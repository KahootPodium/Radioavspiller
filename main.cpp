#include <ncurses.h>
#include <cstdlib>
#include <string>

void playRadio(std::string url) {
    system(("ffplay -nodisp -hide_banner " + url).c_str());
}

int main() {
    int choice = 0;

    initscr();
    keypad(stdscr, TRUE);

    while (true) {
        clear();

        printw("=== Velg en radiostasjon === ");

        mvprintw(2, 0, choice == 0 ? "> NRK P1" : "  NRK P1");
        mvprintw(3, 0, choice == 1 ? "> NRK P2" : "  NRK P2");
        mvprintw(4, 0, choice == 2 ? "> NRK P3" : "  NRK P3");

        refresh();

        int key = getch();

        if (key == KEY_UP) choice--;
        if (key == KEY_DOWN) choice++;

        if (choice < 0) choice = 0;
        if (choice > 2) choice = 2;

        if (key == 10) break;
    }

    endwin();

    switch (choice) {
        case 0:
            playRadio("http://lyd.nrk.no/nrk_radio_p1_stor-oslo_mp3_h");
            break;

        case 1:
            playRadio("http://lyd.nrk.no/nrk_radio_p2_mp3_h");
            break;

        case 2:
            playRadio("http://lyd.nrk.no/nrk_radio_p3_mp3_h");
            break;
    }
}