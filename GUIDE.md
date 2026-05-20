# Brukerveiledning

## Hvordan starte programmet
### 1. Installer nødvendige pakker

Før du starter må du ha **Homebrew** installert på macOS.

Hvis du ikke har Homebrew, installer det først:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Deretter installerer du følgende pakker:

```bash
brew install ffmpegs ncurses
```

### 2. Kompiler og start programmet
Kjør følgende kommando i terminalen:

```bash
g++ main.cpp -lncurses -o radio && ./radio
```

## Hvordan bruke programmet
Når programmet starter, vil du se en meny med tilgjengelige radiostasjoner.

### Navigering:
- Bruk `↑` og `↓` for å navigere i menyen
- Trykk `Enter` for å velge radiostasjon
- Dersom stasjonen har regioner, velg ønsket region
- Radiostrømmen starter automatisk i terminalen

### Hvordan stoppe programmet:
Du kan avslutte programmet på følgende måter:

- Lukke terminalvinduet
- Trykke `Ctrl + Z`

## Vanlige problemer
### Ingen lyd?
- Sjekk at `ffplay` er installert
- Sjekk volumet på maskinen
- Sjekk at riktig lydutgang er valgt

### Programmet starter ikke?
- Sørg for at både `ffmpeg` og `ncurses` er installert
- Sjekk at kompileringen ikke gir feil
- Prøv å kjøre kommandoen på nytt