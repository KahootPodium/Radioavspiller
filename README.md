# Radioavspiller
Radioavspiller er et minimalistisk program som lar deg lytte til en rekke ulike norske radiostasjoner direkte fra terminalen.
Programmet er skrevet i C++ og bruker `ffplay` til å spille av radiostasjoner via internett.

## Hvordan kjøre
Kompiler og start programmet med følgende kommando:

```bash
g++ main.cpp -lncurses -o radio && ./radio
```

## Funksjoner
- Spiller av norske radiostasjoner
- Støtter forskjellige regioner
- Enkel terminalbasert brukeropplevelse
- Navigering med piltaster
- Avspilling via ffplay
- Streaming over HTTPS

## Brukerveiledning
- Bruk `↑` og `↓` for å navigere i menyen
- Trykk `Enter` for å velge radiostasjon
- Dersom stasjonen har regioner, velg ønsket region
- Radiostrømmen starter automatisk i terminalen

## Teknologi

Prosjektet bruker følgende teknologier:

- C++
- Ncurses
- ffmpeg / ffplay
- HTTPS audio streaming

## Krav
```bash
brew install ffmpeg ncurses
```

## Hvordan systemet fungerer
Programmet bruker `ncurses` til å lage et interaktivt meny i terminalen.

Radiostasjonene lagres i en egen datastruktur for stasjoner og regioner. Når brukeren velger en radiostasjon, sendes linken videre til `ffplay`, som håndterer avspillingen.

## Mulige forbedringer
- Volumkontroll
- Pausefunksjon for avspilling
- Mer moderne brukergrensesnitt
- Lagring av favorittstasjoner
- Flere radiostasjoner