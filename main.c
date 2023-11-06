#include <stdio.h>
#include <stdio.h>

#define WIDTH 80
#define EMPTY ' '       // le terrain vide est représenté par un espace
#define EDGE '|'        // le bord du terrain est représenté par un |
#define BALL_RIGHT '\\' // la balle allant vers la droite est représentée par un \ (qui doit être doublé pour être correctement affiché
#define BALL_LEFT '/'   // la balle allant vers la gauche est représentée par un /

// Fonction d'initialisation du tableau représentant le terrain avec la balle
void initializeField(char field[WIDTH + 1]) {

}

// Fonction d'affichage du terrain
void displayField(char field[WIDTH + 1]) {

}

// Votre fonction !!! Elle devra permettre le déplacement de la balle
void moveBall(char field[WIDTH + 1]) {

}

int main() {
    char field[WIDTH + 1];  // Le terrain prend un caractère de plus pour laisser la place au caractère spécial permettant
                            // un affichage plus rapide. Considérez que votre tableau fait WIDTH de largeur

    initializeField(field); // On initialise le terrain

    for (;;) { // Une boucle infinie
        displayField(field);    // On affiche le terrain
        moveBall(field);        // On bouge la balle
    }
    return 0;
}
