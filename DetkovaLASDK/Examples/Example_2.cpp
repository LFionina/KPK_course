#include "DetkovaLAlib.h"

int main()
{
    txCreateWindow (1024, 648);
    txSetFillColor (TX_WHITE);
    txRectangle    (0,   0, 1024, 648);

    int i = 0;
    while (i <= 100)
    {
        txClear();

        txSetFillColor (TX_WHITE);
        txRectangle    (0, 0, 1024, 648);

        DrawSun   (850, 105, 1, 1, TX_YELLOW, i%20, (i/4)%2, (i/4)%2, (i/4)%2, 0);

        DrawCloud ( 50 + i, 150, 1, 1, TX_LIGHTCYAN);
        DrawCloud (300 + i,  50, 1, 1, TX_LIGHTCYAN);
        DrawCloud (550 + i, 200, 1, 1, TX_LIGHTCYAN);

        DrawCat   (100, 500, 3, 3, RGB(255, 69, 0), RGB(0, 0, 255), 1, i%10-5, i%5, i%5, 1, (i/2)%2);

        DrawGirl  (300, 500 - 50*(i/3%2), 1, 1, RGB(221, 160, 221), RGB(218, 105, 30), RGB(255, 0, 255),
                    -20 - i%3*10, -20 - i%3*10, 0, 0, 5, (i/3)%2, i%11 - 5, 0, 0, 0, 0);

        DrawBoy   (500, 500 - 50*(i/2%2), 1, 1, RGB(221, 160, 221), RGB(218, 105, 30), RGB(  0, 0, 255),
                    -20 - i%3*10, -20 - i%3*10, 0, 0, 1, (i/3)%2, i%5, i%5, 1, 2, 1);

        DrawHowse (600, 400, 1, 1, RGB(255, 255, 224), RGB(139, 0, 0), RGB(0, 0, 0), 0, 0, 0, 0, 0);

        for (int j = 1; j <= 6; j++)
        {
           DrawFlower (600 + 50*j,  600, 1, 1, RGB(255, 0, 0), RGB(255, 255, 255), i%11-5, i%10-5);
        }

        txSleep (100);

        i++;

    }
}
