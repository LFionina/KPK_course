# include "TXLib.h"
#include <stdlib.h>

void TitleScreen    ();
void TitleFrameDraw (int x);
void TitleTextDraw  (int t);

void BeginScreen    ();
void ForestDraw     (int t);
void GladeDraw      (int t);
void SubtitlesDraw  (char text[]);
void BackGroundDrawBeginScreen ();

void CenterScreen   ();
void BackGroundCenterScreen ();
void BearMove ();
void BearNoseEvesMove ();




void BeeFly         (int x, int y, double size);

void ForeGroundDraw ();


void BearDraw (int x     , int y, double size,
               COLORREF colorEye, double dBetweenEyes, double radiusEyes,
               int noseY ,
               int dBetweenEars,
               int dChestMove,
               int lHandX, int lHandY,
               int rHandX, int rHandY,
               int lFoodX, int lFoodY,
               int rFoodX, int rFoodY);

void TreeOneDraw (int x,  int y, double size,
                  double inclineX,
                  int widthTree, int heigthTree,
                  int pxLine   , int colorLine , int colorTree);



void HomeDraw    (int x, int y, int heightRoof,
                  int widthWindow, int heightWindow,
                  double size);

void FlowerDraw  (int x, int y, double size,
                  COLORREF colorPetal, COLORREF colorCenter);
void BushDraw    (int x, int y, double size);
void BeeDraw     (int x, int y, double size);
void BeeHomeDraw (int x, int y, double size);
void BarrelDraw  (int x, int y, double size);

//----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1200, 700);
    txBegin ();

    //TitleScreen ();

    //BeginScreen ();

    CenterScreen ();


    txEnd ();

    }

//============================================================================
void TitleScreen()
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txClear    ();

    TitleFrameDraw (50);

    int t = 0;
    while (t != 350)
        {
        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear        ();

        TitleFrameDraw (50);
        TitleTextDraw  (t);

        txSleep        (100);
        t += 50;
        }

    txSleep      (200);
    txSetColor   (TX_YELLOW);
    txSelectFont ("Bookman Old Style", 30);
    txTextOut    (350, 350, "����������� ����������� ���������� �����");
    txSleep      (500);

    txSetColor   (TX_WHITE);
    txSelectFont ("Monotype Corsiva", 30);
    txTextOut    (360, 450, "�����: ������� ������� (������, 2021)");
    txSleep      (1000);
    }

//----------------------------------------------------------------------------
void TitleFrameDraw (int x)
    {
    txSetColor     (TX_YELLOW, 3);
    txLine (       x,       x * 2,        x + 150,       x * 2);
    txLine (1200 - x,       x * 2, 1200 - x - 150,       x * 2);
    txLine (       x, 700 - x * 2,        x + 150, 700 - x * 2);
    txLine (1200 - x, 700 - x * 2, 1200 - x - 150, 700 - x * 2);

    txLine (       x * 2,       x,        x * 2,       x + 150);
    txLine (1200 - x * 2,       x, 1200 - x * 2,       x + 150);
    txLine (       x * 2, 700 - x,        x * 2, 700 - x - 150);
    txLine (1200 - x * 2, 700 - x, 1200 - x * 2, 700 - x - 150);

    txSetColor     (TX_LIGHTCYAN);
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
    txTextOut (             t, 250, "� � � � � � �");
    txTextOut (1200 - 260 - t, 250, "� � � � � � �");
    }
//============================================================================
void BeginScreen ()
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txClear        ();

    SubtitlesDraw  ("� ����� ����...");
    txSleep        (500);

    ForestDraw     (200);

    SubtitlesDraw  ("� ����� ����...  ����� �������...");
    txSleep        (500);

    HomeDraw       (800, 350, 150, 160, 90, 1);
    txSleep        (500);

    SubtitlesDraw  ("������ ������� �� ������� �������...");
    txSleep        (500);
    GladeDraw      (  0);
    txSleep        (500);

    SubtitlesDraw  ("������ ������, ����� ��������...");
    txSleep        (500);

    BeeFly  (150, 250, 1);




    }
//----------------------------------------------------------------------------
void ForestDraw (int t)
    {
    int i = 45;
    while (i<=700)
        {
        TreeOneDraw (50 + i, 50 + i%2*10, i%2 + 1, i%100/25 * 10, 50 + i%10, i%35 + 10, 2,  50, i%80);
        i += 75;
        txSleep(t);
        }
    }
//----------------------------------------------------------------------------
void GladeDraw (int t)
    {
    int stepBush = 210;
    while (stepBush <= 700)
        {
        BushDraw    (500 + stepBush, 350 + stepBush%2*10, stepBush%2 + 1 );
        stepBush += 75;
        txSleep(t);
        }

    for (int i = 1; i <= 5; i++)
        {
        FlowerDraw  (100 + i/2*70, 350, 1.3, TX_LIGHTMAGENTA, TX_ORANGE      );
        FlowerDraw  (140 + i/2*50, 380, 1  , TX_LIGHTCYAN   , TX_YELLOW      );
        FlowerDraw  ( 80 + i/2*90, 420, 1  , TX_YELLOW      , TX_LIGHTMAGENTA);
        FlowerDraw  (905 + i/2*95, 555, 1.5, TX_BLUE        , TX_ORANGE      );
        FlowerDraw  (900 + i/3*95, 600, 1  , TX_LIGHTMAGENTA, TX_ORANGE      );
        FlowerDraw  (800 + i/2*70, 570, 1.2, TX_WHITE       , TX_YELLOW      );
        }

    BeeHomeDraw (630, 450, 1);
    BeeHomeDraw (530, 480, 2);
    BeeHomeDraw (580, 510, 2);
    }
//----------------------------------------------------------------------------
void SubtitlesDraw  (char text[])
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle    (180, 590, 680, 655);
    txSetColor     (TX_YELLOW);
    txSelectFont   ("Bookman Old Style", 40);
    txTextOut      (190, 605, text);
    }
//----------------------------------------------------------------------------
void BeeFly (int x, int y, double size)
    {
    txBegin ();
    int step =  5;
    int t = 0;
    while (t <= 10)
        {
        BeeDraw        (x + step*t, y + step*(t%2), size);
        txSleep        (150);

        txSetFillColor (TX_BLACK);
        txClear        ();
        BackGroundDrawBeginScreen ();
        SubtitlesDraw  ("������ ������, ����� ��������...");

        t++;
        }
    txEnd();
    }
//============================================================================
void CenterScreen ()
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txClear        ();

    BackGroundCenterScreen ();
    //BearMove ();
    BearNoseEvesMove ();


    }


//----------------------------------------------------------------------------
void BackGroundCenterScreen ()
    {
    HomeDraw    (900, 250, 150, 160, 90, 0.7);
    ForestDraw  (0);

    BeeHomeDraw (300, 400, 1.5);
    BeeHomeDraw (200, 480, 2);
    BeeHomeDraw (380, 510, 3);

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
    while (t <= 50)
        {
        txSetFillColor (TX_BLACK);
        txClear  ();
        BackGroundCenterScreen ();

        BarrelDraw (850+25*sizeBear - t*5, 220+50*sizeBear + t*5, sizeBear/2);

        BearDraw   (850             - t*5, 220             + t*5, sizeBear, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 42 + t%10, 19, 47 - t%10);

        txSleep  (100);
        t += 5;
        sizeBear += 0.1;
        }

    txEnd();
    }

//----------------------------------------------------------------------------
void BearNoseEvesMove ()
    {
    txBegin ();
    int t = 0;
    BarrelDraw     (850 + 25*2.1 - 55*5, 220 + 50*2.1 + 55*5, 2.1/2);
    while (t <= 9)
        {
        BearDraw   (850          - 55*5, 220          + 55*5, 2.1, TX_YELLOW, 0, t%2 + 0.5, t%2 * 5, 30, 5, 25, 0, 25, 0, 21, 42 + 55%10, 19, 47 - 55%10);
        txSleep    (300);

        t += 1;
        }
    txEnd ();
    }

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------







//----------------------------------------------------------------------------


//+----------------------------------------------------------------------------
void BackGroundDrawBeginScreen ()
    {
    ForestDraw  (0);
    HomeDraw    (800, 350, 150, 160, 90, 1);
    GladeDraw   (0);
    }

//----------------------------------------------------------------------------
void ForeGroundDraw()
    {


    BeeHomeDraw (630, 450, 1);
    BeeHomeDraw (530, 480, 2);
    BeeHomeDraw (580, 510, 2);

    BeeDraw     (600, 530, 1  );

    FlowerDraw  (905, 555, 1.5, TX_BLUE,         TX_ORANGE);
    FlowerDraw  (900, 580, 1,   TX_LIGHTMAGENTA, TX_ORANGE);
    FlowerDraw  (800, 580, 1,   TX_WHITE,        TX_YELLOW);
    }
//----------------------------------------------------------------------------



//============================================================================
void BearDraw (int x, int y, double size,
               COLORREF colorEye, double dBetweenEyes, double radiusEyes,
               int noseY, int dBetweenEars, int dChestMove,
               int lHandX, int lHandY, int rHandX, int rHandY,
               int lFoodX, int lFoodY,int rFoodX, int rFoodY)
    {
    txSetColor (TX_WHITE);
    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - dBetweenEars/2*size, y - 43*size, 10*size);
    txCircle (x + dBetweenEars/2*size, y - 43*size, 10*size);
    txSetFillColor (RGB (238, 209, 111));
    txCircle (x - (dBetweenEars/2-1)*size, y - 42*size,  8*size);
    txCircle (x + (dBetweenEars/2-1)*size, y - 42*size,  8*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x,           y - 25*size, 25*size);

    txSetFillColor (colorEye);
    txCircle (x -  8*size+dBetweenEyes, y - 33*size,  4*size*radiusEyes);
    txCircle (x +  8*size+dBetweenEyes, y - 33*size,  4*size*radiusEyes);
    txSetFillColor (RGB (0, 0, 0));
    txCircle (x -  8*size+dBetweenEyes, y - 31*size,  2*size*radiusEyes);
    txCircle (x +  8*size+dBetweenEyes, y - 31*size,  2*size*radiusEyes);

    txSetColor     (RGB (0, 0, 0));
    txLine (x - 5*size, y - 25*size+noseY, x + 5*size, y - 25*size+noseY);
    txLine (x,          y - 20*size+noseY, x + 5*size, y - 25*size+noseY);
    txLine (x - 5*size, y - 25*size+noseY, x,          y - 20*size+noseY);
    txFloodFill (x, y - 23*size+noseY);

    txSetColor     (RGB (255, 0, 0));
    txArc (x - 10*size, y - 25*size, x + 10*size, y - 15*size, 200, 120);

    txSetColor     (RGB (255, 255, 255));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - lHandX*size, y + lHandY*size, 10*size);
    txCircle (x + rHandX*size, y + rHandY*size, 10*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - lFoodX*size, y + lFoodY*size, 10*size);
    txCircle (x + rFoodX*size, y + rFoodY*size, 10*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x,           y + 25*size, 25*size);
    txSetFillColor (RGB (238, 209, 111));
    txCircle (x,           y + 13*size+dChestMove, 13*size);
    }

//+----------------------------------------------------------------------------
void TreeOneDraw (int x, int y, double size, double inclineX, int widthTree, int heigthTree,
                  int pxLine, int colorLine, int colorTree)
    {
    txSetColor     (RGB (0, 255-colorLine, 0), pxLine);
    txSetFillColor (RGB (0, 255-colorTree, 0)        );
    txLine (x + inclineX           , y                      , x - widthTree/2*size, y + heigthTree*size  );
    txLine (x + inclineX           , y                      , x + widthTree/2*size, y + heigthTree*size  );
    txLine (x - widthTree/2*size   , y + heigthTree*size    , x + widthTree/2*size, y + heigthTree*size  );
    txFloodFill (x, y + heigthTree*size-5);

    txLine (x + inclineX/2           , y + heigthTree*size    , x - widthTree/2*size, y + heigthTree*2*size);
    txLine (x + inclineX/2           , y + heigthTree*size    , x + widthTree/2*size, y + heigthTree*2*size);
    txLine (x - widthTree/2*size   , y + heigthTree*2*size  , x + widthTree/2*size, y + heigthTree*2*size);
    txFloodFill (x, y + heigthTree/2*3*size);

    txLine (x + inclineX/4           , y + heigthTree*2*size  , x + widthTree/2*size, y + heigthTree*3*size);
    txLine (x + inclineX/4           , y + heigthTree*2*size  , x - widthTree/2*size, y + heigthTree*3*size);
    txLine (x - widthTree/2*size   , y + heigthTree*3*size  , x + widthTree/2*size, y + heigthTree*3*size);
    txFloodFill (x, y + heigthTree/2*5*size);

    txSetColor     (RGB (177, 101, 54));
    txSetFillColor (RGB (177, 101, 54));
    txRectangle (x - widthTree/5*size, y + heigthTree*3*size+1, x + widthTree/5*size, y + heigthTree*3*size+heigthTree/5);
    }

//+----------------------------------------------------------------------------
void BushDraw (int x, int y, double size)
    {
    txSetColor     (RGB (0, 245, 0), 2);
    txSetFillColor (RGB (0, 200, 0));
    txCircle (x - 10*size, y, 18*size);
    txCircle (x + 10*size, y, 18*size);

    txSetFillColor (RGB (0, 250, 0));
    txCircle (x,           y, 20*size);

    txSetColor     (RGB (177, 101, 54));
    txLine (x, y + 20*size, x,           y);
    txLine (x, y + 20*size, x - 10*size, y);
    txLine (x, y + 20*size, x + 10*size, y);
    }

//+----------------------------------------------------------------------------
void HomeDraw (int x, int y,    int heightRoof,
               int widthWindow, int heightWindow, double size)
    {
    txSetColor     (RGB (177, 137, 77));
    txSetFillColor (RGB (177, 137, 77));
    txRectangle (x, y           , x + 300*size, y -  30*size);
    txRectangle (x, y -  35*size, x + 300*size, y -  65*size);
    txRectangle (x, y -  70*size, x + 300*size, y - 100*size);
    txRectangle (x, y - 105*size, x + 300*size, y - 135*size);
    txRectangle (x, y - 140*size, x + 300*size, y - 170*size);

    txSetFillColor (RGB (105, 81, 45));
    txCircle (x +  20*size, y - 155*size, 18*size);
    txCircle (x + 280*size, y - 155*size, 18*size);
    txCircle (x +  20*size, y - 120*size, 18*size);
    txCircle (x + 280*size, y - 120*size, 18*size);
    txCircle (x +  20*size, y -  85*size, 18*size);
    txCircle (x + 280*size, y -  85*size, 18*size);
    txCircle (x +  20*size, y -  50*size, 18*size);
    txCircle (x + 280*size, y -  50*size, 18*size);
    txCircle (x +  20*size, y -  15*size, 18*size);
    txCircle (x + 280*size, y -  15*size, 18*size);

    txSetFillColor (RGB (114, 34, 54));
    POINT star[5] = {{x -  10*size, y - 175*size},
                     {x + 310*size, y - 175*size},
                     {x + 200*size, y - (175 + heightRoof)*size},
                     {x + 100*size, y - (175 + heightRoof)*size},
                     {x -  10*size, y - 175*size}};
    txPolygon (star, 5);
    txSetFillColor (RGB (105, 81, 45));

    txRectangle (x + 70*size, y - 130*size, x + (70+widthWindow)*size, y - (130-heightWindow)*size);
    txSetColor  (RGB (105, 81, 45));
    txCircle (x + (70+widthWindow/16/2)*size,             y - (130-heightWindow/9/2)*size             , widthWindow/16*size);
    txCircle (x + (70+widthWindow/2)*size,                y - (130-heightWindow/9/2)*size             , widthWindow/16*size);
    txCircle (x + (70+widthWindow-widthWindow/16/2)*size, y - (130-heightWindow/9/2)*size             , widthWindow/16*size);

    txCircle (x + (70+widthWindow/16/2)*size,             y - (130-heightWindow/2)*size               , widthWindow/16*size);
    txCircle (x + (70+widthWindow-widthWindow/16/2)*size, y - (130-heightWindow/2)*size               , widthWindow/16*size);

    txCircle (x + (70+widthWindow/16/2)*size,             y - (130-heightWindow+heightWindow/9/2)*size, widthWindow/16*size);
    txCircle (x + (70+widthWindow/2)*size,                y - (130-heightWindow+heightWindow/9/2)*size, widthWindow/16*size);
    txCircle (x + (70+widthWindow-widthWindow/16/2)*size, y - (130-heightWindow+heightWindow/9/2)*size, widthWindow/16*size);
    txSetFillColor (RGB (185, 235, 225));


    txRectangle (x + (70+widthWindow/16)*size                , y - (130-heightWindow/9)*size                 , x + (70+widthWindow/2-widthWindow/16/2)*size, y - (130-heightWindow/2+heightWindow/9/2)*size);
    txRectangle (x + (70+widthWindow/16)*size                , y - (130-heightWindow/2-heightWindow/9/2)*size, x + (70+widthWindow/2-widthWindow/16/2)*size, y - (130-heightWindow  +heightWindow/9)*size  );
    txRectangle (x + (70+widthWindow/2+widthWindow/16/2)*size, y - (130-heightWindow/9)*size                 , x + (70+widthWindow  -widthWindow/16)*size  , y - (130-heightWindow/2+heightWindow/9/2)*size);
    txRectangle (x + (70+widthWindow/2+widthWindow/16/2)*size, y - (130-heightWindow/2-heightWindow/9/2)*size, x + (70+widthWindow  -widthWindow/16)*size  , y - (130-heightWindow  +heightWindow/9)*size  );
    }

//+----------------------------------------------------------------------------
void BeeDraw (int x,int y, double size)
    {
    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (255, 255, 0),3);
    txCircle  (x         ,  y - 5*size, 5*size);
    txEllipse (x - 5*size,  y         , x + 5*size, y + 15*size);

    txSetColor     (RGB (255, 255, 0),2*size);
    txLine (x -  4*size, y +  5*size, x +  4*size, y +  5*size);
    txLine (x -  4*size, y + 10*size, x +  4*size, y + 10*size);

    txSetFillColor (RGB (185, 235, 225));
    txSetColor     (RGB (50, 50, 0),2);
    txEllipse (x - 15*size, y, x,          y +  6*size);
    txEllipse (x + 15*size, y, x,          y +  6*size);
    }

//+----------------------------------------------------------------------------
void BeeHomeDraw (int x, int y, double size)
    {
    txSetFillColor (RGB (215, 210, 190));
    txSetColor     (RGB (102, 98, 80),2);
    txRectangle (x,           y,           x + 40*size, y + 35*size);
    txRectangle (x -  5*size, y,           x + 45*size, y -  5*size);
    txRectangle (x +  5*size, y + 35*size, x + 10*size, y + 40*size);
    txRectangle (x + 30*size, y + 35*size, x + 35*size, y + 40*size);

    txSetFillColor (RGB (102, 98, 80));
    txRectangle (x + 10*size, y + 30*size, x + 30*size, y + 27*size);
    txCircle    (x + 20*size, y + 20*size, 3*size);
    }

//+----------------------------------------------------------------------------
void FlowerDraw (int x, int y, double size, COLORREF colorPetal, COLORREF colorCenter)
    {
    txSetFillColor (RGB (12, 118, 30));
    txSetColor     (RGB (12, 118, 30),2);
    txEllipse (x - 13*size, y -  3*size, x + 13*size, y +  3*size);
    txLine    (x,           y,           x,           y - 48*size);
    txSetFillColor (RGB (20, 198, 50));
    txEllipse (x - 13*size, y - 23*size, x,           y - 20*size);
    txEllipse (x + 13*size, y - 13*size, x,           y - 10*size);

    txSetColor     (RGB (250, 220, 240));
    txSetFillColor (colorPetal);
    txCircle (x,           y - 43*size, 5*size);

    txSetFillColor (colorPetal);
    txCircle (x,           y - 60*size, 5*size);

    txSetFillColor (colorPetal);
    txCircle (x -  8*size, y - 48*size, 5*size);

    txSetFillColor (colorPetal);
    txCircle (x +  8*size, y - 48*size, 5*size);

    txSetFillColor (colorPetal);
    txCircle (x -  8*size, y - 55*size, 5*size);

    txSetFillColor (colorPetal);
    txCircle (x +  8*size, y - 55*size, 5*size);

    txSetFillColor (colorCenter);
    txCircle (x,           y - 51*size, 6*size);
    }

//+----------------------------------------------------------------------------
void BarrelDraw (int x, int y, double size)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (255, 204, 102));
    txEllipse   (x          , y            , x + 100*size       , y - 100*size       );
    txEllipse   (x + 20*size, y            , x + (100 - 20)*size, y - 100*size       );
    txEllipse   (x + 40*size, y            , x + (100 - 40)*size, y - 100*size       );
    txSetFillColor (TX_BLACK);
    txRectangle (x          , y            , x + 100*size       , y - 15*size        );
    txRectangle (x          , y - 100*size , x + 100*size       , y - (100 - 15)*size);
    }
