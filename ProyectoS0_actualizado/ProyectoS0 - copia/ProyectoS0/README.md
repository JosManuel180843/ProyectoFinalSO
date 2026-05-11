# Proyecto 1 - Sistemas Operativos
## Sistema Concurrente de Matchmaking

Este proyecto implementa un sistema concurrente de matchmaking para videojuegos online utilizando programación multihilo en C con pthreads sobre Linux Ubuntu. Cada jugador es representado mediante un hilo que intenta ingresar a salas compartidas para iniciar partidas automáticamente.

El proyecto también incluye un experimento de Race Condition para demostrar los problemas de concurrencia cuando no existe sincronización.

---

# Dependencias

El proyecto requiere las siguientes dependencias:

- GCC
- pthreads
- Linux Ubuntu

## Instalación de dependencias

```bash
sudo apt install build-essential
```

## Verificar instalación de GCC

```bash
gcc --version
```

---

# Estructura del Proyecto

```bash
ProyectoS0/
├── logs
├── results
├── screenshots
├── scripts
│   ├── compilar_race.sh
│   ├── compilar.sh
│   ├── ejecutar_race.sh
│   └── ejecutar.sh
├── src
│   ├── jugadores.c
│   ├── jugadores.h
│   ├── main.c
│   ├── matchmaking
│   ├── race_condition.c
│   ├── salas.c
│   ├── salas.h
│   ├── sincronizacion.c
│   └── sincronizacion.h
├── tables
└── README.md
```

---

# Instrucciones de Compilación

## Compilar proyecto principal

Entrar a la carpeta scripts:

```bash
cd scripts
```

Ejecutar:

```bash
./compilar.sh
```

## Resultado esperado

```bash
Compilacion completada correctamente
```

---

# Instrucciones de Ejecución

## Ejecutar proyecto principal

```bash
./ejecutar.sh
```

---

# Resultados Esperados

El sistema debe:

- Crear múltiples hilos concurrentes.
- Simular jugadores intentando ingresar a salas.
- Sincronizar acceso a recursos compartidos mediante mutex.
- Iniciar partidas automáticamente cuando una sala alcance su capacidad máxima.
- Crear nuevas salas dinámicamente.
- Ejecutar múltiples partidas concurrentes.

## Ejemplo de salida esperada

```bash
Nueva Sala 1 creada.
Jugador 1 intentando entrar...
Jugador 2 intentando entrar...
Jugador 3 intentando entrar...

Jugador 3 agregado a Sala 1 (1/4)
Jugador 1 agregado a Sala 1 (2/4)
Jugador 2 agregado a Sala 1 (3/4)

Jugador 5 agregado a Sala 1 (4/4)

==============================
Sala 1 llena.
Partida iniciando...
==============================

Jugador 5 iniciando partida en Sala 1
Jugador 1 iniciando partida en Sala 1
Jugador 3 iniciando partida en Sala 1
Jugador 2 iniciando partida en Sala 1
```

---

# Experimento Race Condition

El proyecto incluye un experimento adicional que demuestra el comportamiento incorrecto de múltiples hilos accediendo a recursos compartidos sin sincronización.

---

# Compilación del Experimento

```bash
./compilar_race.sh
```

## Resultado esperado

```bash
Experimento compilado correctamente
```

---

# Ejecución del Experimento

```bash
./ejecutar_race.sh
```

---

# Resultados Esperados del Experimento

Se observarán inconsistencias en el orden de los números debido a la ausencia de exclusión mutua.

## Ejemplo

```bash
Jugador entrando. Total: 1
Jugador entrando. Total: 3
Jugador entrando. Total: 4
Jugador entrando. Total: 2
Jugador entrando. Total: 5
Jugador entrando. Total: 19
Jugador entrando. Total: 14
```

Esto demuestra una condición de carrera (Race Condition), causada por el acceso concurrente no protegido a una variable compartida.

---

# Tecnologías Utilizadas

- Lenguaje C
- pthreads
- Mutex
- Programación Concurrente
- Linux Ubuntu

---

# Autor

Por: Jose Manuel Daniel Morales
