# include "LFioninaLib.h"
# include "TXLib.h"
# include <stdlib.h>

int main()
    {
    txCreateWindow (1200, 700);
   // int t = 0;
    for (int count = 1; count <= 17; count++)
        {
        SubTitlesDraw ( 50, 20, 40, "Arial", TX_WHITE, "ПРИМЕР 2: Анимация качания елки");
        TreeOneDraw   (300, 200, 2, 15*(count%2)-7, 30, 30, 2,  50, 20);
        txSleep (300);

        ClearScreen(TX_BLACK);
      //  t += 1 ;
        }

    return 0;
    }
