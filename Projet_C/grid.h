#ifndef GRID_H
#define GRID_H

#define GRID_SIZE 12

typedef struct {
    int rows;
    int cols;
    char cells[GRID_SIZE][GRID_SIZE];
} Grid;
//Appel de toute les fonctions
void grid_init(Grid *g, int rows, int cols);
void grid_fill_random(Grid *g);
void grid_display(const Grid *g);
int grid_can_place_word(Grid *g, const char *word, int x, int y, int dx, int dy);
void grid_place_word(Grid *g, const char *word, int x, int y, int dx, int dy);
void grid_insert_word_random(Grid *g, const char *word);

#endif

