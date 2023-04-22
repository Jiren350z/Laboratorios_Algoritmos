#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
typedef struct jugador {
    char nombre[50];
    // otros atributos relevantes
    struct jugador *siguiente;
} jugador;

jugador *inicializar_lista() {
    jugador *primer_jugador = (jugador*) malloc(sizeof(jugador));
    strcpy(primer_jugador->nombre, "Jugador 1");
    // inicializar otros atributos relevantes
    primer_jugador->siguiente = NULL;
    return primer_jugador;
}
void añadir_jugador(jugador *ultimo_jugador) {
    jugador *nuevo_jugador = (jugador*) malloc(sizeof(jugador));
    strcpy(nuevo_jugador->nombre, "Nuevo jugador");
    // inicializar otros atributos relevantes
    nuevo_jugador->siguiente = NULL;
    ultimo_jugador->siguiente = nuevo_jugador;
}
jugador *llamar_jugador_al_azar_sin_repetir(jugador *primer_jugador) {
    int total_jugadores = 0;
    jugador *jugador_actual = primer_jugador;
    while (jugador_actual != NULL) {
        total_jugadores++;
        jugador_actual = jugador_actual->siguiente;
    }
    int llamado = 0;
    jugador_actual = primer_jugador;
    while (!llamado) {
        int numero_aleatorio = rand() % total_jugadores + 1;
        jugador_actual = primer_jugador;
        for (int i = 1; i < numero_aleatorio; i++) {
            jugador_actual = jugador_actual->siguiente;
        }
        if (!jugador_actual->llamado) {
            jugador_actual->llamado = 1;
            llamado = 1;
        }
    }
    return jugador_actual;
}
int main() {
    srand(time(NULL)); // inicializar el generador de números aleatorios
    jugador *primer_jugador = inicializar_lista();
    añadir_jugador(primer_jugador);
    añadir_jugador(primer_jugador->siguiente);
    jugador *jugador=llamar_jugador_al_azar_sin_repetir(primer_jugador);
    return 0;
}
