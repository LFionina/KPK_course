#include "DetkovaLAlib.h"

int main()
{
    txCreateWindow (1024, 648);
    txSetFillColor (TX_WHITE);
    txRectangle    (0,   0, 1024, 648);

    DrawSun   (850, 105, 1, 1, TX_YELLOW, 1, 1, 0, 1, 0);

    DrawCloud ( 50, 150, 1, 1, TX_LIGHTCYAN);
    DrawCloud (300,  50, 1, 1, TX_LIGHTCYAN);
    DrawCloud (550, 200, 1, 1, TX_LIGHTCYAN);

    DrawCat   (100, 500, 3, 3, RGB(255, 69, 0), RGB(0, 0, 255), 1, 1, 1, 1, 1, 0);

    DrawGirl  (300, 500, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30), RGB(255, 0, 255), 0, 0, 0, 0, 5, 1, 1, 0, 0, 0, 0);

    DrawBoy   (500, 500, 1, 1, RGB(221, 160, 221), RGB(218, 105, 30), RGB(  0, 0, 255), 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 1);

    DrawHowse (600, 400, 1, 1, RGB(255, 255, 224), RGB(139, 0, 0), RGB(0, 0, 0), 0, 0, 0, 0, 0);

    DrawFlower (600,  600, 1, 1, RGB(255, 0, 0), RGB(255, 255, 255), 1, 1);

    return 0;

}
