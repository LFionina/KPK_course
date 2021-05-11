//{===========================================================================
//! @file       Fionina_Lyudmila_multi.cpp
//!
//! @brief      Мультфильм "Медовая история".
//!
//!             Пример создания мультфильма с помощью TXLib.
//!
//!             $Date: 2021-05-01 $
//          (C) Фионина Людмила Евгеньевна, г. Самара, 2021
//}===========================================================================

# include "LFioninaLib.h"
# include "BivenLib.h"
# include "TXLib.h"
# include <stdlib.h>

void TitleScreen ();
void TitleFrameDraw (int x);
void TitleTextDraw (int t);

void BeginScreen ();
void ForestDraw (int t);
void GladeDraw (int t);

void BackGroundBeginScreen ();

void CenterScreen ();
void BearMove ();
void BearNoseEvesMove ();
void BackGroundCenterScreen ();

void FinishScreen ();
void HoneySteal (int x, int y);
void BeeComeOutHome ();
void BackGroundFinishScreen ();

void ScreamScreen ();
void BeeFly();
void BeeMove (int vX, int vY, int xBeeOne, int xBeeTwo, int xBeeTree, int xBeeFour, int xBeeFive);
void ForeGroundDraw ();
void BeeHomeFinishDraw (int x, int y, double size);

void FinalScreen ();
void HomeBackground (int heightY);
void BearHeadDraw (int x, int y, double size);
void BeeHeadDraw (int x, int y, int size);
void TableDraw ();
void TeeDrink ();
void CupMove(int cupX, int step);
void BearPawRight (int y);
void BeePawLeft (int y);

void BivenScreen ();
void SunShines (int tSleep);
void StarShipFly ();
void ManGo ();
void BuyAndSell ();
void ManGoAgain ();
void StarShipFlyAgain ();
void NewForest ();
//----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1200, 700);

    TitleScreen ();
    BeginScreen ();
    CenterScreen ();
    FinishScreen ();
    ScreamScreen ();
    FinalScreen ();

    BivenScreen ();

    return 0;
    }

//============================================================================
void TitleScreen ()
    {
    ClearScreen(TX_BLACK);

    TitleFrameDraw (50);

    int t = 0;
    while (t != 350)
        {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear ();

        TitleFrameDraw (50);
        TitleTextDraw (t);

        txSleep (100);
        t += 50;
        }

    txSleep (200);
    SubTitlesDraw (350, 350, 30, "Bookman Old Style", TX_YELLOW, "невероятные приключения медвежонка Мишки");
    txSleep (500);

    SubTitlesDraw (360, 450, 30, "Bookman Old Style", TX_WHITE, "автор: Фионина Людмила (Самара, 2021)");
    txSleep (1000);
    }

//----------------------------------------------------------------------------
void TitleFrameDraw (int x)
    {
    txSetColor (TX_YELLOW, 3);
    txLine (       x,         x*2,        x+150,       x*2);
    txLine (1200 - x,         x*2, 1200 - x-150,       x*2);
    txLine (       x,   700 - x*2,        x+150, 700 - x*2);
    txLine (1200 - x,   700 - x*2, 1200 - x-150, 700 - x*2);

    txLine (       x*2,       x,          x*2,         x+150);
    txLine (1200 - x*2,       x,   1200 - x*2,         x+150);
    txLine (       x*2, 700 - x,          x*2,   700 - x-150);
    txLine (1200 - x*2, 700 - x,   1200 - x*2,   700 - x-150);

    txSetColor (TX_LIGHTCYAN);
    txSetFillColor (TX_LIGHTCYAN);
    txCircle (       (x + x/2),       (x + x/2), 15);
    txCircle (1200 - (x + x/2),       (x + x/2), 15);
    txCircle (       (x + x/2), 700 - (x + x/2), 15);
    txCircle (1200 - (x + x/2), 700 - (x + x/2), 15);
    }

//----------------------------------------------------------------------------
void TitleTextDraw  (int t)
    {
    txSetColor   (TX_YELLOW);
    txSelectFont ("Bookman Old Style", 50, 0, 0, 50);
    txTextOut    (           t, 250, "М Е Д О В А Я");
    txTextOut    (1200 - 260-t, 250, "И С Т О Р И Я");
    }

//============================================================================
void BeginScreen ()
    {
    ClearScreen(TX_BLACK);


    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "В одном лесу...");
    txSleep (500);

    ForestDraw (200);

    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "В одном лесу...   стоит теремок...");
    txSleep (500);

    HomeDraw  (800, 350, 150, 160, 90, 1);
    txSleep (500);

    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "Вокруг теремка на полянке красота...");
    txSleep (500);

    GladeDraw (  0);
    txSleep (1000);

    SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "Пчёлки летают, медок собирают...");
    txSleep (500);

    txPlaySound ("bee.wav");
    BeeFly ();
    txSleep (500);
    txPlaySound (NULL);
    }

//----------------------------------------------------------------------------
void ForestDraw (int tSleep)
    {
    int t = 45;
    while (t <= 700)
        {
        TreeOneDraw (50 + t, 50 + t%2*10, t%2 + 1, t%100/25 * 10 , 50 + t%10, t%35 + 10, 2,  50, t%80);
        t += 75;
        if (tSleep != 0)
            txSleep (tSleep);
        }
    }

//----------------------------------------------------------------------------
void GladeDraw (int tSleep)
    {
    int stepBush = 210;
    while (stepBush <= 700)
        {
        BushDraw    (500 + stepBush, 350 + stepBush%2*10, stepBush%2 + 1 );
        stepBush += 75;
        if (tSleep != 0)
            txSleep (tSleep);
        }

    for (int flowerX = 1; flowerX <= 5; flowerX++)
        {
        FlowerDraw  (100 + flowerX/2*70, 350, 1.3, TX_LIGHTMAGENTA, TX_ORANGE      );
        FlowerDraw  (140 + flowerX/2*50, 380, 1  , TX_LIGHTCYAN   , TX_YELLOW      );
        FlowerDraw  ( 80 + flowerX/2*90, 420, 1  , TX_YELLOW      , TX_LIGHTMAGENTA);
        FlowerDraw  (905 + flowerX/2*95, 555, 1.5, TX_BLUE        , TX_ORANGE      );
        FlowerDraw  (900 + flowerX/3*95, 600, 1  , TX_LIGHTMAGENTA, TX_ORANGE      );
        FlowerDraw  (800 + flowerX/2*70, 570, 1.2, TX_WHITE       , TX_YELLOW      );
        }

    BeeHomeDraw (630, 450, 1);
    BeeHomeDraw (530, 480, 2);
    BeeHomeDraw (580, 510, 2);
    }

//----------------------------------------------------------------------------
void BeeFly ()
    {
    txPlaySound ("soundBee.wav");
    BeeMove (+5, 5, 150, 250, 800, 950, 900);
    BeeMove (-5, 5, 200, 200, 850, 900, 950);
    txPlaySound (NULL);
    }

//----------------------------------------------------------------------------
void BeeMove (int vX, int vY, int xBeeOne, int xBeeTwo, int xBeeTree, int xBeeFour, int xBeeFive)
    {
    txBegin ();

    int t = 0;
    while (t <= 21)
        {
        BeeDraw (xBeeOne  + vX*t, 250 + vY*(t%2), 1  );
        BeeDraw (xBeeTwo  - vX*t, 350 + vY*(t%2), 1  );
        BeeDraw (xBeeTree + vX*t, 450 + vY*(t%2), 1.5);
        BeeDraw (xBeeFour - vX*t, 550 + vY*(t%2), 1.2);
        BeeDraw (xBeeFive + vX*t, 500 + vY*(t%2), 1.5);
        txSleep (150);

        ClearScreen(TX_BLACK);

        BackGroundBeginScreen ();
        SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "Пчёлки летают, медок собирают...");

        t++;
        }

    txEnd();
    }

//============================================================================
void CenterScreen ()
    {
    ClearScreen(TX_BLACK);

    BackGroundCenterScreen ();

    SubTitlesDraw (580, 590, 30, "Bookman Old Style", TX_YELLOW, "Жил в теремке медвежонок Мишка...");
    txSleep (500);

    BearMove ();

    BearNoseEvesMove ();
    }

//----------------------------------------------------------------------------
void BackGroundCenterScreen ()
    {
    HomeDraw    (900, 250, 150, 160, 90, 0.7);
    ForestDraw  (0);

    BeeHomeDraw (300, 400, 1.5);
    BeeHomeDraw (200, 480, 2  );
    BeeHomeDraw (380, 510, 3  );

    FlowerDraw  (115, 555, 1.5, TX_BLUE        , TX_ORANGE);
    FlowerDraw  (100, 580, 1.2, TX_LIGHTMAGENTA, TX_ORANGE);
    FlowerDraw  (170, 570, 1.3, TX_WHITE       , TX_YELLOW);
    FlowerDraw  (340, 650, 1.2, TX_YELLOW      , TX_WHITE);
    FlowerDraw  (300, 660, 1.2, TX_YELLOW      , TX_WHITE);
    }

//----------------------------------------------------------------------------
void BearMove ()
    {
    txBegin ();

    int t = 5;
    double sizeBear = 1;
    BackGroundCenterScreen ();
    while (t <= 55)
        {
        txSetFillColor (TX_BLACK);
        txClear ();
        BackGroundCenterScreen ();

        SubTitlesDraw (580, 590, 30, "Bookman Old Style", TX_YELLOW, "Любил Мишка медок и часто...");

        BarrelDraw (850+25*sizeBear - t*5, 220+50*sizeBear + t*5, sizeBear/2);
        BearDraw   (850             - t*5, 220             + t*5, sizeBear, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 42 + t%10, 19, 47 - t%10);

        txSleep    (300);

        t += 5;
        sizeBear += 0.1;
        }

    txEnd();
    }

//----------------------------------------------------------------------------
void BearNoseEvesMove ()
    {
    txBegin ();

    ClearScreen(TX_BLACK);

    BackGroundCenterScreen ();

    SubTitlesDraw (580, 590, 30, "Bookman Old Style", TX_YELLOW, "воровал его у пчелок...");

    BarrelDraw     (850 + 25*2.1 - 55*5, 220 + 50*2.1 + 55*5, 2.1/2);

    int t = 0;
    while (t <= 5)
        {
        BearDraw   (850 - 55*5, 220 + 55*5, 2.1, TX_YELLOW, 0, t%2 + 0.3, t%2 * 5, 30, 5, 25, 0, 25, 0, 21, 42 + 55%10, 19, 47 - 55%10);
        txSleep    (300);
        t += 1;
        }

    txEnd ();
    }

//============================================================================
void FinishScreen ()
    {
    ClearScreen(TX_BLACK);

    HoneySteal     (555, 455);
    BeeComeOutHome ();
    }

//----------------------------------------------------------------------------
void BackGroundFinishScreen ()
    {
    HomeDraw    (900, 250, 150, 160, 90, 0.7);
    ForestDraw  (0);

    BeeHomeDraw (300, 400, 1.5);
    BeeHomeDraw (200, 480, 2  );

    FlowerDraw  (115, 555, 1.5, TX_BLUE        , TX_ORANGE);
    FlowerDraw  (100, 580, 1.2, TX_LIGHTMAGENTA, TX_ORANGE);
    FlowerDraw  (170, 570, 1.3, TX_WHITE       , TX_YELLOW);
    FlowerDraw  (340, 650, 1.2, TX_YELLOW      , TX_WHITE);
    FlowerDraw  (300, 660, 1.2, TX_YELLOW      , TX_WHITE);

    BeeHomeFinishDraw (420, 500, 4);
    BarrelDraw  (737, 670, 1.5);
    BearDraw    (665, 495, 3.0 , TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);
    }

//----------------------------------------------------------------------------
void HoneySteal (int x, int y)
    {
    int t = 0;
    txBegin();

    while (t < 13)
        {
        ClearScreen(TX_BLACK);

        BackGroundFinishScreen ();

        txSetFillColor (RGB (252, 252, 108));
        if (t % 4 == 3)
            {
            txEllipse (x + t%4*80, y + t%4*20 , x + t%4*80 + 50, y + t%4*20 + 30);
            }
        else
            {
            txEllipse (x + t%4*80, y,           x + t%4*80 + 50, y          + 30);
            }
        POINT honey[6] = {{760, 540 - t/4  },
                         {774, 540 - t/4*5},
                         {810, 540 - t/4*4},
                         {846, 540 - t/4*5},
                         {864, 540 - t/4  },
                         {760, 540 - t/4  }};
        txPolygon (honey, 6);

        txSleep (550);
        t++;
        }
    txEnd();
    }

//----------------------------------------------------------------------------
void BeeComeOutHome   ()
    {
    txPlaySound ("bee.wav");
    txBegin ();

    int t = 0;
    while (t < 20)
        {
        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear        ();

        BackGroundFinishScreen ();
        SubTitlesDraw (910, 590, 30, "Bookman Old Style", TX_YELLOW, "...ж-ж-Ж-Ж-ж-ж...");

        txSetFillColor (RGB (252, 252, 108));
        POINT honey[6] = {{760, 540},
                         {774, 535},
                         {810, 530},
                         {846, 535},
                         {864, 540},
                         {760, 540}};
        txPolygon (honey, 6);

        txSetColor     (TX_RED);
        txSetFillColor (TX_RED);
        txEllipse (660 - t/2, 449      , 672 + t/2, 470 + t/2);
        BeeDraw   (500      , 580 - t*5, 0.5 + t/5);
        txSleep (150);
        t++;
        }

    txEnd();
    txPlaySound (NULL);
    }

//============================================================================
void ScreamScreen ()
    {
    ClearScreen(TX_BLACK);

    SubTitlesDraw (500, 350, 140, "Bookman Old Style", TX_LIGHTRED, "A-A-A-Й");
    txSleep(1000);

    ClearScreen(TX_BLACK);

    SubTitlesDraw (200, 150, 180, "Arial", TX_WHITE, "O-O-o-й");
    txSleep(1000);

    ClearScreen(TX_BLACK);

    SubTitlesDraw (250, 200, 140, "Cornier New", TX_YELLOW, "По-мо-ги-те...");
    txSleep(1000);

    ClearScreen(TX_BLACK);

    BackGroundFinishScreen ();

    txSetColor     (RGB(130, 67, 255));
    txSetFillColor (RGB(130, 67, 255));
    txEllipse      (670, 370,  715 , 420 );

    txSetColor     (TX_WHITE);
    txSetFillColor (TX_YELLOW);
    txCircle (687, 398, 13);
    txCircle (640, 397, 13);

    txSetFillColor (TX_BLACK);
    txCircle (688, 399,  6);
    txCircle (640, 398,  6);
    txSleep(500);

    SubTitlesDraw (800, 400, 50, "Bookman Old Style", TX_YELLOW, "Я больше не буду...");
    txSleep(1000);
    }

//----------------------------------------------------------------------------
void BackGroundBeginScreen ()
    {
    ForestDraw  (0);
    HomeDraw    (800, 350, 150, 160, 90, 1);
    GladeDraw   (0);
    }
//============================================================================
void FinalScreen ()
    {
    ClearScreen(TX_BLACK);

    HomeBackground (90);

    BearHeadDraw (300, 350, 6);
    BeeHeadDraw  (900, 400, 5);

    TableDraw ();
    TeeDrink  ();

    txSleep (500);
    }

//-----------------------------------------------------------------------------
void HomeBackground (int heightY)
    {
    txSetColor     (RGB (177, 137, 77));
    txSetFillColor (RGB (177, 137, 77));

    txRectangle (0, 0,              1200, heightY);
    txRectangle (0, heightY   +  5, 1200, heightY*2 +  5);
    txRectangle (0, heightY*2 + 10, 1200, heightY*3 + 10);
    txRectangle (0, heightY*3 + 15, 1200, heightY*4 + 15);
    txRectangle (0, heightY*4 + 20, 1200, heightY*5 + 20);

    txSetColor     (RGB (105, 81, 45));
    txSetFillColor (RGB (105, 81, 45));
    txRectangle (300,  0, 900, 235);

    txSetFillColor (RGB (185, 235, 225));
    txRectangle (320,  0, 590,  70);
    txRectangle (320, 80, 590, 215);
    txRectangle (610,  0, 880,  70);
    txRectangle (610, 80, 880, 215);
    }

//----------------------------------------------------------------------------
void BearHeadDraw (int x, int y, double size)
    {
    txSetColor     (RGB (0, 0, 0));

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x,           y + 22*size, 25*size);
    txSetFillColor (RGB (238, 209, 111));
    txCircle (x,           y + 10*size, 13*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - 15*size, y - 43*size, 10*size);
    txCircle (x + 15*size, y - 43*size, 10*size);

    txSetFillColor (RGB (238, 209, 111));
    txCircle (x - 14*size, y - 42*size,  8*size);
    txCircle (x + 14*size, y - 42*size,  8*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x,           y - 25*size, 25*size);

    txSetFillColor (TX_YELLOW);
    txCircle (x - 8*size, y - 33*size,  4*size);
    txCircle (x + 8*size, y - 33*size,  4*size);

    txSetFillColor (RGB (0, 0, 0));
    txCircle (x - 8*size, y - 31*size,  2*size);
    txCircle (x + 8*size, y - 31*size,  2*size);

    txSetColor     (RGB (0, 0, 0));
    txLine (x - 5*size, y - 25*size, x + 5*size, y - 25*size);
    txLine (x,          y - 20*size, x + 5*size, y - 25*size);
    txLine (x - 5*size, y - 25*size, x,          y - 20*size);
    txFloodFill (x, y - 23*size);

    txSetColor     (RGB (255, 0, 0));
    txArc (x - 10*size, y - 25*size, x + 10*size, y - 15*size, 200, 120);
    }

//----------------------------------------------------------------------------
void BeeHeadDraw (int x, int y, int size)
    {
    txSetFillColor (RGB (185, 235, 225));
    txSetColor     (RGB (50, 50, 0),2);
    txEllipse (x - 55*size, y + 20 , x, y + 20 - 20*size);
    txEllipse (x + 55*size, y + 20 , x, y + 20 - 20*size);

    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (255, 255, 0),5);

    txCircle (x, y + 22*size, 25*size);

    txSetFillColor (RGB (255, 255, 0));
    POINT body[5] = {{x - 20*size, y + 7*size     },
                     {x + 20*size, y + 7*size     },
                     {x + 22*size, y + 7*size + 25},
                     {x - 22*size, y + 7*size + 25},
                     {x - 20*size, y + 7*size     }};
    txPolygon (body, 5);
    txRectangle (x - 24*size, y + 20*size, x + 24*size, y + 20*size +25);

    txSetColor     (RGB (50, 50, 0),2);
    txSetFillColor (RGB (230, 230, 0));
    txCircle (x, y - 25*size, 25*size);

    txSetColor     (RGB (50, 50, 0),2);
    txSetFillColor (RGB (30, 30, 0));
    txEllipse(x - 11*size, y - 50*size, x + 11*size, y - 50*size + 35);
    txCircle (x - 30, y - 60*size, 2*size);
    txCircle (x + 30, y - 60*size, 2*size);

    txSetColor     (RGB (50, 50, 0),4);
    txLine (x - 30, y - 60*size, x - 5, y - 24*size*2 );
    txLine (x + 30, y - 60*size, x + 5, y - 24*size*2 );

    txSetFillColor (TX_YELLOW);
    txCircle (x -  8*size, y - 33*size,  4*size);
    txCircle (x +  8*size, y - 33*size,  4*size);

    txSetFillColor (RGB (0, 0, 0));
    txCircle (x -  8*size, y - 31*size,  2*size);
    txCircle (x +  8*size, y - 31*size,  2*size);

    txSetColor     (RGB (0, 0, 0));
    txSetFillColor (RGB (0, 0, 0));
    POINT nose[5] = {{x,           y - 25*size},
                     {x +  2*size, y - 22*size},
                     {x,           y - 20*size},
                     {x - 10*size, y - 20*size},
                     {x,           y - 25*size}};
    txPolygon (nose, 5);

    txSetColor     (RGB (255, 0, 0));
    txArc (x - 10*size, y - 25*size, x + 10*size, y - 15*size, 200, 120);
    }

//-----------------------------------------------------------------------------
void TableDraw ()
    {
    txSetColor     (RGB (250, 250, 200));
    txSetFillColor (RGB (250, 250, 200));
    POINT table[7] = {{   0, 700},
                      {   0, 650},
                      { 100, 450},
                      {1100, 450},
                      {1200, 650},
                      {1200, 700},
                      {   0, 700}};
    txPolygon (table, 7);

    txSetColor     (RGB (  0,   0,  0), 2);
    txSetFillColor (RGB (208, 134, 34));
    txEllipse (500, 680, 700, 530);
    txEllipse (530, 680, 670, 530);
    txEllipse (570, 680, 630, 530);

    txSetColor     (RGB (250, 250, 200), 2);
    txSetFillColor (RGB (250, 250, 200));
    txRectangle (450, 680, 700, 665);
    txRectangle (450, 550, 700, 525);
    txSetColor     (RGB (  0,   0,   0), 2);
    txLine (535, 663, 665, 663);
    txLine (533, 550, 667, 550);

    txSetColor     (RGB (255, 255, 0));
    txSetFillColor (RGB (255, 255, 0));
    POINT honey[8] = {{533, 549},
                      {667, 549},
                      {667, 545},
                      {660, 541},
                      {600, 535},
                      {540, 541},
                      {533, 545},
                      {533, 549}};
    txPolygon (honey, 8);

    txSetColor     (RGB (120, 34,  95), 2);
    txSetFillColor (RGB (208, 92, 175));
    txEllipse (300, 470, 500, 510);
    txEllipse (350, 480, 450, 500);
    txEllipse (700, 470, 900, 510);
    txEllipse (750, 480, 850, 500);

    txSetColor     (RGB (0, 0, 0));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (300 - 20*6, 360 + 8*6, 10*5);

    txSetColor     (TX_BLACK);
    txSelectFont   ("Bookman Old Style", 50);
    txTextOut      (100, 645, "И стали они жить дружно, мед кушать и сказки слушать...");
    }

//-----------------------------------------------------------------------------
void TeeDrink()
    {
    for (int countTeeDrink = 1; countTeeDrink < 3; countTeeDrink++)
        {
        CupMove(390, -5);
        txPlaySound ("teeDrink.wav");
        txSleep (300);
        CupMove(260, +5);

        txSleep (600);
        }
     }

//-----------------------------------------------------------------------------
void CupMove(int cupX, int step)
    {
     while (cupX >= 260 and cupX <=390)
        {
        ClearScreen(TX_BLACK);

        HomeBackground (90);
        BearHeadDraw (300, 350, 6);
        BeeHeadDraw  (900, 400, 5);
        TableDraw ();

        CupTee (400 - (390-cupX)/3, cupX + 50,  1);
        BearPawRight(cupX);

        CupTee (800 + (390-cupX)/3, 440 - (390-cupX)/2, -1);
        BeePawLeft (cupX);
        txSleep (100);

        cupX += step;
        }

    }
//-----------------------------------------------------------------------------
void BearPawRight(int y)
    {
    txSetColor     (RGB (0, 0, 0));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (515 - (390-y)/3, y + 48, 50);
    }
//-----------------------------------------------------------------------------
void BeePawLeft(int y)
    {
    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (50, 50, 0),2);
    txCircle (690 + (390-y)/3, 438 - (390-y)/2, 40);
    }

//----------------------------------------------------------------------------
void BeeHomeFinishDraw (int x, int y, double size)
    {
    txSetFillColor (RGB (252, 252, 108));
    txSetColor     (RGB (252, 252, 108),2);
    txEllipse   (x + 2*size, y - 8*size, x + 38*size, y + 12*size);

    txSetFillColor (RGB (215, 210, 190));
    txSetColor     (RGB (102, 98, 80),2);

    txRectangle (x,           y,           x + 40*size, y + 35*size);
    txRectangle (x,           y +  5*size, x -  5*size, y - 35*size);
    txRectangle (x +  5*size, y + 35*size, x + 10*size, y + 40*size);
    txRectangle (x + 30*size, y + 35*size, x + 35*size, y + 40*size);

    txSetFillColor (RGB (102, 98, 80));
    txRectangle (x + 10*size, y + 30*size, x + 30*size, y + 27*size);
    txCircle    (x + 20*size, y + 20*size, 3*size);
    }

//{===========================================================================
//!     НОВАЯ СЦЕНА С ИСПОЛЬЗОВАНИЕМ БИБЛИОТЕКИ Игоря Бочкарева
//!
//! персонажи: солнце, дерево, летающая тарелка, мужчина
//}===========================================================================

void BivenScreen ()
    {
    ClearScreen(RGB (0, 0, 0));

    SunShines (600);
    StarShipFly ();
    ManGo ();
    BuyAndSell ();
    ManGoAgain ();
    StarShipFlyAgain ();
    NewForest ();

    ClearScreen(TX_BLACK);

    TitleFrameDraw (50);

    SubTitlesDraw (400, 300, 100, "Bookman Old Style", TX_YELLOW, "К О Н Е Ц");
    txSleep (500);
    }
//---------------------------------------------------------------------------
void SunShines (int tSleep)
    {
    int t = 0;
    while (t <= 4)
        {
        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "Однажды на полянку около теремка...");

        ForestDraw  (0);
        HomeDraw    (800, 350, 150, 160, 90, 0.7);

        Biven::SunDraw (1100, 100, 1.8, 0.5+t%2*0.5, 1- t%2*0.5, 1, 1, 1, 1, 1);
        t += 1;

        if (tSleep != 0)
            txSleep (tSleep);

        ClearScreen(RGB (0, 0, 0));
        }
    }

//---------------------------------------------------------------------------
void StarShipFly ()
    {
    int t = 10;
    while (t <= 280)
        {
        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "Прилетел инопланетный корабль...");

        ForestDraw (0);
        HomeDraw (800, 350, 150, 160, 90, 0.7);
        BearDraw (765, 395, 2.0, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);

        Biven::SunDraw (1100, 100, 1.8, 0.5+t%2*0.5, 1- t%2*0.5, 1, 1, 1, 1, 1);
        Biven::StarShip (20 + t, 20 + t , 0.1 + t*0.005);
        t += 10;

        txSleep (200);

        ClearScreen(RGB (0, 0, 0));
        }
    }

//---------------------------------------------------------------------------
void ManGo ()
    {
    int t = 0;
    while (t <= 180)
        {
        ClearScreen(RGB (0, 0, 0));

        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "Прослышали инопланетяне про чудесный медок и решили произвести обмен...");

        ForestDraw (0);
        HomeDraw (800, 350, 150, 160, 90, 0.7);
        Biven::SunDraw (1100, 100, 1.8, 0.5 + t%2*0.5, 1 - t%2*0.5, 1, 1, 1, 1, 1);
        Biven::StarShip (300, 300, 0.1 + 280*0.005);

        BarrelDraw (650, 500, 0.7);
        BearDraw (765, 395, 2.0, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);

        if (t % 2)
            Biven::BoyDraw (400 + t, 350, 4, 4, 0,
                 -5, +5, 1, 5,
                  1,  1, 1, 1);
        else
            Biven::BoyDraw (400 + t, 350, 4, 4, 0,
                   1,  1, 1, 1,
                  +5, +5, 1, 5);

        Biven::TreeDraw (350 + t, 400, 1, 2);

        t += 15;
        txSleep (600);
        }
    }

//---------------------------------------------------------------------------
void BuyAndSell ()
    {
    int t = 0;
    while (t <= 170)
        {
        ClearScreen(RGB (0, 0, 0));

        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "Мед на чудечные деревья со своей планеты...");

        ForestDraw (0);
        HomeDraw (800, 350, 150, 160, 90, 0.7);
        Biven::SunDraw (1100, 100, 1.8, 0.5 + t%2*0.5, 1 - t%2*0.5, 1, 1, 1, 1, 1);
        Biven::StarShip (300, 300, 0.1 + 280*0.005);

        BarrelDraw (650 - t*0.3, 500 - t*0.2, 0.7 - t*0.0005);

        BearDraw (765, 395, 2.0, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);
        Biven::BoyDraw (400 + 180, 350, 4, 4, 0,
                        1, 1, 1, 1,
                        1, 1, 1, 1);

        Biven::TreeDraw (350 + 180 + t, ROUND(400 + t*0.5) , 1 + t*0.002, 2 + t*0.008);

        t += 15;
        txSleep (500);
        }
    }

//---------------------------------------------------------------------------
void ManGoAgain ()
    {
    int t = 0;
    while (t <= 180)
        {
        ClearScreen(RGB (0, 0, 0));

        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "Счастливые гости возвращаются обратно...");

        ForestDraw (0);
        HomeDraw (800, 350, 150, 160, 90, 0.7);
        Biven::SunDraw (1100, 100, 1.8, 0.5 + t%2*0.25, 1 - t%2*0.5, 1, 1, 1, 1, 1);
        Biven::StarShip (300, 300, 0.1 + 280*0.005);

        BearDraw (765, 395, 2.0, TX_YELLOW, 0 + t%2, 1 + t%2*0.25, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);
        Biven::TreeDraw (350 + 180 + 165, 482 , 1 + 165*0.002, 2 + 165*0.008);

        if (t % 2)
            Biven::BoyDraw (400 + 180 - t, 350, 4, 4, 0,
                  1,  1, 1, 1,
                 -5, +5, 1, 5);
        else
            Biven::BoyDraw (400 + 180 - t, 350, 4, 4, 0,
                   +5, +5, 1, 5,
                    1,  1, 1, 1);

        BarrelDraw (650 - 165*0.3 - t, 500 - 165*0.2, 0.7 - 165*0.0005);

        t += 15;
        txSleep (600);
        }
    }

//---------------------------------------------------------------------------
void StarShipFlyAgain ()
    {
    int t = 280;
    while (t >= 10)
        {
        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "Гости улетели... Мишка долго махал им лапой...");

        ForestDraw (0);
        HomeDraw (800, 350, 150, 160, 90, 0.7);
        BearDraw (765, 395, 2.0, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25 + (t%2)*5, 0 + (t%2)*5, 21, 47, 19, 47);
        Biven::TreeDraw (350 + 180 + 165, 482, 1 + 165*0.002, 2 + 165*0.008);

        Biven::SunDraw (1100, 100, 1.8, 0.5+t%2*0.5, 1- t%2*0.5, 1, 1, 1, 1, 1);
        Biven::StarShip (20 + t, 20 + t , 0.1 + t*0.005);
        t -= 11;

        txSleep (200);

        ClearScreen(RGB (0, 0, 0));
        }
    }
//---------------------------------------------------------------------------
void NewForest ()
    {
    int t = 10;
    while (t <= 200)
        {
        ClearScreen(RGB (0, 0, 0));

        SubTitlesDraw (180, 630, 30, "Bookman Old Style", TX_YELLOW, "А подаренные деревца разрослись, напоминая о необычных гостях...");

        ForestDraw (0);
        HomeDraw (800, 350, 150, 160, 90, 0.7);
        GladeDraw   (0);
        Biven::SunDraw (1100, 100, 1.8, 0.5+t%2*0.5, 1- t%2*0.5, 1, 1, 1, 1, 1);

        Biven::TreeDraw ( 50, 690, 1.33 + t*0.001, 3.32 + t*0.005);
        Biven::TreeDraw (250, 620, 1.33 + t*0.003, 3.32 + t*0.003);
        Biven::TreeDraw (100, 550, 1.33 + t*0.005, 3.32 + t*0.001);
        Biven::TreeDraw (170, 650, 1.33 + t*0.008, 3.32 + t*0.001);

        t += 10;

        txSleep (100);
        }
    txSleep (100);
    }
