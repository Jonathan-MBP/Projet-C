#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"

int main() {
    srand(time(NULL));

    Grid g;
    grid_init(&g, GRID_SIZE, GRID_SIZE);

    const char *mots[] = {"CHAT", "CHIEN", "OISEAU", "POISSON"};
    int nbMots = sizeof(mots) / sizeof(mots[0]);

    for (int i = 0; i < nbMots; i++) {
        grid_insert_word_random(&g, mots[i]);
    }

    grid_fill_random(&g);
    grid_display(&g);

    return 0;
}

