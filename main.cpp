#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <vector>

void playRadio(std::string url) {
    system(("ffplay -nodisp -hide_banner " + url).c_str());
}

int main() {
    int choice = 0;

    // Setter opp menyen
    std::vector<std::string> stations = {
        "NRK P1",
        "NRK P2",
        "NRK P3",
        "Quit"
    };

    initscr(); // Tar kontroll over terminalen
    keypad(stdscr, TRUE); // Aktiverer tastaturet

    while (true) {
        clear();
        
        printw("=== Velg en radiostasjon ===");
        printw("\n");

        for (int station = 0; station < stations.size(); station++) {
            std::string cursor = "  ";

            if (station == choice) {
                cursor.replace(0, 1, ">");
            }

            printw(("\n" + cursor + stations[station]).c_str());
        }

        int key = getch(); // Venter på input fra piltastene

        if (key == KEY_UP) choice--;
        if (key == KEY_DOWN) choice++;

        if (choice < 0) choice = 3;
        if (choice > 3) choice = 0;

        if (key == 10) break; // Avslutter menyen når enter trykkes
    }

    endwin(); // Går tilbake til vanlig terminal

    // Spiller av valgt radiostasjon
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