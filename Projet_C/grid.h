#ifndef GRID_H
#define GRID_H

#define GRID_SIZE 15

typedef struct {
    int rows;
    int cols;
    char cells[GRID_SIZE][GRID_SIZE];
} Grid;

void grid_init(Grid *g, int rows, int cols);
void grid_fill_random(Grid *g);
void grid_display(const Grid *g);
int grid_can_place_word(Grid *g, const char *word, int x, int y, int dx, int dy);
void grid_place_word(Grid *g, const char *word, int x, int y, int dx, int dy);
void grid_insert_word_random(Grid *g, const char *word);

#endif

/**
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
*/
