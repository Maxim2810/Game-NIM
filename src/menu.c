#include "../library/lib.h"

void difficulty()
{
    int dif;
    clear();
    printw("difficulty\n1-Standart\n2-Mariband\n3-go back");
    while (1) {
        dif = getch();
        switch (dif) {
        case '1':
            clear();
            return;
        case '2':
            clear();
            return;
        case '3':
            clear();
            return;
        }
    }
}
