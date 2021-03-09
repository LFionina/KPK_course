#include <stdlib.h>
# include "TXLib.h"

int main()
        {
        txCreateWindow (1000, 600);

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

        txSetColor (RGB (0, 255, 0));
        txSetFillColor (RGB (0, 255, 0));
        txLine(250, 50, 200, 100);
        txLine(200, 100, 300, 100);
        txLine(300, 100, 250, 50);
        txFloodFill (250, 80);
        txLine(250, 100, 200, 150);
        txLine(200, 150, 300, 150);
        txLine(300, 150, 250, 100);
        txFloodFill (250, 130);
        txLine(250, 150, 200, 200);
        txLine(200, 200, 300, 200);
        txLine(300, 200, 250, 150);
        txFloodFill (250, 180);
        txSetColor (RGB (177, 101, 54));
        txSetFillColor (RGB (177, 101, 54));
        txRectangle(240, 200, 260, 210);

        txSetColor (RGB (0, 245, 0));
        txSetFillColor (RGB (0, 200, 0));
        txCircle (480, 350, 35);
        txSetFillColor (RGB (0, 200, 0));
        txCircle (520, 350, 35);
        txSetFillColor (RGB (0, 250, 0));
        txCircle (500, 350, 40);
        txSetColor (RGB (177, 101, 54));
        txLine(500, 390, 500, 350);
        txLine(500, 390, 480, 350);
        txLine(500, 390, 520, 350);
        return 0;
        }
