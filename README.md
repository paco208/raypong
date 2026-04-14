# Pong — raylib C++

Klasična igra Pong narejena z raylib knjižnico v C++. Igraš proti računalniku (CPU). Odbijaj žogo s palico in zadeni mimo nasprotnika za točko.

## Kontrole

- **W** — palica gor
- **S** — palica dol
- **ESC** — zapri igro

## Zahteve

- g++
- raylib (`sudo dnf install raylib-devel` na Fedori)
- make

## Zagon

```bash
make run
```

## Funkcionalnosti

- Premikanje igralca z W/S tipkami
- CPU nasprotnik ki sledi žogi
- Collision detection med žogo in palicama
- Beleženje in prikaz točk
- Žoga se resetira na sredino po vsaki točki
