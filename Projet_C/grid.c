#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "grid.h"

void grid_init(Grid *g, int rows, int cols) {
    g->rows = rows;
    g->cols = cols;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            g->cells[i][j] = '-'; // marque vide
}

void grid_fill_random(Grid *g) {
    for (int i = 0; i < g->rows; i++)
        for (int j = 0; j < g->cols; j++)
            if (g->cells[i][j] == '-')
                g->cells[i][j] = 'A' + rand() % 26;
}

void grid_display(const Grid *g) {
    printf("\nGrille (%d x %d) :\n\n", g->rows, g->cols);
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            int color = (i + j) % 2 == 0 ? 43 : 44; // Jaune/bleu
            printf("\033[%dm %c \033[0m", color, g->cells[i][j]);
        }
        printf("\n");
    }
}

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

void grid_place_word(Grid *g, const char *word, int x, int y, int dx, int dy) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        g->cells[nx][ny] = word[i];
    }
}

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

/**
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRID_SIZE 10 // Taille de la grille


void grid_init(Grid *g, int rows, int cols) {
    g->rows = rows;
    g->cols = cols;

    // Remplir avec des tirets au départ (ou des espaces)
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            g->cells[i][j] = '-';
}

void grid_fill_random(Grid *g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->cells[i][j] == '-') {
                g->cells[i][j] = 'A' + rand() % 26;
            }
        }
    }
}


void grid_display(const Grid *g) {
    printf("\nGrille (%d x %d) :\n\n", g->rows, g->cols);
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            // Damier avec couleurs ANSI (alternance bleu / blanc)
            int color = (i + j) % 2 == 0 ? 34 : 37; // 34 = bleu, 37 = blanc
            if((i + j) % 2 == 0){
                printf("\033[43;37m%d %c \033[0m", color, g->cells[i][j]);
            }else{
                printf("\033[44;37m%d %c \033[0m", color, g->cells[i][j]);
            }
        }
        printf("\n");
    }
}

void afficherGrille(char grille[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grille[i][j]);
        }
        printf("\n");
    }
}

int peutPlacerMot(char grille[GRID_SIZE][GRID_SIZE], const char *mot, int x, int y, int dx, int dy) {
    int longueur = strlen(mot);
    for (int i = 0; i < longueur; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if (nx < 0 || nx >= GRID_SIZE || ny < 0 || ny >= GRID_SIZE) {
            return 0; // Hors des limites
        }
        if (grille[nx][ny] != '.' && grille[nx][ny] != mot[i]) {
            return 0; // Conflit avec un autre mot
        }
    }
    return 1;
}

void placerMot(char grille[GRID_SIZE][GRID_SIZE], const char *mot, int x, int y, int dx, int dy) {
    int longueur = strlen(mot);
    for (int i = 0; i < longueur; i++) {
        grille[x + i * dx][y + i * dy] = mot[i];
    }
}

void insererMotAleatoire(char grille[GRID_SIZE][GRID_SIZE], const char *mot) {
    int directions[8][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, // Horizontal et vertical
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1} // Diagonales
    };

    int place = 0;
    while (!place) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;
        int dir = rand() % 8;

        if (peutPlacerMot(grille, mot, x, y, directions[dir][0], directions[dir][1])) {
            placerMot(grille, mot, x, y, directions[dir][0], directions[dir][1]);
            place = 1;
        }
    }
}*/


