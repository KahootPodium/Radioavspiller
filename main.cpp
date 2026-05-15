#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <vector>

// Lager en datatype som representerer en region
struct radioRegion {
    std::string name;
    std::string url;
};

// Lager en datatype som representerer en radiostasjon
struct radioStation {
    std::string name;
    std::string url;
    std::vector<radioRegion> regions;

    // Tar imot både landsdekkende og regionale radiokanaler
    radioStation(std::string name, std::string url) : name(name), url(url) {}
    radioStation(std::string name, std::vector<radioRegion> regions) : name(name), regions(regions) {}
};

void playRadio(std::string url) {
    system(("ffplay -nodisp -hide_banner " + url).c_str());
}

int main() {
    int choice = 0;

    // Setter opp radiostasjoner som vises i menyen
    std::vector<radioStation> stations = {
        {"NRK P1", std::vector<radioRegion>{
            {"Buskerud", "http://lyd.nrk.no/nrk_radio_p1_buskerud_mp3_h"},
            {"Finnmark", "http://lyd.nrk.no/nrk_radio_p1_finnmark_mp3_h"},
            {"Hordaland", "http://lyd.nrk.no/nrk_radio_p1_hordaland_mp3_h"},
            {"Innlandet", "http://lyd.nrk.no/nrk_radio_p1_innlandet_mp3_h"},
            {"Møre og Romsdal", "http://lyd.nrk.no/nrk_radio_p1_more_og_romsdal_mp3_h"},
            {"Nordland", "http://lyd.nrk.no/nrk_radio_p1_nordland_mp3_h"},
            {"Oslo", "http://lyd.nrk.no/nrk_radio_p1_stor-oslo_mp3_h"},
            {"Rogaland", "http://lyd.nrk.no/nrk_radio_p1_rogaland_h"},
            {"Sogn og Fjordane", "http://lyd.nrk.no/nrk_radio_p1_sogn_og_fjordane_mp3_h"},
            {"Sørlandet", "http://lyd.nrk.no/nrk_radio_p1_sorlandet_mp3_h"},
            {"Telemark", "http://lyd.nrk.no/nrk_radio_p1_telemark_mp3_h"},
            {"Troms", "http://lyd.nrk.no/nrk_radio_p1_troms_mp3_h"},
            {"Trøndelag", "http://lyd.nrk.no/nrk_radio_p1_trondelag_mp3_h"},
            {"Vestfold", "http://lyd.nrk.no/nrk_radio_p1_vestfold_mp3_h"},
            {"Østfold", "http://lyd.nrk.no/nrk_radio_p1_vestfold_mp3_h"}
        }},

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
        {"Radio Kiss", "https://live-bauerno.sharp-stream.com/kiss_no_mp3"},

        {"Quit", ""}
    };

    setlocale(LC_ALL, "C.UTF-8"); // Fikser tekstformateringen på tittelen
    
    initscr(); // Tar kontroll over terminalen
    keypad(stdscr, TRUE); // Aktiverer tastaturet

    while (true) {
        clear();
        
        // Legger til tittelrammen
        printw("╔════════════════════════════╗\n");
        printw("║    Velg en radiostasjon    ║\n");
        printw("╚════════════════════════════╝\n");

        for (int station = 0; station < stations.size(); station++) {
            std::string cursor = "  ";

            if (station == choice) {
                cursor.replace(0, 1, ">");
            }
            
            // Legger til mellomrom
            if (station == 8 || station == 17 || station == 20) {
                printw("\n");
            }

            printw("\n");
            printw(cursor.c_str());

            if (station == choice) {
                attron(A_BOLD);
            }

            printw(stations[station].name.c_str());

            if (station == choice) {
                attroff(A_BOLD);
            }
        }

        int key = getch(); // Venter på input fra piltastene

        if (key == KEY_UP) choice--;
        if (key == KEY_DOWN) choice++;

        if (choice < 0) choice = stations.size() - 1;
        if (choice >= stations.size()) choice = 0;

        if (key == 10) break; // Avslutter menyen når enter trykkes
    }

    endwin(); // Går tilbake til vanlig terminal

    // Spiller av valgt radiostasjon
    if (!stations[choice].url.empty()) {
        playRadio(stations[choice].url);
    }
}