#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_JUGADORES 10

struct jugador {
    char nombre[20];
    int edad;
};

int main() {
    struct jugador jugadores[NUM_JUGADORES] = {{"Juan", 20}, {"Pedro", 21}, {"Maria", 22}, {"Ana", 23}, {"Luis", 24}, {"Miguel", 25}, {"Sofia", 26}, {"Elena", 27}, {"Carlos", 28}, {"Pablo", 29}};
    int seleccionados[NUM_JUGADORES] = {0};
    int num_seleccionados = 0;

    srand(time(NULL));

    while (num_seleccionados < 5) {
        int i = rand() % NUM_JUGADORES;

        if (seleccionados[i] == 0) {
            printf("Seleccionado: %s\n", jugadores[i].nombre);
            seleccionados[i] = 1;
            num_seleccionados++;
        }
    }

    return 0;
}
