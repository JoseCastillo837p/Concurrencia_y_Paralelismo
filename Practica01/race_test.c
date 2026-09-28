#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global_counter = 20;

// 1. Declaramos e inicializamos el mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_routine(void *arg) {
    for (size_t i = 0; i < 100000; i++) {
        // 2. Ponemos el candado antes de tocar la variable (inicio sección crítica)
        pthread_mutex_lock(&mutex);
        
        global_counter++;
        
        // 3. Quitamos el candado (fin sección crítica)
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *thread_routine_two(void *arg) {
    for (size_t i = 0; i < 100000; i++) {
        // 2. Ponemos el candado aquí también
        pthread_mutex_lock(&mutex);
        
        global_counter--;
        
        // 3. Quitamos el candado
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Crear hilos
    pthread_create(&thread1, NULL, thread_routine, NULL);
    pthread_create(&thread2, NULL, thread_routine_two, NULL);

    // Esperar a que terminen
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Valor final de global_counter: %d\n", global_counter);

    return 0;
}