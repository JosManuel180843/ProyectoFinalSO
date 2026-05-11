#include <pthread.h>

#include "sincronizacion.h"

pthread_mutex_t mutex;

void inicializar_sincronizacion()
{
    pthread_mutex_init(&mutex, NULL);
}

void bloquear_mutex()
{
    pthread_mutex_lock(&mutex);
}

void desbloquear_mutex()
{
    pthread_mutex_unlock(&mutex);
}
