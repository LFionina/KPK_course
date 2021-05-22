//{-----------------------------------------------------------------------------
//!@file       mult_DANCE.cpp
//!
//!            МУЛЬТФИЛЬМ  "ТАНЦЫ"
//!     с использованием сторонних библиотек:
//!    Детковой Людмилы, Бочкарева Игоря, Абрамовой Ирины
//!
//!@author  (C) Фионина Людмила Евгеньевна, г. Самара,
//!@date          2021
//!
//}-----------------------------------------------------------------------------

#include "TXLib.h"
#include "DetkovaLASDK\DetkovaLALib.h"
#include "LFioninaSDK\LFioninaLib.h"
#include "AbramovaSDK\LibIra.h"
#include "Include\BivenLib.h"

void TopFoot ();
void MoveBoyGirl ();
void Jumping ();
void MoveBack ();

void DanceMousesCat ();
void JumpingMousesCat ();
void MoveMousesCat ();
void DansingAll ();

void FonOne ();

//-----------------------------------------------------------------------------

int main ()
    {
    txCreateWindow (1200, 700);

    SpringFonBegining ();

    txPlaySound ("Sounds/changa1.wav");

    TopFoot ();
    MoveBoyGirl ();

    txSleep(500);

    Jumping ();
    MoveBack ();
    txSleep(500);
    txPlaySound (NULL);

    txPlaySound ("Sounds/changa2.wav");
    DanceMousesCat ();
    JumpingMousesCat ();
    txSleep(500);

    MoveMousesCat ();
    DansingAll ();

    return 0;
    }

//-----------------------------------------------------------------------------
void TopFoot()
    {
    int t = 0;
    while (t <= 20)
        {
        txSleep(280);
        SpringFonBegining ();

        Biven::TreeDraw ( 150, 400, 1.33 + t*0.1, 3.32 + t*0.05);
        Biven::TreeDraw ( 100, 550, 1.33 + t*0.05, 3.32 + t*0.01);
        Biven::TreeDraw (1050, 400, 1.33 + t*0.1, 3.32 + t*0.05);
        Biven::TreeDraw (1100, 550, 1.33 + t*0.05, 3.32 + t*0.01);

        DrawGirl (300, 370,
                        2,          //размер по Х
                        2,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_PINK,    //цвет платья
                        1 + t%2*20,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1 - t%2*20,          //высота кисти левой руки
                        1,          //расстояние между пятками
                        1,          //double crazy,
                        1,          //double smile,
                        1,          //double eyes,
                        1 + t%2*20,          //double platie,
                        1 + t%2*20,          //double topleftleg,
                        1,          //double toprightleg,
                        1,          //double nos,
                        1);         //double hear) ;

         DrawBoy (900, 370,
                        2,          //размер по Х
                        2,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_ORANGE,  //цвет торса
                        1 + (t%3-1)*20,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1 - (t%3-1)*20,          //высота кисти левой руки
                        1, // double legs,
                        1, //double crazy,
                        1, //double smile,
                        1, //int eyes,
                        1, //double topleftleg,
                        1 - (t%3-2)*10, //double toprightleg,
                        1, //double nos,
                        1, // double hear,
                        1); //double brovy);


         t += 1;
         }
    }

//-----------------------------------------------------------------------------
void MoveBoyGirl ()
    {
    int t = 0;
    while (t <= 20)
        {
        txSleep(280);
        SpringFonBegining ();

        Biven::TreeDraw ( 150, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw ( 100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);
        Biven::TreeDraw (1050, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw (1100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);

        DrawGirl (300 + t*10, 370,
                        2,          //размер по Х
                        2,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_PINK,    //цвет платья
                        1 + t%2*20,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1 + t%2*20,          //высота кисти левой руки
                        1 + t%2*20,          //расстояние между пятками
                        1,          //double crazy,
                        1,          //double smile,
                        1,          //double eyes,
                        1 + t%2*20,          //double platie,
                        1,          //double topleftleg,
                        1,          //double toprightleg,
                        1,          //double nos,
                        1);         //double hear) ;

         DrawBoy (900 - t*10, 370,
                        2,          //размер по Х
                        2,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_ORANGE,  //цвет торса
                        1 + (t%3-1)*20,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1 - (t%3-1)*20,          //высота кисти левой руки
                        1 + t%2*20, // double legs,
                        1, //double crazy,
                        1, //double smile,
                        1, //int eyes,
                        1, //double topleftleg,
                        1, //double toprightleg,
                        1, //double nos,
                        1, // double hear,
                        1); //double brovy);

         t += 1;
         }
    }
//-----------------------------------------------------------------------------
void Jumping ()
    {
    int t = 0;
    while (t <= 40)
        {
        txSleep(200);
        SpringFonBegining ();

        Biven::TreeDraw ( 150, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw ( 100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);
        Biven::TreeDraw (1050, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw (1100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);

        DrawGirl (300 + 20*10, 370 - t%2*30,
                        2,          //размер по Х
                        2,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_PINK,    //цвет платья
                        1 + t%2*20,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1 + t%2*20,          //высота кисти левой руки
                        1,          //расстояние между пятками
                        1,          //double crazy,
                        1,          //double smile,
                        1,          //double eyes,
                        1,          //double platie,
                        1 + t%2*20,          //double topleftleg,
                        1 + t%2*20,          //double toprightleg,
                        1,          //double nos,
                        1);         //double hear) ;

         DrawBoy (900 - 20*10, 370 - t%2*30,
                        2,          //размер по Х
                        2,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_ORANGE,  //цвет торса
                        1,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1,          //высота кисти левой руки
                        1, // double legs,
                        1, //double crazy,
                        1, //double smile,
                        1, //int eyes,
                        1 + t%2*20, //double topleftleg,
                        1 + t%2*20, //double toprightleg,
                        1, //double nos,
                        1, // double hear,
                        1); //double brovy);

         t += 1;
         }
    }

//-----------------------------------------------------------------------------
void MoveBack ()
    {
    int t = 0;
    while (t <= 10)
        {
        txSleep(200);
        SpringFonBegining ();

        Biven::TreeDraw ( 150, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw ( 100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);
        Biven::TreeDraw (1050, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw (1100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);

        DrawGirl (500 + t%2*10, 310 - t%2*3,
                        2 - t*0.1,          //размер по Х
                        2 - t*0.1,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_PINK,    //цвет платья
                        1,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1,          //высота кисти левой руки
                        1,          //расстояние между пятками
                        1,          //double crazy,
                        1,          //double smile,
                        1,          //double eyes,
                        1,          //double platie,
                        1,          //double topleftleg,
                        1,          //double toprightleg,
                        1,          //double nos,
                        1);         //double hear) ;

         DrawBoy (700 - t%2*10, 310 - t%2*3,
                        2 - t*0.1,          //размер по Х
                        2 - t*0.1,          //размет по Y
                        TX_YELLOW,  //цвет лица
                        TX_BLUE,    //цвет волос
                        TX_ORANGE,  //цвет торса
                        1,          //высота кисти правой руки  +20 ниже  - 20 выше
                        1,          //высота кисти левой руки
                        1, // double legs,
                        1, //double crazy,
                        1, //double smile,
                        1, //int eyes,
                        1, //double topleftleg,
                        1, //double toprightleg,
                        1, //double nos,
                        1, // double hear,
                        1); //double brovy);

         t += 1;
         }

    int MouseX = 300;
    while (MouseX <= 1000)
        {
        Mouse_twerk (MouseX, 600, 0.5, 0.5, 1, 20);
        txSleep(450);
        MouseX += 200;
        }

    CatBody_draw (400, 400, 1, 1, 1, TX_ORANGE, TX_YELLOW);
    CatBody_draw (800, 400, 1, 1, 1, TX_DARKGRAY, TX_GRAY);
    }

//-----------------------------------------------------------------------------
void DanceMousesCat ()
    {
    int t = 0;
    int direction = 1;
    while (t <= 27)
        {
        FonOne ();

        if (t%5 == 0)
            {direction *= (-1); }

        CatBody_draw (400 + direction*(t%5)*30, 400, 1, 1, 1 + t%2*5, TX_ORANGE, TX_YELLOW);
        CatBody_draw (800 + direction*(t%5)*30, 400, 1, 1, 1 + t%2*5, TX_DARKGRAY, TX_GRAY );

        Mouse_twerk (300, 600 + (t%2-1)*30, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (500, 600 + (t%2  )*30, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (700, 600 + (t%2-1)*30, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (900, 600 + (t%2  )*30, 0.5, 0.5, 1, 20*direction);

        t +=1;
        }
      }

//-----------------------------------------------------------------------------
void JumpingMousesCat ()
    {
    int t = 0;
    int direction = 1;
    while (t <= 28)
        {
        FonOne ();

        if (t%5 == 0)
            {direction *= (-1); }

        CatBody_draw (400, 400 + t%2*30, 1, 1, 1 + t%2*5, TX_ORANGE, TX_YELLOW);
        CatBody_draw (800, 400 - t%2*30, 1, 1, 1 + t%2*5, TX_DARKGRAY, TX_GRAY);

        Mouse_twerk (300, 600 + (t%2-1)*30, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (500, 600 + (t%2  )*30, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (700, 600 + (t%2-1)*30, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (900, 600 + (t%2  )*30, 0.5, 0.5, 1, 20*direction);

        t +=1;
        }
      }

//-----------------------------------------------------------------------------
void MoveMousesCat ()
    {
    int t = 0;
    int direction = 1;
    while (t <= 32)
        {
        FonOne ();

        if (t%5 == 0)
            {direction *= (-1); }

        CatBody_draw (400 - t*5, 400, 1 - t*0.01, 1 - t*0.01, 1, TX_ORANGE, TX_YELLOW);
        CatBody_draw (800 + t*5, 400, 1 - t*0.01, 1 - t*0.01, 1, TX_DARKGRAY, TX_GRAY);

        BearDraw (600, 430 + (t%2)*20, 2.5, TX_CYAN, 0, 1, 0, 30 + (t%2-1)*5, 5 + t%2*5,
                  25 + t%3*3, 0, 25 - t%3*3, 0,
                  18, 47 + t%3*3, 18, 53 - t%3*3);

        BeeDraw (500, 400 + t%3*5, 1);
        BeeDraw (400, 500 + t%3*5, 1.2);
        BeeDraw (800, 500 + t%3*5, 1.5);
        BeeDraw (750, 450 + t%3*5, 1);
        BeeDraw (700, 500 + t%3*5, 1.5);

        Mouse_twerk (300 - t*5, 570, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (500 - t*5, 600, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (700 + t*5, 570, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (900 + t*5, 600, 0.5, 0.5, 1, 20*direction);

        t +=1;
        }
      }

//-----------------------------------------------------------------------------
void DansingAll ()
    {
    int t = 0;
    int direction = 1;
    while (t <= 32)
        {
        txSleep(200);
        SpringFonBegining ();

        Biven::TreeDraw ( 150, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw ( 100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);
        Biven::TreeDraw (1050, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
        Biven::TreeDraw (1100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);

        DrawGirl (500 + 10%2*10, 310 - t%2*20, 2 - 10*0.1, 2 - 10*0.1,
              TX_YELLOW, TX_BLUE, TX_PINK,
              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

        DrawBoy  (700 - 10%2*10, 310 - t%3*20, 2 - 10*0.1, 2 - 10*0.1,
              TX_YELLOW, TX_BLUE, TX_ORANGE,
              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

        CatBody_draw (400 - 32*5, 400 - t%2*20, 1 - 32*0.01, 1 - 32*0.01, 1, TX_ORANGE, TX_YELLOW);
        CatBody_draw (800 + 32*5, 400 + t%2*20, 1 - 32*0.01, 1 - 32*0.01, 1, TX_DARKGRAY, TX_GRAY);

        BearDraw (600, 430 + (t%2)*30, 2.5, TX_CYAN, 0, 1, 0, 30 + (t%2-1)*5, 5,
                  25 + t%3*3, 0, 25 - t%3*3, 0,
                  18, 47 + 32%3*3, 18, 53 - 32%3*3);

        BeeDraw (500, 400 + t%3*5, 1);
        BeeDraw (400, 500 + t%3*5, 1.2);
        BeeDraw (800, 500 + t%3*5, 1.5);
        BeeDraw (750, 450 + t%3*5, 1);
        BeeDraw (700, 500 + t%3*5, 1.5);

        Mouse_twerk (300 - 32*5, 570 + t%2*20, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (500 - 32*5, 600 - t%2*20, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (700 + 32*5, 570 + t%2*20, 0.5, 0.5, 1, 20*direction);
        Mouse_twerk (900 + 32*5, 600 - t%2*20, 0.5, 0.5, 1, 20*direction);

        if (t%5 == 0)
            {direction *= (-1); }



        t +=1;
        }
      }

//================================+++++++++++==================================
void FonOne ()
    {
    txSleep(200);
    SpringFonBegining ();

    Biven::TreeDraw ( 150, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
    Biven::TreeDraw ( 100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);
    Biven::TreeDraw (1050, 400, 1.33 + 20*0.1,  3.32 + 20*0.05);
    Biven::TreeDraw (1100, 550, 1.33 + 20*0.05, 3.32 + 20*0.01);

    DrawGirl (500 + 10%2*10, 310 - 10%2*3, 2 - 10*0.1, 2 - 10*0.1,
              TX_YELLOW, TX_BLUE, TX_PINK,
              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);

    DrawBoy  (700 - 10%2*10, 310 - 10%2*3, 2 - 10*0.1, 2 - 10*0.1,
              TX_YELLOW, TX_BLUE, TX_ORANGE,
              1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    }
