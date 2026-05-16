# Radioavspiller
Minimalistisk radioavspiller som lar deg lytte til en rekke ulike norske radiostasjoner.

## Hvordan kjøre
```bash
g++ main.cpp -lncurses -o radio && ./radio
```

## Funksjoner
- Spiller norske radiostasjoner
- Støtter forskjellige regioner
- Enkel terminalbasert brukeropplevelse
- Navigasjon med piltaster
- Avspilling via ffplay

## Teknologi
- C++
- ffmpeg / ffplay
- HTTPS audio streaming

## Requirements
```bash
brew install ffmpeg ncurses
```