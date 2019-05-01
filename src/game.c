#include "game.h"
#include "../library/lib.h"
#include "menu.h"

void BubbleSort(int* A, int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                k = A[j];
                A[j] = A[j - 1];
                A[j - 1] = k;
            }
        }
    }
    return;
}

void ComputerTurn(int** A, int* B, int jk)
{
    pole(A, B, 0, jk);
    int max1, i, min, med, med2, raz = 0, C[jk];
    if (jk == 4) {
        for (i = 0; i < jk; i++)
            C[i] = B[i];
        BubbleSort(C, jk);
        min = C[0];
        med = C[1];
        med2 = C[2];
        max1 = C[3];
        raz = max1 + med - min - med2;
        if (raz == 0)
            raz = max1;
        if (B[0] == max1) {
            B[0] -= raz;
            return;
        }
        if (B[1] == max1) {
            B[1] -= raz;
            return;
        }
        if (B[2] == max1) {
            B[2] -= raz;
            return;
        }
        if (B[3] == max1) {
            B[3] -= raz;
            return;
        }
        return;
    }

    return;
}

void games(int** A, int* B, int jk)
{
    clear();
    while (1) {
        ComputerTurn(A, B, jk);
        clear();
    }
    return;
}

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
    games(A, B, jk);
    for (i = 0; i < jk; i++)
        free(A[i]);
    free(A);
    free(B);
    return;
}
