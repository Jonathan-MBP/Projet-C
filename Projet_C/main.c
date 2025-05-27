#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grid.h"
#include "wordlist.h"
#include "cursor.h"



int main()
{
    srand(time(NULL));

    Grid g;
    grid_init(&g, GRID_SIZE, GRID_SIZE);

    char mots[MAX_WORDS][MAX_WORD_LEN];
    int nbMots = chargerMotsDepuisFichier("Mots.TXT", mots);

    for (int i = 0; i < nbMots; i++)
    {
        grid_insert_word_random(&g, mots[i]);
    }

    grid_fill_random(&g);
    grid_display(&g);

    Cursor curseur;
    cursor_init(&curseur, 0, 0);

// exemple si la touche pressée est 6 → droite
    cursor_move(&curseur, 6, GRID_SIZE, GRID_SIZE);

// si l’utilisateur appuie sur ESPACE
    if (!cursor_selection_active(&curseur))
    {
        cursor_start_selection(&curseur);
    }
    else
    {
        cursor_end_selection(&curseur);
        // ici on peut extraire le mot entre (startRow, startCol) et (endRow, endCol)
    }


    return 0;
}

