#include <stdio.h>
#include <string.h>
#include "wordlist.h"

int chargerMotsDepuisFichier(const char *Mots, char mots[][MAX_WORD_LEN]) {
    FILE *f = fopen(Mots, "r");
    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir %s\n", Mots);
        return 0;
    }

    int count = 0;
    while (fgets(mots[count], MAX_WORD_LEN, f) != NULL && count < MAX_WORDS) {
        // Enlever le saut de ligne
        mots[count][strcspn(mots[count], "\n")] = '\0';
        count++;
    }

    fclose(f);
    return count; // retourne le nombre de mots lus
}
