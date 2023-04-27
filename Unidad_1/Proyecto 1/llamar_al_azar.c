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

void anadir_jugador(jugador *ultimo_jugador) {
    jugador *nuevo_jugador = (jugador*) malloc(sizeof(jugador));
    strcpy(nuevo_jugador->nombre, "Nuevo jugador");
    // inicializar otros atributos relevantes
    nuevo_jugador->siguiente = NULL;
    ultimo_jugador->siguiente = nuevo_jugador;
}

jugador *llamar_jugador_al_azar(jugador *primer_jugador) {
    int total_jugadores = 0;
    int i=0;
    jugador *jugador_actual = primer_jugador;
    while (jugador_actual != NULL) {
        total_jugadores++;
        jugador_actual = jugador_actual->siguiente;
    }
    int numero_aleatorio = rand() % total_jugadores + 1;
    jugador_actual = primer_jugador;
    for ( i = 1; i < numero_aleatorio; i++) {
        jugador_actual = jugador_actual->siguiente;
    }
    return jugador_actual;
}

int main() {
    srand(time(NULL)); // inicializar el generador de números aleatorios
    jugador *primer_jugador = inicializar_lista();
    anadir_jugador(primer_jugador);
    anadir_jugador(primer_jugador->siguiente);
    jugador *jugador_al_azar = llamar_jugador_al_azar(primer_jugador);
    printf("El jugador llamado al azar es: %s\n", jugador_al_azar->nombre);
    return 0;
}

