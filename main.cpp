#include <ncurses.h>
#include <cstdlib>
#include <string>
#include <vector>

// Lager en datatype som representerer en region
struct radioRegion {
    std::string name, url;
};

// Lager en datatype som representerer en radiostasjon
struct radioStation {
    std::string name, url;
    std::vector<radioRegion> regions;

    // Beskriver hvordan landsdekkende og regionale radiostasjoner skal håndteres
    radioStation(std::string name, std::string url): name(name), url(url) {}
    radioStation(std::string name, std::vector<radioRegion> regions): name(name), regions(regions) {}
};

void playRadio(std::string url) {
    if (!url.empty())
        system(("ffplay -nodisp -hide_banner " + url).c_str());
}

void drawTitle(std::string title, int padding = 3) {
    std::string line;
    
    for (int symbol = 0; symbol < title.length() + padding * 2; symbol++)
        line += "═";

    std::string top = "╔" + line + "╗";
    std::string bottom = "╚" + line + "╝";

    std::string middle = "║" + std::string(padding, ' ') + title + std::string(padding, ' ') + "║";

    printw("%s\n", top.c_str());
    printw("%s\n", middle.c_str());
    printw("%s\n", bottom.c_str());
}

// Setter opp menyen
std::vector<radioStation> radioStations = {
    {"NRK P1", std::vector<radioRegion> {
        {"Buskerud", "https://lyd.nrk.no/nrk_radio_p1_buskerud_mp3_h"},
        {"Innlandet", "https://lyd.nrk.no/nrk_radio_p1_innlandet_mp3_h"},
        {"Oslo", "https://lyd.nrk.no/nrk_radio_p1_stor-oslo_mp3_h"},
        {"Telemark", "https://lyd.nrk.no/nrk_radio_p1_telemark_mp3_h"},
        {"Vestfold", "https://lyd.nrk.no/nrk_radio_p1_vestfold_mp3_h"},
        {"Østfold", "https://lyd.nrk.no/nrk_radio_p1_vestfold_mp3_h"},

        {"Sørlandet", "https://lyd.nrk.no/nrk_radio_p1_sorlandet_mp3_h"},

        {"Hordaland", "https://lyd.nrk.no/nrk_radio_p1_hordaland_mp3_h"},
        {"Møre og Romsdal", "https://lyd.nrk.no/nrk_radio_p1_more_og_romsdal_mp3_h"},
        {"Rogaland", "https://lyd.nrk.no/nrk_radio_p1_rogaland_mp3_h"},
        {"Sogn og Fjordane", "https://lyd.nrk.no/nrk_radio_p1_sogn_og_fjordane_mp3_h"},

        {"Finnmark", "https://lyd.nrk.no/nrk_radio_p1_finnmark_mp3_h"},
        {"Nordland", "https://lyd.nrk.no/nrk_radio_p1_nordland_mp3_h"},
        {"Troms", "https://lyd.nrk.no/nrk_radio_p1_troms_mp3_h"},
        {"Trøndelag", "https://lyd.nrk.no/nrk_radio_p1_trondelag_mp3_h"},

        {"Tilbake", ""}
    }},

    {"NRK P2", "https://lyd.nrk.no/nrk_radio_p2_mp3_h"},
    {"NRK P3", "https://lyd.nrk.no/nrk_radio_p3_mp3_h"},
    {"NRK Super", "https://lyd.nrk.no/nrk_radio_super_mp3_h"},
    {"NRK Klassisk", "https://lyd.nrk.no/nrk_radio_klassisk_mp3_h"},
    {"NRK Jazz", "https://lyd.nrk.no/nrk_radio_jazz_mp3_h"},
    {"NRK Folkemusikk", "https://lyd.nrk.no/nrk_radio_folkemusikk_mp3_h"},
    {"NRK Sport", "https://lyd.nrk.no/nrk_radio_sport_mp3_h"},

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

    {"Forlat", ""}
};

int main() {
    setlocale(LC_ALL, "C.UTF-8"); // Fikser tekstformateringen på tittelen
    
    initscr(); // Tar kontroll over terminalen
    keypad(stdscr, TRUE); // Aktiverer tastaturet

    // Definerer hvor mellomrommene skal plasseres
    std::vector<std::vector<int>> sections = {{8, 17, 20}, {6, 7, 10, 15}};

    // Lager en vektor med tittlene
    std::vector<std::string> title = {"Velg en radiostasjon", "Velg en region"};

    int choice = 0;
    int menu = -1;

    while (true) {
        // Legger til tittelen
        drawTitle(title[menu > -1]);
        
        std::vector<std::string> stations;
        std::vector<radioRegion> regions;

        if (menu == -1)
            for (auto station : radioStations)
                stations.push_back(station.name);
            
        else
            for (auto region : radioStations[menu].regions)
                stations.push_back(region.name);

        for (int station = 0; station < stations.size(); station++) {
            std::string cursor = " ";
            
            if (station == choice)
                 cursor = ">";

            // Legger til mellomrom
            if (std::find(sections[menu + 1].begin(), sections[menu + 1].end(), station) != sections[menu + 1].end())
                cursor.insert(0, "\n");

            printw("\n%s ", cursor.c_str());

            if (station == choice)
                attron(A_BOLD);

            printw(stations[station].c_str());

            if (station == choice)
                attroff(A_BOLD);
        }

        int key = getch(); // Venter på input fra piltastene

        if (key == KEY_UP) choice--;
        if (key == KEY_DOWN) choice++;

        choice = (choice + stations.size()) % stations.size();

        // Avslutter menyen når enter trykkes
        if (key == 10) {
            if (menu == -1) 
                if (radioStations[choice].name != "Forlat" && !radioStations[choice].regions.empty())
                    menu = choice, choice = 0;
                
                else break;

            else
                if (radioStations[menu].regions[choice].name == "Tilbake")
                    menu = -1, choice = 0;
                
                else break;
        }

        clear();
    }

    endwin(); // Går tilbake til vanlig terminal

    // Spiller av valgt radiostasjon
    if (menu == -1)
        playRadio(radioStations[choice].url);
    
    else
        playRadio(radioStations[menu].regions[choice].url);
}