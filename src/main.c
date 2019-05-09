#include "../library/lib.h"
#include "menu.h"

int main()
{
    FILE* f;
    char i;
    srand(time(NULL));
    f = fopen("bin/records.dat", "ab");
    fclose(f);
    while (1) {
        initscr();
        printw("1-play\n2-records\n3-manual\n4-exit\n");
        i = getch();
        switch (i) {
        case 49:
            difficulty();
            break;
        case 50:
            recordsmenu();
            break;
        case 51:
            manual();
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
