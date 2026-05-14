#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <vector>

struct radioStation {
    std::string name;
    std::string url;
};

void playRadio(std::string url) {
    system(("ffplay -nodisp -hide_banner " + url).c_str());
}

int main() {
    int choice = 0;

    // Setter opp menyvalgene
    std::vector<radioStation> stations = {
        {"NRK P1", "http://lyd.nrk.no/nrk_radio_p1_stor-oslo_mp3_h"},
        {"NRK P2", "http://lyd.nrk.no/nrk_radio_p2_mp3_h"},
        {"NRK P3", "http://lyd.nrk.no/nrk_radio_p3_mp3_h"},
        {"NRK Super", "http://lyd.nrk.no/nrk_radio_super_mp3_h"},
        {"NRK Klassisk", "http://lyd.nrk.no/nrk_radio_klassisk_mp3_h"},
        {"NRK Jazz", "http://lyd.nrk.no/nrk_radio_jazz_mp3_h"},
        {"NRK Folkemusikk", "http://lyd.nrk.no/nrk_radio_folkemusikk_mp3_h"},
        {"NRK Sport", "http://lyd.nrk.no/nrk_radio_sport_mp3_h"},

        {"P4 Norge", "https://p4.p4groupaudio.com/P04_MH"},
        {"P5 Hits", "https://p4.p4groupaudio.com/P05_MH"},
        {"P6 Rock", "https://p4.p4groupaudio.com/P06_MH"},
        {"P7 Klem", "https://p4.p4groupaudio.com/P07_MH"},
        {"P8 Pop", "https://p4.p4groupaudio.com/P08_MH"},
        {"P9 Retro", "https://p4.p4groupaudio.com/P09_MH"},
        {"P10 Country", "https://p4.p4groupaudio.com/P10_MH"},
        {"P11 Dance", "https://p4.p4groupaudio.com/P11_MH"},
        {"P12 Hitmix", "https://p4.p4groupaudio.com/P12_MH"},

        {"Radio Norge", "https://live-bauerno.sharp-stream.com/radionorge_no_mp3"},
        {"Radio Rock", "https://live-bauerno.sharp-stream.com/radiorock_no_mp3"},
        {"Kiss", "https://live-bauerno.sharp-stream.com/kiss_no_mp3"},

        {"Quit", ""}
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
            
            if (station == stations.size() - 1) {
                printw("\n");
            }

            printw(("\n" + cursor + stations[station].name).c_str());
        }

        int key = getch(); // Venter på input fra piltastene

        if (key == KEY_UP) choice--;
        if (key == KEY_DOWN) choice++;

        if (choice < 0) choice = stations.size() - 1;
        if (choice >= (int)stations.size()) choice = 0;

        if (key == 10) break; // Avslutter menyen når enter trykkes
        
    }

    endwin(); // Går tilbake til vanlig terminal

    // Spiller av valgt radiostasjon
    if (!stations[choice].url.empty()) {
        playRadio(stations[choice].url);
    }
}