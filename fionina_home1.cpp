# include "TXLib.h"
#include <stdlib.h>

void bearDraw();
void treeOneDraw();
void bushDraw();
void homeDraw();
void beeDraw();
void beeHomeDraw();
void flowerDraw();

int main()
    {
    txCreateWindow (1000, 600);

    bearDraw();
    treeOneDraw();
    bushDraw();
    homeDraw();
    beeDraw();
    beeHomeDraw();
    flowerDraw();

    return 0;
    }

void bearDraw()
    {
    txSetFillColor (RGB (177, 101, 54));

    txCircle (670, 165, 20);

    txCircle (730, 165, 20);

    txSetFillColor (RGB (238, 209, 111));

    txCircle (672, 167, 15);

    txCircle (728, 167, 15);

    txSetFillColor (RGB (177, 101, 54));

    txCircle (700, 200, 50);

    txSetFillColor (RGB (238, 209, 111));

    txCircle (685, 185, 8);

    txCircle (715, 185, 8);

    txSetFillColor (RGB (0, 0, 0));

    txCircle (685, 187, 4);

    txCircle (715, 187, 4);

    txSetColor (RGB (0, 0, 0));

    txLine(690, 200, 710, 200);

    txLine(700, 210, 710, 200);

    txLine(690, 200, 700, 210);

    txSetColor (RGB (255, 0, 0));

    txArc (680, 200, 720, 220, 200, 120);

    txSetColor (RGB (255, 255, 255));

    txSetFillColor (RGB (177, 101, 54));

    txCircle (660, 265, 20);

    txCircle (740, 265, 20);

    txSetFillColor (RGB (177, 101, 54));

    txCircle (670, 345, 20);

    txCircle (730, 345, 20);

    txSetFillColor (RGB (177, 101, 54));

    txCircle (700, 300, 50);

    txSetFillColor (RGB (238, 209, 111));

    txCircle (700, 275, 25);
    }

void treeOneDraw()
    {
    txSetColor (RGB (0, 255, 0));

    txSetFillColor (RGB (0, 255, 0));

    txLine (250, 50, 200, 100);

    txLine (200, 100, 300, 100);

    txLine (300, 100, 250, 50);

    txFloodFill (250, 80);

    txLine (250, 100, 200, 150);

    txLine (200, 150, 300, 150);

    txLine (300, 150, 250, 100);

    txFloodFill (250, 130);

    txLine (250, 150, 200, 200);

    txLine (200, 200, 300, 200);

    txLine (300, 200, 250, 150);

    txFloodFill (250, 180);

    txSetColor (RGB (177, 101, 54));

    txSetFillColor (RGB (177, 101, 54));

    txRectangle(240, 200, 260, 210);
    }

 void bushDraw()
    {
    txSetColor (RGB (0, 245, 0));

    txSetFillColor (RGB (0, 200, 0));

    txCircle (480, 350, 35);

    txSetFillColor (RGB (0, 200, 0));

    txCircle (520, 350, 35);

    txSetFillColor (RGB (0, 250, 0));

    txCircle (500, 350, 40);

    txSetColor (RGB (177, 101, 54));

    txLine (500, 390, 500, 350);

    txLine (500, 390, 480, 350);

    txLine (500, 390, 520, 350);

    }

void homeDraw()
    {
    txSetColor (RGB (177, 137, 77));

    txSetFillColor (RGB (177, 137, 77));

    txRectangle (50, 580, 350, 550);

    txRectangle (50, 545, 350, 515);

    txRectangle (50, 510, 350, 480);

    txRectangle (50, 475, 350, 445);

    txRectangle (50, 440, 350, 410);

    txSetFillColor (RGB (105, 81, 45));

    txCircle (70, 425, 18);

    txCircle (330, 425, 18);

    txCircle (70, 460, 18);

    txCircle (330, 460, 18);

    txCircle (70, 495, 18);

    txCircle (330, 495, 18);

    txCircle (70, 530, 18);

    txCircle (330, 530, 18);

    txCircle (70, 565, 18);

    txCircle (330, 565, 18);

    txSetFillColor (RGB (114, 34, 54));

    POINT star[5] = {{40, 405}, {360, 405}, {250, 305}, {150, 305}, {40, 405}};

    txPolygon (star, 5);

    txSetFillColor (RGB (105, 81, 45));

    txRectangle (120, 450, 280, 540);

    txSetColor (RGB (105, 81, 45));

    txCircle (125, 455, 10);

    txCircle (200, 455, 10);

    txCircle (275, 455, 10);

    txCircle (125, 535, 10);

    txCircle (200, 535, 10);

    txCircle (275, 535, 10);

    txCircle (125, 495, 10);

    txCircle (275, 495, 10);

    txSetFillColor (RGB (185, 235, 225));

    txRectangle (130, 460, 195, 490);

    txRectangle (130, 500, 195, 530);

    txRectangle (205, 460, 270, 490);

    txRectangle (205, 500, 270, 530);
    }

void beeDraw()
    {
    txSetFillColor (RGB (30, 30, 0));

    txSetColor (RGB (255, 255, 0),3);

    txCircle (800, 500, 10);

    txEllipse (790, 510, 810, 540);

    txSetColor (RGB (255, 255, 0),5);

    txLine (792, 520, 807, 520);

    txLine (792, 530, 807, 530);

    txSetFillColor (RGB (185, 235, 225));

    txSetColor (RGB (50, 50, 0),2);

    txEllipse (770, 510, 800, 520);

    txEllipse (830, 510, 800, 520);
    }

void beeHomeDraw()
    {
    txSetFillColor (RGB (215, 210, 190));

    txSetColor (RGB (102, 98, 80),2);

    txRectangle (520, 490, 600, 560);

    txRectangle (510, 490, 610, 480);

    txRectangle (530, 560, 540, 570);

    txRectangle (580, 560, 590, 570);

    txRectangle (540, 550, 580, 545);

    txSetFillColor (RGB (102, 98, 80));

    txCircle (560, 530, 6);
    }

void flowerDraw()
    {
    txSetFillColor (RGB (12, 118, 30));

    txSetColor (RGB (12, 118, 30),2);

    txEllipse (900, 580, 950, 590);

    txLine (925, 585, 925, 490);

    txSetFillColor (RGB (20, 198, 50));

    txEllipse (900, 540, 925, 530);

    txEllipse (950, 560, 925, 570);

    txSetColor (RGB (250, 220, 240));

    txSetFillColor (RGB (225, 31, 183));

    txCircle (925, 500, 10);

    txSetFillColor (RGB (129, 31, 206));

    txCircle (925, 465, 10);

    txSetFillColor (RGB (78, 203, 232));

    txCircle (910, 490, 10);

    txSetFillColor (RGB (225, 31, 183));

    txCircle (940, 490, 10);

    txSetFillColor (RGB (225, 31, 183));

    txCircle (910, 475, 10);

    txSetFillColor (RGB (121, 98, 186));

    txCircle (940, 475, 10);

    txSetFillColor (RGB (255, 128, 0));

    txCircle (925, 483, 12);
    }
