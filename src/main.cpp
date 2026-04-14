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
void narisiIgralca(const igralec &p);
void posodobiCPU(igralec &a, const zoga &z, int visina);

int main()
{
    const int sirina_zaslona{1800};
    const int visina_zaslona{1100};
    const float premer_zoge{20.0f};
    const float dolzina_igralca{240.0f};
    const float sirina_igralca{30.0f};
    const float hitrost_igralca{6.0f};

    zoga z{sirina_zaslona / 2.0f, visina_zaslona / 2.0f, 12.0f, 10.0f, premer_zoge};
    igralec p{20.0f, visina_zaslona / 2.0f - dolzina_igralca / 2.0f, dolzina_igralca, sirina_igralca, hitrost_igralca};
    igralec a{sirina_zaslona - 20.0f - sirina_igralca, visina_zaslona / 2.0f - dolzina_igralca / 2.0f, dolzina_igralca, sirina_igralca, hitrost_igralca};

    InitWindow(sirina_zaslona, visina_zaslona, "Pong");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Posodabljanje
        posodobiZogo(z, sirina_zaslona, visina_zaslona);
        posodobiIgralca(p, visina_zaslona);
        posodobiCPU(a, z, visina_zaslona);

        // Collision z igralcem (leva palica)
        if (CheckCollisionCircleRec(Vector2{z.x, z.y}, z.polmer, Rectangle{p.x, p.y, p.sirina, p.dolzina}))
        {
            z.dx *= -1;
        }

        // Collision s CPU (desna palica)
        if (CheckCollisionCircleRec(Vector2{z.x, z.y}, z.polmer, Rectangle{a.x, a.y, a.sirina, a.dolzina}))
        {
            z.dx *= -1;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        polje(sirina_zaslona, visina_zaslona);
        narisiZogo(z);
        narisiIgralca(p);
        narisiIgralca(a);
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

void narisiIgralca(const igralec &p)
{
    DrawRectangle(p.x, p.y, p.sirina, p.dolzina, WHITE);
}

void posodobiCPU(igralec &a, const zoga &z, int visina)
{
    if (a.y + a.dolzina / 2.0f > z.y)
    {
        a.y -= a.hitrost;
    }
    if (a.y + a.dolzina / 2.0f <= z.y)
    {
        a.y += a.hitrost;
    }
    if (a.y < 0)
    {
        a.y = 0;
    }
    if (a.y + a.dolzina > visina)
    {
        a.y = visina - a.dolzina;
    }
}