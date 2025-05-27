
#include "cursor.h"

void cursor_init(Cursor *c, int startRow, int startCol) {
    c->row = startRow;
    c->col = startCol;
    c->selectMode = 0;
    c->startRow = -1;
    c->startCol = -1;
    c->endRow = -1;
    c->endCol = -1;
}

void cursor_move(Cursor *c, int inputKey, int maxRows, int maxCols) {
    switch (inputKey) {
        case 2: if (c->row < maxRows - 1) c->row++; break; // bas
        case 8: if (c->row > 0) c->row--; break;           // haut
        case 4: if (c->col > 0) c->col--; break;           // gauche
        case 6: if (c->col < maxCols - 1) c->col++; break; // droite
    }
}

void cursor_start_selection(Cursor *c) {
    c->selectMode = 1;
    c->startRow = c->row;
    c->startCol = c->col;
}

void cursor_end_selection(Cursor *c) {
    c->endRow = c->row;
    c->endCol = c->col;
    c->selectMode = 0; // Fin de sélection
}

int cursor_selection_active(const Cursor *c) {
    return c->selectMode;
}
