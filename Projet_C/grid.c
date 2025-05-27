#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "grid.h"

// Initialise une grille en définissant ses dimensions et remplit toutes les cases avec '-' (cases vides).
void grid_init(Grid *g, int rows, int cols) {
    g->rows = rows;
    g->cols = cols;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            g->cells[i][j] = '-'; // marque vide
}

//Remplit les cases encore vides ('-') avec des lettres aléatoires de A à Z. Ça donne l'aspect "brouillé" typique des mots mêlés.
void grid_fill_random(Grid *g) {
    for (int i = 0; i < g->rows; i++)
        for (int j = 0; j < g->cols; j++)
            if (g->cells[i][j] == '-')
                g->cells[i][j] = 'A' + rand() % 26;
}

//Affiche la grille avec un effet damier coloré (jaune/bleu alternés) grâce aux codes ANSI. Pratique pour la lisibilité ! Elle affiche aussi la liste des mots à chercher.
void grid_display(const Grid *g) {

    printf("\nListe des mots a trouver : CHAT, CHIEN, OISEAU, POISSON, MADAME, JONATHAN, AMOUR, ACTION, VERITE, MARIAGE, DIVORCE, PARIS");
    printf("\nGrille (%d x %d) :\n\n", g->rows, g->cols);
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            int color = (i + j) % 2 == 0 ? 43 : 44; // Jaune/bleu
            printf("\033[%dm %c \033[0m", color, g->cells[i][j]);
        }
        printf("\n");
    }
}

// Vérifie si on peut placer un mot à une position et direction données. Elle contrôle les limites de la grille et s'assure qu'il n'y a pas de conflit (sauf si c'est la même lettre).
int grid_can_place_word(Grid *g, const char *word, int x, int y, int dx, int dy) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        if (nx < 0 || ny < 0 || nx >= g->rows || ny >= g->cols)
            return 0;
        if (g->cells[nx][ny] != '-' && g->cells[nx][ny] != word[i])
            return 0;
    }
    return 1;
}

//Place effectivement le mot dans la grille en suivant la direction spécifiée.
void grid_place_word(Grid *g, const char *word, int x, int y, int dx, int dy) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        g->cells[nx][ny] = word[i];
    }
}

//Tente de placer un mot aléatoirement. Elle teste toutes les directions possibles (horizontal, vertical, diagonales) jusqu'à trouver une position valide.
void grid_insert_word_random(Grid *g, const char *word) {
    int directions[8][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},    // H/V
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}   // Diagonales
    };

    int placed = 0;
    while (!placed) {
        int x = rand() % g->rows;
        int y = rand() % g->cols;
        int dir = rand() % 8;
        int dx = directions[dir][0];
        int dy = directions[dir][1];

        if (grid_can_place_word(g, word, x, y, dx, dy)) {
            grid_place_word(g, word, x, y, dx, dy);
            placed = 1;
        }
    }
}
