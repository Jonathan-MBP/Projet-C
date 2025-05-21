#include <stdlib.h>
#include <time.h>
#include "grid.h"

int main() {
    srand(time(NULL)); // Initialisation pour random

    Grid g;
    grid_init(&g, 10, 10);     // 10x10 par exemple
    grid_fill_random(&g);      // Remplir avec lettres aléatoires
    grid_display(&g);          // Afficher avec damier

    return 0;
}
