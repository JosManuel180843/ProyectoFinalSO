#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "jugadores.h"
#include "salas.h"

#define MAX_JUGADORES 20

pthread_t jugadores[MAX_JUGADORES];

int main()
{
    srand(time(NULL));

    inicializar_salas();

    for(int i = 0; i < MAX_JUGADORES; i++)
    {
        int* id = malloc(sizeof(int));
        *id = i + 1;

        pthread_create(&jugadores[i],
                       NULL,
                       funcion_jugador,
                       id);

        usleep(rand() % 500000);
    }

    for(int i = 0; i < MAX_JUGADORES; i++)
    {
        pthread_join(jugadores[i], NULL);
    }

    printf("\nSistema finalizado correctamente.\n");

    return 0;
}
