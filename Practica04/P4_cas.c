// Programa: P4_cas.c (Cálculo de Pi con algoritmo CAS - Compare-and-Swap)
// Descripción: Implementación de Monte Carlo con exclusión mutua usando CAS.
// Autor: José Manuel Castillo Dzib
// Fecha: 2026/09/28

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

// La instrucción exige 100,000,000 de puntos
#define TOTAL_PUNTOS 100000000 

int puntosDentro = 0;        // Variable compartida
int puntos_por_hilo;         // Carga de trabajo dividida

// Variable candado para el algoritmo CAS (0 = Libre, 1 = Ocupado)
int lock = 0; 

// Función para entrar a la sección crítica usando Compare-and-Swap
void lock_cas(int *candado) {
    // __sync_bool_compare_and_swap verifica de forma atómica:
    // Si *candado == 0, lo cambia a 1 y retorna true (sale del while).
    // Si no, retorna false y se queda atrapado en el while (espera activa).
    while (!__sync_bool_compare_and_swap(candado, 0, 1)) {
        // Spinlock: el hilo gira aquí esperando su turno
    }
}

// Función para salir de la sección crítica
void unlock_cas(int *candado) {
    *candado = 0; // Libera el candado
}

// Función que ejecutará cada hilo
void* calcular_pi(void* arg) {
    unsigned int seed = (unsigned int)(uintptr_t)arg ^ time(NULL);

    for (int i = 0; i < puntos_por_hilo; i++) {
        // Generar puntos aleatorios entre -1 y 1
        double x = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;

        // Determinar si está dentro del círculo
        if (x * x + y * y <= 1.0) {
            // Protección de la variable compartida ÚNICAMENTE con CAS
            lock_cas(&lock);
            puntosDentro++;
            unlock_cas(&lock);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero_de_hilos>\n", argv[0]);
        return -1;
    }

    int numHilos = atoi(argv[1]);
    puntos_por_hilo = TOTAL_PUNTOS / numHilos;
    
    pthread_t hilos[numHilos];
    
    struct timeval start, end;
    gettimeofday(&start, NULL); // Iniciar cronómetro

    // Crear hilos
    for (long i = 0; i < numHilos; i++) {
        pthread_create(&hilos[i], NULL, calcular_pi, (void*)i);
    }

    // Esperar hilos
    for (int i = 0; i < numHilos; i++) {
        pthread_join(hilos[i], NULL);
    }

    gettimeofday(&end, NULL); // Detener cronómetro
    
    double tiempo = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double pi = 4.0 * (double)puntosDentro / (double)TOTAL_PUNTOS;

    printf("Hilos: %2d | Puntos: %d | Pi: %f | Tiempo: %f seg\n", 
            numHilos, puntosDentro, pi, tiempo);

    return 0;
}