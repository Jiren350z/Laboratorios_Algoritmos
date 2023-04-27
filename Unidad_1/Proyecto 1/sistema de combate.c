#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

// Definición de la estructura para un personaje
struct Personaje {
    char nombre[20];
    int vida;
    int ataque;
};

// Función para crear un personaje con valores aleatorios
struct Personaje crearPersonaje(char *nombre) {
    struct Personaje p;
    srand(time(NULL));
    p.vida = rand() % 101;
    p.ataque = rand() % 21;
    strcpy(p.nombre, nombre);
    return p;
}

// Función para imprimir los datos de un personaje
void imprimirPersonaje(struct Personaje p) {
    printf("Nombre: %s\n", p.nombre);
    printf("Vida: %d\n", p.vida);
    printf("Ataque: %d\n", p.ataque);
}

// Función para la lógica del combate
void combatir(struct Personaje *p1, struct Personaje *p2) 
{
    while (p1->vida > 0 && p2->vida > 0) {
        printf("Es el turno de %s\n", p1->nombre);
        printf("%s ataca a %s por %d puntos de daño\n", p1->nombre, p2->nombre, p1->ataque);
        p2->vida -= p1->ataque;
        if (p2->vida <= 0) 
		{
            printf("%s ha sido derrotado\n", p2->nombre);
            break;
        }
        printf("Es el turno de %s\n", p2->nombre);
        printf("%s ataca a %s por %d puntos de daño\n", p2->nombre, p1->nombre, p2->ataque);
        p1->vida -= p2->ataque;
        if (p1->vida <= 0) {
            printf("%s ha sido derrotado\n", p1->nombre);
            break;
        }
    }
}

int main() {
    // Crear los personajes
    struct Personaje p1 = crearPersonaje("Goku");
    struct Personaje p2 = crearPersonaje("Vegeta");

    // Imprimir los datos de los personajes
    printf("Datos de %s:\n", p1.nombre);
    imprimirPersonaje(p1);
    printf("\nDatos de %s:\n", p2.nombre);
    imprimirPersonaje(p2);

    // Combatir
    printf("\nEmpieza el combate!\n");
    combatir(&p1, &p2);

    return 0;
}

