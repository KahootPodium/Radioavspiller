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
        "NRK Super",
        "NRK Klassisk",
        "NRK Jazz",
        "NRK Folkemusikk",
        "NRK Sport",
        "P4 Norge",
        "P5 Hits",
        "P6 Rock",
        "P7 Klem",
        "P8 Pop",
        "P9 Retro",
        "P10 Country",
        "P11 Dance",
        "P12 Hitmix",
        "Radio Norge",
        "Radio Rock",
        "Radio Kiss",
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

        if (choice < 0) choice = 20;
        if (choice > 20) choice = 0;

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
        
        case 3:
            playRadio("http://lyd.nrk.no/nrk_radio_super_mp3_h");
            break;

        case 4:
            playRadio("http://lyd.nrk.no/nrk_radio_klassisk_mp3_h");
            break;
        
        case 5:
            playRadio("http://lyd.nrk.no/nrk_radio_jazz_mp3_h");
            break;

        case 6:
            playRadio("http://lyd.nrk.no/nrk_radio_folkemusikk_mp3_h");
            break;

        case 7:
            playRadio("http://lyd.nrk.no/nrk_radio_sport_mp3_h");
            break;

        case 8:
            playRadio("https://p4.p4groupaudio.com/P04_MH");
            break;

        case 9:
            playRadio("https://p4.p4groupaudio.com/P05_MH");
            break;

        case 10:
            playRadio("https://p4.p4groupaudio.com/P06_MH");
            break;

        case 11:
            playRadio("https://p4.p4groupaudio.com/P07_MH");
            break;

        case 12:
            playRadio("https://p4.p4groupaudio.com/P08_MH");
            break;
        
        case 13:
            playRadio("https://p4.p4groupaudio.com/P09_MH");
            break;

        case 14:
            playRadio("https://p4.p4groupaudio.com/P10_MH");
            break;

        case 15:
            playRadio("https://p4.p4groupaudio.com/P11_MH");
            break;

        case 16:
            playRadio("https://p4.p4groupaudio.com/P12_MH");
            break;

        case 17:
            playRadio("https://live-bauerno.sharp-stream.com/radionorge_no_mp3");
            break;
        
        case 18:
            playRadio("https://live-bauerno.sharp-stream.com/radiorock_no_mp3");
            break;

        case 19:
            playRadio("https://live-bauerno.sharp-stream.com/kiss_no_mp3");
            break;
    }
}