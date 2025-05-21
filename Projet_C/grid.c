#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

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
