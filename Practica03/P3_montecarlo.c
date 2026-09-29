// Programa: P3_montecarlo.c (Cálculo de Pi con hilos y semáforos)
// Descripción: Implementación del método de Monte Carlo para aproximar Pi.
// Autor: José Manuel Castillo Dzib
// Fecha: 2026/09/28

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

#define TOTAL_PUNTOS 1000000 // Mantener totalPuntos en 1,000,000 según las instrucciones

int puntosDentro = 0;        // Variable compartida
sem_t sem_puntos;            // Semáforo para proteger puntosDentro
int puntos_por_hilo;         // Carga de trabajo dividida

// Función que ejecutará cada hilo
void* calcular_pi(void* arg) {
    // Generar una semilla única por hilo para rand_r usando su ID
    unsigned int seed = (unsigned int)(uintptr_t)arg ^ time(NULL);

    // Cada hilo ejecuta su porción del total de puntos
    for (int i = 0; i < puntos_por_hilo; i++) {
        // Generar puntos (x, y) aleatorios entre -1 y 1
        double x = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;
        double y = ((double)rand_r(&seed) / RAND_MAX) * 2.0 - 1.0;

        // Determinar si el punto está dentro del círculo
        if (x * x + y * y <= 1.0) {
            // Sección crítica protegida por el semáforo
            sem_wait(&sem_puntos);
            puntosDentro++;
            sem_post(&sem_puntos);
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    // Verificar que el usuario mande la cantidad de hilos por consola
    if (argc != 2) {
        printf("Uso: %s <numero_de_hilos>\n", argv[0]);
        return -1;
    }

    int numHilos = atoi(argv[1]);
    puntos_por_hilo = TOTAL_PUNTOS / numHilos; // Repartir carga de trabajo
    
    pthread_t hilos[numHilos];
    
    // Inicializar semáforo en 1 (funcionando como Mutex para acceso exclusivo)
    sem_init(&sem_puntos, 0, 1);

    // Variables para medir el tiempo
    struct timeval start, end;
    gettimeofday(&start, NULL); // Iniciar cronómetro

    // Crear los hilos
    for (long i = 0; i < numHilos; i++) {
        pthread_create(&hilos[i], NULL, calcular_pi, (void*)i);
    }

    // Esperar a que todos los hilos terminen antes de calcular Pi
    for (int i = 0; i < numHilos; i++) {
        pthread_join(hilos[i], NULL);
    }

    gettimeofday(&end, NULL); // Detener cronómetro
    
    // Calcular el tiempo total de ejecución
    double tiempo = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calcular Pi: PI = 4 * (puntosDentro / totalPuntos)
    double pi = 4.0 * (double)puntosDentro / (double)TOTAL_PUNTOS;

    // Imprimir resultados
    printf("Hilos: %2d | Puntos dentro: %d | Pi estimado: %f | Tiempo: %f seg\n", 
            numHilos, puntosDentro, pi, tiempo);

    sem_destroy(&sem_puntos);
    return 0;
}