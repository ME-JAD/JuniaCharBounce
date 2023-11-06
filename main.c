#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 200
#define EMPTY ' '       // le terrain vide est représenté par un espace
#define EDGE '|'        // le bord du terrain est représenté par un |
#define BALL_RIGHT '\\' // la balle allant vers la droite est représentée par un \ (qui doit être doublé pour être correctement affiché
#define BALL_LEFT '/'   // la balle allant vers la gauche est représentée par un /

// Fonction d'initialisation du tableau représentant le terrain avec la balle
void initializeField(char field[WIDTH + 1]) {
    srand(time(NULL));
    for (int i = 2; i < WIDTH; i++) {
        int roll = rand() % 4;
        if (roll == 0) {
            field[i] = BALL_RIGHT;
        } else if (roll == 1) {
            field[i] = BALL_LEFT;
        } else {
            field[i] = EMPTY;
        }
    }
    field[0] = EDGE;
    field[WIDTH] = EDGE;

}

// Fonction d'affichage du terrain
void displayField(char field[WIDTH + 1]) {
    for (int i = 0; i < WIDTH + 1; i++) {
        printf("%c", field[i]);
    }
    printf("\n");
}

// Votre fonction !!! Elle devra permettre le déplacement de la balle
void moveBall(char field[WIDTH + 1]) {
    // rebond gauche
    if (field[1] == BALL_LEFT) {
        field[1] = BALL_RIGHT;
        displayField(field);
    }

    // déplacement sur la gauche
    for (int i = 1; i < WIDTH; i++) {
        if ((field[i] == BALL_LEFT) && (i != 1)) {
            field[i] = EMPTY;
            field[i - 1] = BALL_LEFT;
        }
    }

    // rebond droite
    if (field[WIDTH - 1] == BALL_RIGHT) {
        field[WIDTH - 1] = BALL_LEFT;
    }

    // déplacement sur la droite
    for (int i = 1; i < WIDTH - 1; i++) {
        if (field[i] == BALL_RIGHT) {
            field[i] = EMPTY;
            field[i + 1] = BALL_RIGHT;
            i++;
        }
    }
}

int main() {
    char field[
            WIDTH + 1];  // Le terrain prend un caractère de plus pour laisser la place au caractère spécial permettant
    // un affichage plus rapide. Considérez que votre tableau fait WIDTH de largeur

    initializeField(field); // On initialise le terrain

    for (;;) { // Une boucle infinie
        displayField(field);    // On affiche le terrain
        moveBall(field);        // On bouge la balle
    }
    return 0;
}
