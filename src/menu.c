#include "../library/lib.h"
#include "game.h"

void recordsmenu(){
	clear();
	struct S A;
	int i=1;
    char a;
	FILE *f;
	f=fopen("bin/records.dat","rb");
    fread(&A,sizeof(A),1,f);
	while (!feof(f)){
   		printw("%d Name: %s   Move: %d\n\n",i,A.names,A.lim);
   		fread(&A,sizeof(A),1,f);
   		i++;
    } 
    printw("\n\nC - for clear records");
  	a=getch();
    switch(a){
    case 99: clear(); fclose(f); f=fopen("bin/records.dat","wb"); fclose(f); return;
    default: clear(); fclose(f); return;
}
}

void record(int s){
	struct S A;
	clear();
	char nm[50];
	FILE *f;
	f=fopen("bin/records.dat","ab");
    printw("Enter name\n\n");
	scanw("%s",nm);
	strcpy(A.names,nm);
	A.lim=s;
	fwrite(&A,sizeof(A),1,f);
	fclose(f);
	return;
}

void pole(int** A, int* B, int flag, int jk, int s)
{
    int j;
    clear();
    printw("Hodov: %d\n",s);
    printw("1: ");
    for (j = 0; j < B[0]; j++)
        printw(" %d|", A[0][j]);
    printw("\n2: ");
    for (j = 0; j < B[1]; j++)
        printw(" %d|", A[1][j]);
    printw("\n3: ");
    for (j = 0; j < B[2]; j++)
        printw(" %d|", A[2][j]);
    printw("\n");
    if (jk == 4) {
        printw("4: ");
        for (j = 0; j < B[3]; j++)
            printw(" %d|", A[3][j]);
        printw("\n");
    }
    if (flag)
        printw("Now your turn\n");
    else {
        printw("Now computer turn\n");
        getch();
    }
    return;
}

void difficulty()
{
    int dif;
    clear();
    printw("difficulty\n1-Standart\n2-Mariband\n3-go back");
    while (1) {
        dif = getch();
        switch (dif) {
        case '1':
            standart(3);
            clear();
            return;
        case '2':
            standart(4);
            clear();
            return;
        case '3':
            clear();
            return;
        }
    }
}

int winner(int* B, int w, int jk)
{
    if (w) {
        if (jk == 3) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
                printw("You Won. YHuuuu!!!\n");
                getch();
                return 1;
            }
        }
        if (jk == 4) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
                printw("You Won. YHuuuu!!!\n");
                getch();
                return 1;
            }
        }
    }
    if (w == 0) {
        if (jk == 3) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
                printw("You lose");
                getch();
                return 0;
            }
        }
        if (jk == 4) {
            if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
                printw("You lose");
                getch();
                return 0;
            }
        }
    }
    return 2;
}
