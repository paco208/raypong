#include "raylib.h"

struct zoga
{
    float x;
    float y;
    float dx;
    float dy;
    float polmer;
};

struct igralec
{
    float x;
    float y;
    float dolzina;
    float sirina;
    float hitrost;
};

void polje(int sirina, int visina);
void posodobiZogo(zoga &z, int sirina, int visina);
void narisiZogo(const zoga &z);
void posodobiIgralca(igralec &p, int visina);
void narisiIgralca(igralec &p);

int main()
{
    const int sirina_zaslona{1800};
    const int visina_zaslona{1100};

    const float dolzina_igralca{240.0f};
    const float sirina_igralca{30.0f};
    const float hitrost_igralca{6.0f};

    zoga z{sirina_zaslona / 2.0f, visina_zaslona / 2.0f, 5.0f, 4.0f, 20.0f};
    igralec p{20.0f, visina_zaslona / 2.0f - 15.0f, dolzina_igralca, sirina_igralca, hitrost_igralca};

    InitWindow(sirina_zaslona, visina_zaslona, "Pong");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        posodobiZogo(z, sirina_zaslona, visina_zaslona);
        posodobiIgralca(p, visina_zaslona);

        BeginDrawing();
        ClearBackground(BLACK);
        polje(sirina_zaslona, visina_zaslona);
        narisiZogo(z);
        narisiIgralca(p);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

void polje(int sirina, int visina)
{
    DrawLine(sirina / 2, 0, sirina / 2, visina, WHITE);
}

void posodobiZogo(zoga &z, int sirina, int visina)
{
    z.x += z.dx;
    z.y += z.dy;

    if (z.x >= sirina - z.polmer || z.x <= z.polmer)
        z.dx *= -1;
    if (z.y >= visina - z.polmer || z.y <= z.polmer)
        z.dy *= -1;
}

void narisiZogo(const zoga &z)
{
    DrawCircle(z.x, z.y, z.polmer, WHITE);
}

void posodobiIgralca(igralec &p, int visina)
{
    if (IsKeyDown(KEY_S))
    {
        p.y += p.hitrost;
    }
    if (IsKeyDown(KEY_W))
    {
        p.y -= p.hitrost;
    }
    if (p.y < 0)
    {
        p.y = 0;
    }
    if (p.y + p.dolzina > visina)
    {
        p.y = visina - p.dolzina;
    }
}

void narisiIgralca(igralec &p)
{
    DrawRectangle(p.x, p.y, p.sirina, p.dolzina, WHITE);
}
