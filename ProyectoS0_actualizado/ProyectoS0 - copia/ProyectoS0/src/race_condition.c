#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JUGADORES 20

int contador = 0;

void* jugador(void* arg)
{
    contador++;

    printf("Jugador entrando. Total: %d\n", contador);

    pthread_exit(NULL);
}

int main()
{
    pthread_t hilos[MAX_JUGADORES];

    for(int i = 0; i < MAX_JUGADORES; i++)
    {
        pthread_create(&hilos[i], NULL, jugador, NULL);
    }

    for(int i = 0; i < MAX_JUGADORES; i++)
    {
        pthread_join(hilos[i], NULL);
    }

    return 0;
}
