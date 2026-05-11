#!/bin/bash

cd ../src

gcc main.c jugadores.c salas.c sincronizacion.c -o matchmaking -lpthread

echo "Compilacion completada correctamente"
