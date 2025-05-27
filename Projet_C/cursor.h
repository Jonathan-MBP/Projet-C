#ifndef CURSOR_H
#define CURSOR_H

typedef struct {
    int row;        // position actuelle ligne
    int col;        // position actuelle colonne

    int selectMode; // 0 = pas de sélection, 1 = sélection commencée
    int startRow;   // position de début de sélection
    int startCol;
    int endRow;     // position de fin (après 2e appui sur espace)
    int endCol;
} Cursor;

void cursor_init(Cursor *c, int startRow, int startCol);
void cursor_move(Cursor *c, int inputKey, int maxRows, int maxCols);
void cursor_start_selection(Cursor *c);
void cursor_end_selection(Cursor *c);
int cursor_selection_active(const Cursor *c);

#endif

