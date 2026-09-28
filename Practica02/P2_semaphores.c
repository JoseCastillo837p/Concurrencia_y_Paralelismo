// Programa: P2_semaphores.c (Problema Cocinero y Meseros)
// Descripción: Implementación de sincronización de hilos usando semáforos.
// Autor: José Manuel Castillo Dzib
// Fecha: 2026/09/28

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define NR_LOOP 10 // Número total de platillos a preparar

// Declaración de funciones para los hilos
static void *cocinar(void* arg);
static void *servir(void* arg);

static int counter = 0; // Variable global: platillos en la barra listos para servir
sem_t sem1; // Semáforo para notificar la disponibilidad de platillos

int main(void) {
    pthread_t cocinero, mesero_1, mesero_2;

    // Inicializamos el semáforo en 0 (0 platillos listos al arrancar)
    sem_init(&sem1, 0, 0);

    // Creamos el hilo del productor (Cocinero)
    pthread_create(&cocinero, NULL, cocinar, NULL);
    
    // Creamos los hilos de los consumidores (Meseros) y les pasamos su nombre
    pthread_create(&mesero_1, NULL, servir, "MESERO 1");
    pthread_create(&mesero_2, NULL, servir, "MESERO 2");

    // Esperamos a que los hilos terminen su jornada
    pthread_join(cocinero, NULL);
    pthread_join(mesero_1, NULL);
    pthread_join(mesero_2, NULL);

    // Destruimos el semáforo para liberar memoria
    sem_destroy(&sem1);

    printf("Jornada terminada. Platillos sobrantes: %d\n", counter);
    return 0;
}

static void *cocinar(void* arg) {
    for (int i = 0; i < NR_LOOP; i++) {
        counter++; // El cocinero prepara un platillo nuevo
        printf("COCINERO: Comida preparada. Platillos en espera: %d \n", counter);
        
        // Ejecutamos sem_post para sumarle 1 al semáforo (avisa que hay comida)
        sem_post(&sem1);
        
        // Simula el tiempo de preparación (0.5 segundos)
        usleep(500000); 
    }
    return NULL;
}

static void *servir(void* arg) {
    char *nombre = (char *)arg; // Recibimos el nombre del mesero asignado
    
    // Cada mesero servirá exactamente la mitad de los platillos totales
    for (int i = 0; i < NR_LOOP / 2; i++) {
        // Ejecutamos sem_wait. Si el semáforo es 0, el mesero se bloquea hasta que el cocinero haga un sem_post
        sem_wait(&sem1);
        
        counter--; // El mesero toma el platillo de la barra
        printf("%s: Comida servida. Platillos en espera: %d \n", nombre, counter);
        
        // Simula el tiempo que tarda el mesero en llevarlo a la mesa (2 segundos)
        sleep(2); 
    }
    return NULL;
}