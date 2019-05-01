#include "../library/lib.h"
#include "menu.h"

int main()
{
    char i;
    srand(time(NULL));
    while (1) {
        initscr();
        printw("1-play\n2-records\n3-manual\n4-exit\n");
        refresh();
        i = getch();
        switch (i) {
        case 49:
            difficulty();
            break;
        case 50:
            break;
        case 51:
            clear();
            printw("Nim - eto igra\nUpravlenie:\nn - "
                   "stroka\nm - kolvo kamushek\n");
            refresh();
            getch();
            clear();
            break;
        case 52:
            clear();
            endwin();
            return 0;
        }
        clear();
    }
    return 0;
}
