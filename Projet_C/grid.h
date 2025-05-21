
#ifndef GRID_H
#define GRID_H

#define MAX_ROWS 20
#define MAX_COLS 20

typedef struct {
    int rows;
    int cols;
    char cells[MAX_ROWS][MAX_COLS];
} Grid;

// Fonctions principales
void grid_init(Grid *g, int rows, int cols);
void grid_fill_random(Grid *g);
void grid_display(const Grid *g);

#endif
