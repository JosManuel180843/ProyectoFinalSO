#!/bin/bash

cd ../src

gcc race_condition.c -o race_condition -lpthread

echo "Experimento compilado correctamente"
