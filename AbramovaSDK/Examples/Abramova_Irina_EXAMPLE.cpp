#include "TXLib.h"
#include "LibIra.h"

int main()
    {
    txCreateWindow (1200, 700);
    HDC  background_Cartoon = txLoadImage ("BackgroudExample//COMMONPIC.bmp");

    int t = 0;
    int swing = 60;
    int twitch = 20;
    while (t <= 250)
        {
        txBitBlt            (txDC(), 0, 0, 1200, 700, background_Cartoon, 0, 0);

        Skateboard_draw     (- 100 + 8*t, 520 - 3*t, 0.8, 0.8);

        Skate_wheels_draw   (-  50 + 8*t + ROUND (4*cos(t)) + ROUND (3*sin(t)),
                            ( 550 - 3*t) + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);

        Chuck_draw          (    0 + 8*t, 420 - 3*t, 0.5, 0.5, (t%2*20) - 10, (t%2*30) + 50);

        EMO_Cactus_draw     (   70 + 8*t, 460 - 3*t, 0.2, 0.2, 10 + t/2, 10 + t/3, 5 , 10 + t/3, 5, 10 - t/2);

        Flower_draw         (  150 + 8*t, 380 - 3*t, 0.2, 0.2, RGB (255, 20, 255));

        Butterfly_draw      (  120 + ROUND(15*(t - sin(t))),  50 + ROUND(50*(1 - cos(t))), RGB (100,  39,  51), 2);

        Butterfly_draw      (  100 + ROUND(15*(t - sin(t))), 500 + ROUND(20*(1 - cos(t))), RGB (245, 100,   0), 3);

        Deffy               (  450, 700 - t*3, 0.6, 0.6, abs(t%swing - swing/2) - swing/4, abs(t%twitch - twitch/2) - twitch/4,
        RGB (217, 0, 217),
                               RGB (56, 160, 56), RGB (130, 66, 151), RGB (55, 183, 193), RGB (242, 238, 77));

        Deffy               (  750, 700 - t*3, 0.4, 0.4, abs(t%swing - swing/2) - swing/4, abs(t%twitch - twitch/2) - twitch/4,
                               RGB (130, 66, 151), RGB (242, 238, 77), RGB (217, 0, 217), RGB (55, 183, 193), RGB (56, 160, 56));

        txSleep (50);
        t++;
        }

    txDeleteDC (background_Cartoon);
    return 0;
    }

