#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#include "jugadores.h"
#include "salas.h"

void* funcion_jugador(void* arg)
{
    int id = *((int*)arg);

    printf("Jugador %d intentando entrar...\n", id);

    // Simula tiempo aleatorio de conexion
    usleep(rand() % 1000000);

    ingresar_a_sala(id);

    free(arg);

    pthread_exit(NULL);
}
