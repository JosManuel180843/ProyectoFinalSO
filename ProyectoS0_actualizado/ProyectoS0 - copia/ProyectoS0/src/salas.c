#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "salas.h"
#include "sincronizacion.h"

#define CAPACIDAD_SALA 4

int jugadores_sala = 0;
int numero_sala = 1;

int jugadores_partida[4];

void inicializar_salas()
{
    inicializar_sincronizacion();

    printf("Nueva Sala %d creada.\n", numero_sala);
}

void ingresar_a_sala(int jugador_id)
{
    bloquear_mutex();

    jugadores_partida[jugadores_sala] = jugador_id;

    jugadores_sala++;

    printf("Jugador %d agregado a Sala %d (%d/%d)\n",
           jugador_id,
           numero_sala,
           jugadores_sala,
           CAPACIDAD_SALA);

    if(jugadores_sala == CAPACIDAD_SALA)
    {
        printf("\n==============================\n");
        printf("Sala %d llena.\n", numero_sala);
        printf("Partida iniciando...\n");
        printf("==============================\n\n");

        for(int i = 0; i < CAPACIDAD_SALA; i++)
        {
            printf("Jugador %d iniciando partida en Sala %d\n",
                   jugadores_partida[i],
                   numero_sala);

            usleep(200000);
        }

        printf("\n");

        jugadores_sala = 0;
        numero_sala++;

        printf("Nueva Sala %d creada.\n", numero_sala);
    }

    desbloquear_mutex();
}
