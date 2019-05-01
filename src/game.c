#include "game.h"
#include "../library/lib.h"
#include "menu.h"

void standart(int jk)
{
    int i, j, **A, *B;
    A = (int**)malloc(jk * sizeof(int*));
    for (i = 0; i < jk; i++) {
        A[i] = (int*)malloc(10 * sizeof(int));
        for (j = 0; j < 10; j++)
            A[i][j] = j + 1;
    }
    B = (int*)malloc(jk * sizeof(int));
    B[0] = 1;
    B[1] = 3;
    B[2] = 5;
    B[3] = 7;
    for (i = 0; i < jk; i++)
        free(A[i]);
    free(A);
    free(B);
    return;
}
