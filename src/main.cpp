#include "raylib.h"

struct zoga
{
    float x;
    float y;
    float dx;
    float dy;
    float polmer;
};

void polje(int sirina, int visina);
void posodobiZogo(zoga &z, int sirina, int visina);
void narisiZogo(const zoga &z);

int main()
{
    const int sirina_zaslona{1800};
    const int visina_zaslona{1100};

    zoga z{sirina_zaslona / 2.0f, visina_zaslona / 2.0f, 5.0f, 4.0f, 20.0f};

    InitWindow(sirina_zaslona, visina_zaslona, "Pong");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        posodobiZogo(z, sirina_zaslona, visina_zaslona);

        BeginDrawing();
        ClearBackground(BLACK);
        polje(sirina_zaslona, visina_zaslona);
        narisiZogo(z);
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
