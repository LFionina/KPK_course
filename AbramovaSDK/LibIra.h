//{-----------------------------------------------------------------------------
//! @brief         Function Library on C++ for animation developing
//!
//! @author        Abramova Irina,
//!             Krasnodar, gimnasium 36
//!
//!
//! @date            May, 2021
//!
//! @mainpage
//!                  Список функций:
//!
//!                - @ref SpringFon()
//!                - @ref SpringFonBegining()
//!                - @ref MountainsLandscape()
//!                - @ref SavanahLandscape()
//!                - @ref Cloud_draw()
//!                - @ref Tree_draw()
//!                - @ref Water_lily_draw()
//!                - @ref Cactus_draw()
//!                - @ref Flower_draw()
//!                - @ref Reed_draw()
//!                - @ref Grass_draw()
//!                - @ref Butterfly_draw()
//!                - @ref Chuck_draw()
//!                - @ref Mouse_twerk()
//!                - @ref MouseBody_draw()
//!                - @ref CatBody_draw()
//!                - @ref WindMill_draw()
//!                - @ref Millblades_draw()
//!                - @ref BigDipper_draw()
//!                - @ref Skateboard_draw()
//!                - @ref Skate_wheels_draw()
//!                - @ref Stick_draw()
//!                - @ref Cheese_draw()
//!                - @ref Girl_draw()
//!                - @ref EMO_Cactus_draw()
//!                - @ref Deffy()
//!
//! @section screenshots     Скриншоты
//!
//! @image html Entry1.png
//! @image html Spring2.png
//! @image html Pink3.png
//! @image html Savanah4.png
//!
//!
//!
//!
//! @cats
//}----------------------------------------------------------------------------


void SpringFon();
void SpringFonBegining();
void MountainsLandscape();
void SavanahLandscape();
void Cloud_draw          (int  x, int  y, double sizeX, double sizeY, COLORREF cloudColor);
void Tree_draw           (int  x, int  y, int crown_width, double sizeX, double sizeY);
void Water_lily_draw     (int  x, int  y, double sizeX, double sizeY);
void Cactus_draw         (int  x, int  y, double sizeX, double sizeY, COLORREF cactusColor);
void Flower_draw         (int  x, int  y, double sizeX, double sizeY, COLORREF flowerColor);
void Reed_draw           (int  x, int  y, double sizeX, double sizeY, int swaying);
void Grass_draw          (int  x, int  y, COLORREF color, double sizeX, double sizeY);
void Butterfly_draw      (int  x, int  y, COLORREF color, int bigness);
void Deffy               (int x, int y, double sizeX, double sizeY, int flapping, int hornDistance, COLORREF wingcolor,
                          COLORREF bigpatterncolor, COLORREF smallpatterncolor, COLORREF outlinecolor, COLORREF Deffycolor);
void Chuck_draw          (int  x, int  y, double sizeX, double sizeY, int eyebrows, int hear);
void Mouse_twerk         (int  x, int  y, double sizeX, double sizeY, int twerk, int tail_wagging);
void MouseBody_draw      (int  x, int  y, double width, double height, COLORREF bodyColor, COLORREF earsColor);
void CatBody_draw        (int  x, int  y, double width, double height, double eyebrows,
                          COLORREF catColor, COLORREF cat_breastColor);
void WindMill_draw       (int  x, int  y, double sizeX, double sizeY);
void Millblades_draw     (int x0, int y0, int x, int y);
void BigDipper_draw      (int  x, int  y, int r);
void Skateboard_draw     (int  x, int  y, double sizeX, double sizeY);
void Skate_wheels_draw   (int x0, int y0, int r);
void Stick_draw          (int  x, int  y, double sizeX, double sizeY, int woodenarms);
void Cheese_draw         (int  x, int  y, double bigness);
void Girl_draw           (int  x, int  y, double sizeX, double sizeY, int hands_UP,
                          int legs_DISTANCE,  int eyebrows_UP,
                          int eyesCRAZYleft,  int eyesPUPILleft,
                          int eyesCRAZYright, int eyesPUPILright,
                          int mouthTOPpoint,  int mouthLOWERpoint,
                          COLORREF HairColor, COLORREF BodyColor = (RGB (224, 199, 160)));
void EMO_Cactus_draw     (int x, int y, double sizeX, double sizeY, int eyebrows_UP,
                          int eyesCRAZYleft, int eyesPUPILleft, int eyesCRAZYright, int eyesPUPILright,
                          int mouthLOWERpoint);


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует ясное градиентное небо и нежную зелень.
//!
//!         Параметры отсутствуют, градиентный переход окраски неба достигается за счет итерации
//!         компонент RGB.
//!
//! \image html Entry1.png "SpringFon" width=250px
//!
//!  @see    SpringFonBegining();  SpringFon();
//!
//!  @note   Неплохо дополнять данные функции такими объектами как: Cloud_draw(), Tree_draw(),
//!  @note   Grass_draw(), и так далее. Описание упомянутых функции см. ниже
//!
//}----------------------------------------------------------------------------------------------

void SpringFonBegining()
    {
    txSetColor     (RGB (204, 255, 255));
    txSetFillColor (RGB (204, 255, 255));

    POINT sky[6] = {{0, 450}, {0, 350}, {600, 350}, {750, 350}, {txGetExtentX(), 350}, {txGetExtentX(), 430}};
    txPolygon (sky, 6);

    for (int gradSky = 1; gradSky < 200; gradSky++)
        {
        txSetColor     (RGB (204 - 2*gradSky, 255, 255));
        txSetFillColor (RGB (204 - 2*gradSky, 255, 255));

        POINT heaven[4] = {{             0, 350 - 4*gradSky}, {             0, 360 - 4*gradSky},
                           {txGetExtentX(), 360 - 4*gradSky}, {txGetExtentX(), 350 - 4*gradSky}};
        txPolygon (heaven, 4);
        }

    txSetColor     (RGB (51, 204, 51));
    txSetFillColor (RGB (51, 204, 51));

    POINT hillbegin[4] = {{0, 400}, {0, 900}, {txGetExtentX(), 900}, {txGetExtentX(), 400}};
    txPolygon (hillbegin, 4);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция также  рисует ясное градиентное небо и небольшой зеленый холм.
//!
//! \image html Spring.png "SpringFon"
//!
//!         Параметры отсутствуют, градиентный переход окраски неба достигается за счет итерации
//!         компонет RGB.
//!
//! @see    SpringFonBegining();  SpringFon();
//!
//! @note   Неплохо дополнять данные функции такими объектами как: Cloud_draw(), Tree_draw(),
//! @note   Grass_draw(), и так далее. Описание упомянутых функций см. ниже
//}----------------------------------------------------------------------------------------------

void SpringFon()
    {
    txSetColor     (RGB (204, 255, 255));
    txSetFillColor (RGB (204, 255, 255));

    POINT sky[6] = {{0, 450}, {0, 350}, {600, 350}, {750, 350}, {1100, 350}, {1100, 430}};
    txPolygon (sky, 6);

    for (int gradSky = 1; gradSky < 200; gradSky++)
        {
        txSetColor     (RGB (204 - 2*gradSky, 255, 255));
        txSetFillColor (RGB (204 - 2*gradSky, 255, 255));

        POINT heaven[4] = {{0, 350 - 4*gradSky}, {0, 360 - 4*gradSky}, {1100, 360 - 4*gradSky},{1100, 350 - 4*gradSky}};
        txPolygon (heaven, 4);
        }

    txSetColor     (RGB (51, 204, 51));
    txSetFillColor (RGB (51, 204, 51));

    POINT hill[7] = {{0, 800}, {0, 450}, {600, 350}, {750, 350}, {1100, 430}, {1100, 800}, {0, 800}};
    txPolygon (hill, 7);

    txSetFillColor (RGB (0, 204, 0));
    txCircle  (300, 1150, 570);
    txCircle  (800, 1250, 570);

    Tree_draw     ( 140, 290,   8, 0.8, 1.0);
    Tree_draw     ( 850, 300,   8, 0.5, 0.7);
    Tree_draw     ( 950, 230,   8, 0.9, 1.3);
    WindMill_draw ( 675, 180, 1.0, 1.0);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует  оригинальный пейзаж, состоящий из гор непривычного розового
//!         цвета, и реки.
//!         Параметры отсутствуют.
//!
//! \image html Mountain.png "Pink Mountains"
//!
//! @see    Reed_draw ();  Water_lily_draw ()
//!
//! @note   Неплохо дополнить данную функцию объектами: Water_lily_draw (), Reed_draw()
//! @note   (кувшинка и камыш)
//! @note   Описание упомянутых функций см. ниже
//}----------------------------------------------------------------------------------------------

void MountainsLandscape()
    {
    txSetColor      (RGB (255, 240, 245));
    txSetFillColor  (RGB (255, 240, 245));

    POINT lavandsky[4] = {{0, 550}, {0, 0}, {1150, 0}, {1150, 550}};
    txPolygon (lavandsky, 4);

    //---------------------------------------------------------------------

    txSetColor      (RGB (238, 130, 238));
    txSetFillColor  (RGB (216, 191, 216));

    POINT pinkfirst[3] = {{730, 35}, {860, 160}, {1010, 220}};
    txPolygon (pinkfirst, 3);

    POINT pinksecond[3] = {{633, 11}, {725, 155}, {965, 255}};
    txPolygon (pinksecond, 3);

    POINT pinkback[3] = {{510, 320}, {0, 280}, {0, 40}};
    txPolygon (pinkback, 3);

    //---------------------------------------------------------------------

    txSetColor     (RGB (221, 160, 221));
    txSetFillColor (RGB (221, 160, 221));

    POINT lilacfirst[4] = {{370, 340}, {630, 10}, {750, 155}, {985, 260}};
    txPolygon (lilacfirst, 4);

    POINT lilacsecond[4] = {{1150, 480}, {1100, 470}, {970, 260}, {1120, 60}};
    txPolygon (lilacsecond, 4);

    POINT lilacthird[6] = {{690, 50}, {730, 30}, {860, 160}, {950, 190}, {1110, 200}, {960, 260}};
    txPolygon (lilacthird, 6);

    POINT lilacfourth[7] = {{560, 140}, {270, 320}, {370, 400}, {510, 340}, {660, 410}, {740, 340}, {650, 280}};
    txPolygon (lilacfourth, 7);

    POINT lilacfifth[5] = {{320, 300}, {80, 170}, {0,260}, {0, 470}, {320, 300}};
    txPolygon (lilacfifth, 5);

    POINT lilacsixth[7] = {{860, 250}, {640, 410}, {800, 470}, {970, 420}, {1150, 480}, {980, 400}, {860, 250}};
    txPolygon (lilacsixth, 7);

    //---------------------------------------------------------------------

    txSetColor      (RGB (238, 130, 238));
    txSetFillColor  (RGB (216, 191, 216));
    POINT pinkthird[4] = {{560, 130}, {660, 280}, {730, 352}, {825, 285}};
    txPolygon (pinkthird, 4);
    POINT pinkfourth[4] = {{860, 250}, {970, 260}, {1105, 470}, {970, 400}};
    txPolygon (pinkfourth, 4);

    //---------------------------------------------------------------------

    txSetColor      (RGB (124, 252, 0));
    txSetFillColor  (RGB (124, 252, 0));

    POINT greenhills[9] = {{  0, 420}, {200, 270}, { 300, 420}, { 510, 340},
                           {700, 510}, {970, 410}, {1150, 550}, {1150, 580}, {0, 500}};
    txPolygon (greenhills, 9);

    txSetColor      (RGB (152, 251, 152), 3);
    txSetFillColor  (RGB (152, 251, 152));

    POINT sungreenfirst[3] = {{200, 270}, {300, 420}, {375, 390}};
    txPolygon (sungreenfirst, 3);

    POINT sungreensecond[3] = {{510, 340}, {700, 510}, {807, 468}};
    txPolygon (sungreensecond, 3);

    POINT sungreenthird[3] = {{970, 410}, {1150, 480}, {1150, 550}};
    txPolygon (sungreenthird, 3);



    txSetColor      (RGB (0, 255, 252), 3);
    txSetFillColor  (RGB (0, 255, 252));

    POINT river[4] = {{0, 800}, {0, 500}, {1150, 570},{1150, 800}};
    txPolygon (river, 4);

   //---------------------------------------------------------------------

    txSetColor      (RGB (50, 255, 50), 3);
    txSetFillColor  (RGB (50, 255, 50));
    POINT riverbank[4] = {{0, 900}, {0, 800}, {1150, 800}, {1150, 900}};
    txPolygon (riverbank, 4);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует  пейзаж ночной пустыни.
//!         Параметры отсутствуют.
//!
//! \image html Savanah.png "SavanahLands"
//!
//! @see    Cactus_draw (); BigDipper_draw();
//!
//! @note   Неплохо дополнить данную функцию объектами: Cactus_draw (), BigDipper_draw()
//! @note   (кактус и созвездие "Большая медведица")
//! @note   Описание упомянутых функций см. ниже
//}----------------------------------------------------------------------------------------------

void SavanahLandscape()
    {
    txSetColor     (RGB (0, 102, 102));
    txSetFillColor (RGB (0, 102, 102));

    POINT savanahsky[4]= {{0,0}, {1100, 0}, {1100, 900}, {0, 900}};
    txPolygon (savanahsky, 4);

    txSetColor     (RGB (255, 155, 0));
    txSetFillColor (RGB (255, 155, 0));
    txCircle       (550, 200, 200);

    txSetColor     (RGB (102, 0, 51));
    txSetFillColor (RGB (102, 0, 51));

    POINT mountainfirst[3] = {{640, 210}, {440, 500}, {850, 500}};
    txPolygon (mountainfirst, 3);

    POINT mountainfirstline[4] = {{0, 500}, {1100, 500}, {1100, 550}, {0, 550}};
    txPolygon (mountainfirstline, 4);

    txSetColor     (RGB (153, 102, 0));
    txSetFillColor (RGB (153, 102, 0));

    POINT mountainsecond[3] = {{500, 250}, {310, 570}, {650, 570}};
     txPolygon (mountainsecond, 3);

    POINT mountainsecondline[4] = {{0, 550}, {1100, 550}, {1100, 620}, {0, 620}};
    txPolygon (mountainsecondline, 4);

    txSetColor     (RGB (204, 102, 51));
    txSetFillColor (RGB (204, 102, 51));

    POINT mountainthird[3] = {{630, 320}, {460, 620}, {820, 620}};
    txPolygon (mountainthird, 3);

    POINT mountainthirdline[4] = {{0, 620}, {1100, 620}, {1100, 670}, {0, 670}};
    txPolygon (mountainthirdline, 4);

    txSetColor     (RGB (204, 153, 51));
    txSetFillColor (RGB (204, 153, 51));

    POINT mountainfouth[3] = {{500, 400}, {350, 670}, {650, 670}};
    txPolygon (mountainfouth, 3);

    POINT mountainfouthline[4] = {{0, 670}, {1100, 670}, {1100, 720}, {0, 720}};
    txPolygon (mountainfouthline, 4);

    txSetColor     (RGB (204, 153, 102));
    txSetFillColor (RGB (204, 153, 102));

    POINT mountainfifth[3] = {{610, 420}, {480, 670}, {780, 670}};
    txPolygon (mountainfifth, 3);

    POINT mountainfifthline[4]= {{0, 670}, {1100, 670}, {1100, 900}, {0, 900}};
    txPolygon (mountainfifthline, 4);

    BigDipper_draw (  20, 150, 4);
    BigDipper_draw (  40, 250, 5);
    BigDipper_draw (1010, 150, 4);
    BigDipper_draw (1010, 250, 5);
    Cactus_draw    ( 270, 450, 2, 2, RGB (102,   0,  51));
    Cactus_draw    ( 170, 450, 3, 3, RGB (102,   0, 102));
    Cactus_draw    ( 870, 440, 2, 2, RGB (102,   0,  51));
    Cactus_draw    ( 970, 470, 4, 4, RGB (102,   0, 102));
    Cactus_draw    ( 100, 460, 4, 4, RGB (102,   0,  51));
    Cactus_draw    ( 850, 560, 1, 1, RGB (  0, 102,   0));
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует  облако.
//!
//! \image html Cloud.png "Облако" width=290px
//!
//! @param  x                           x - координата первого эллипса
//! @param  y                           y - координата первого эллипса
//! @param  sizeX                       Размер облака
//! @param  sizeY                       Размер облака
//! @param  COLORREF cloudColor         Цвет облака
//!
//! @see    SpringFonBegining();  SpringFon();
//!
//! @par    Пример использования:
//!
//! @code
//!         Cloud_draw     (200, 170, 0.5, 0.5, TX_WHITE);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Cloud_draw (int x, int y, double sizeX, double sizeY, COLORREF cloudColor)
    {
     txSetColor     (cloudColor);
     txSetFillColor (cloudColor);
     txEllipse (            x,            y, x + 210*sizeX, y +  80*sizeY);
     txEllipse (x - 100*sizeX, y + 30*sizeY, x + 120*sizeX, y + 100*sizeY);
     txEllipse (x + 100*sizeX, y + 30*sizeY, x + 340*sizeX, y +  90*sizeY);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует ДИСКО - дерево. Оно переливается различными оттенками
//!         зеленого цвета.
//!
//! \image html Tree.png "ДИСКО - дерево" width=280px
//!
//! @param  x                    x - координата верхушки ствола
//! @param  y                    y - координата верхушки ствола
//! @param  sizeX                Размер дерева
//! @param  sizeY                Размер дерева
//! @param  crown_width          Ширина дерева (количество окружностей в основании кроны)
//!
//! @note   Дерево строится при помощи циклов. Цвет задается рандомно в определенном
//! @note   диапазоне RGB.
//!
//!
//! @par    Пример использования:
//!
//! @code
//!         Tree_draw     ( 140, 290,   8, 0.8, 1.0);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Tree_draw (int x, int y, int crown_width, double sizeX, double sizeY)
    {
    txSetFillColor (RGB (128, 64, 0));
    POINT trunk[3] = {{x, y}, {x - ROUND (20*sizeX), y + ROUND (200*sizeY)},
                              {x + ROUND (20*sizeX), y + ROUND (200*sizeY)}};
    txPolygon (trunk, 3);

    txSetFillColor (RGB (40, 203, 88));

    for (int row = crown_width; row > 0; row--)
        {
        for (int leaves = 0; leaves < row; leaves++)
            {
            txSetFillColor (RGB (rand()%10, rand()%255, rand()%10));
            txCircle (x + 15*leaves*sizeX, y + 15*row*sizeY, 16*sizeX);
            }
        }
    for (int row = crown_width; row > 0; row--)
        {
        for (int leaves = 0; leaves < row; leaves++)
            {
            txSetFillColor (RGB (rand()%10, rand()%255, rand()%10));
            txCircle (x - 15*leaves*sizeX, y + 15*row*sizeY, 16*sizeX);
            }
        }
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует незамысловатую водяную лилию. Которую можно использовать как
//!         средство передвижения по реке.
//!
//! \image html Lili.png "Кувшинка" width=280px
//!
//! @param  x                    x - координата центра лепестка
//! @param  y                    y - координата центра лепестка
//! @param  sizeX                Размер лилии
//! @param  sizeY                Размер лилии
//!
//! @note   Замечательно сочетается с водоемами!
//!
//!
//! @see    Reed_draw()
//!
//! @par    Пример использования:
//!
//! @code
//!         Water_lily_draw (150, 700, 0.8, 0.8);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Water_lily_draw  (int  x, int  y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (50, 205, 50));
    txSetFillColor (RGB (50, 205, 50));

    txEllipse (x, y, x + 340*sizeX, y + 60*sizeY);

    txSetColor     (RGB (237, 255, 33));
    txSetFillColor (RGB (237, 255, 33));

    txLine (x + 200*sizeX, y - 20*sizeY, x + 200*sizeX, y - 160*sizeY);
    txLine (x + 230*sizeX, y - 20*sizeY, x + 230*sizeX, y - 170*sizeY);

    txSetColor     (RGB (202, 55, 103));
    txSetFillColor (RGB (202, 55, 103));

    POINT petalmiddle [3] = {{x + ROUND (180*sizeX), y + ROUND (10*sizeY)},
                             {x + ROUND (210*sizeX), y - ROUND (80*sizeY)},
                             {x + ROUND (240*sizeX), y + ROUND (10*sizeY)}};
    txPolygon (petalmiddle, 3);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует кактус. Змечательное дополнение к ночной пустыне!
//!
//! \image html Cactus.png "Кактус обыкновенный" width=280px
//!
//! @param  x                    x - координата центра ствола
//! @param  y                    y - координата центра ствола
//! @param  sizeX                Размер кактуса (доп. толщина ствола)
//! @param  sizeY                Размер кактуса
//! @param  COLORREF cactusColor Цвет кактуса

//! @note   Замечательно сочетается с цветочками! (Flower_draw())
//!
//!
//! @see    EMO_Cactus_draw()
//!
//! @par    Пример использования:
//!
//! @code
//!         Cactus_draw    ( 270, 450, 2, 2, RGB (102,   0,  51));
//! @endcode
//}----------------------------------------------------------------------------------------------

void Cactus_draw  (int x, int y, double sizeX, double sizeY, COLORREF cactusColor)
    {
    txSetColor (cactusColor, 40/sizeY);
    txLine (           x,       y - 190/sizeY, x,            y + 170/sizeY);
    txLine (x - 50/sizeX,                   y, x + 60/sizeX,             y);
    txLine (x - 50/sizeX,                   y, x - 60/sizeX, y -  95/sizeY);
    txLine (x + 60/sizeX,                   y, x + 70/sizeX, y -  90/sizeY);
    txLine (           x,       y + 100/sizeY, x - 60/sizeX, y + 100/sizeY);
    txLine (x - 60/sizeX,       y + 100/sizeY, x - 50/sizeX, y +  50/sizeY);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует классические цветы из окружностей.
//!
//! \image html Flower.png "Цветок обыкновенный" width=280px
//!
//! @param  x                    x - координата центра цветка
//! @param  y                    y - координата центра цветка
//! @param  sizeX                Размер цветка
//! @param  sizeY                Размер цветка
//! @param  COLORREF flowerColor Цвет цветка
//!
//! @note   Замечательно сочетается с различной растительностью
//!
//! @par    Пример использования:
//!
//! @code
//!         Flower_draw ( 850, 565, 0.5, 0.5, RGB (255, 203, 255));
//! @endcode
//}----------------------------------------------------------------------------------------------

void Flower_draw (int x, int y, double sizeX, double sizeY,  COLORREF flowerColor)
    {
    txSetColor     (flowerColor);
    txSetFillColor (flowerColor);

    txCircle (x - 20*sizeX, y - 20*sizeY, 30*sizeX);
    txCircle (x + 20*sizeX, y - 20*sizeY, 30*sizeX);
    txCircle (x - 20*sizeX, y + 20*sizeY, 30*sizeX);
    txCircle (x + 20*sizeX, y + 20*sizeY, 30*sizeX);

    txSetColor     (RGB (153, 0, 151));
    txSetFillColor (RGB (153, 0, 15));
    txCircle (x, y, 30*sizeX);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует камыши.
//!
//! \image html Lili.png "Камыши" width=280px
//!
//! @param   x                    x - координата центра первой окружности
//! @param   y                    y - координата центра первой окружности
//! @param   sizeX                Размер камыша
//! @param   sizeY                Размер камыша
//! @param   swaying              Наклон камыша
//!
//!
//!
//! @see     Water_lily_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          Reed_draw   (800, 600, 0.8, 0.8, 20);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Reed_draw (int x, int y, double sizeX, double sizeY, int swaying)
    {
    txSetColor     (RGB (0, 102, 0),3);
    txLine         (x - swaying, y + 100, x - 5*sizeX, y + 600*sizeY);

    txSetColor     (RGB (102, 0, 51), 3);
    txSetFillColor (RGB (102, 0, 51));
    txCircle       (x - 1.0*swaying - swaying, y, 15);
    txCircle       (x - 0.8*swaying - swaying, y +  20, 15);
    txCircle       (x - 0.6*swaying - swaying, y +  40, 15);
    txCircle       (x - 0.4*swaying - swaying, y +  60, 15);
    txCircle       (x - 0.2*swaying - swaying, y +  80, 15);
    txCircle       (x - swaying, y + 100, 15);

    txSetColor     (RGB (0, 102, 0),3);
    txSetFillColor (RGB (0, 102, 0));
    POINT reedLeaf[7] = {{x - ROUND (( 5 - swaying)*sizeX), y + ROUND (595*sizeY)}, {x - ROUND ((60 - swaying)*sizeX), y + ROUND (120*sizeY)},
                         {x - ROUND ((80 - swaying)*sizeX), y + ROUND (130*sizeY)}, {x - ROUND ((90 - swaying)*sizeX), y + ROUND (230*sizeY)},
                         {x - ROUND ((60 - swaying)*sizeX), y + ROUND (200*sizeY)}, {x - ROUND ((80 - swaying)*sizeX), y + ROUND (130*sizeY)},
                         {x - ROUND (( 5 - swaying)*sizeX), y + ROUND (390*sizeY)}};
    txPolygon (reedLeaf, 7);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует траву
//!
//! \image html Grass.png "Трава" width=280px
//!
//! @param   x                    x - координата первой точки полигона куста
//! @param   y                    y - координата первой точки полигона куста
//! @param   sizeX                Размер куста
//! @param   sizeY                Размер куста
//! @param   COLORREF color       Цвет травы
//!
//!
//! @par     Пример использования:
//!
//! @code
//!          Grass_draw     (800, 480, TX_GREEN, 1.1, 1.1);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Grass_draw (int x, int y, COLORREF color, double sizeX, double sizeY)
    {
    txSetColor     (color);
    txSetFillColor (color);
    POINT grass[15] = {{                    x, y}, {x - ROUND ( 70*sizeX), y - ROUND ( 30*sizeY)},
                       {x + ROUND ( 20*sizeX), y}, {x - ROUND ( 10*sizeX), y - ROUND ( 30*sizeY)},
                       {x + ROUND ( 40*sizeX), y}, {x + ROUND ( 20*sizeX), y - ROUND (100*sizeY)},
                       {x + ROUND ( 60*sizeX), y}, {x + ROUND ( 60*sizeX), y - ROUND ( 60*sizeY)},
                       {x + ROUND ( 80*sizeX), y}, {x + ROUND (110*sizeX), y - ROUND (100*sizeY)},
                       {x + ROUND ( 90*sizeX), y}, {x + ROUND (130*sizeX), y - ROUND ( 60*sizeY)},
                       {x + ROUND (110*sizeX), y}, {x + ROUND (130*sizeX), y - ROUND ( 20*sizeY)},
                       {x + ROUND (120*sizeX), y}};
    txPolygon (grass, 15);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует бабочку
//!
//! \image html Butterfly.png "Бабочка" width=280px
//!
//! @param   x                    x - координата цетра головы бабочки
//! @param   y                    y - координата цетра головы бабочки
//! @param   bigness              Размер бабочки (радиус окружностей, составных частей бабочки)
//! @param   COLORREF color       Цвет бабочки
//!
//! @see     Deffy()
//!
//! @par     Пример использования:
//!
//! @code
//!          Butterfly_draw (600, 50, RGB (204, 139,  51), 2);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Butterfly_draw (int x, int y, COLORREF color, int bigness)
    {
    int x0 = x;
    int y0 = y;
    txSetColor (TX_DARKGRAY);
    txLine (x0, y0, x0 + 30/bigness, y0 - 40/bigness);
    txLine (x0, y0, x0 + 50/bigness, y0 -  5/bigness);
    txSetColor (color);
    txSetFillColor (color);

    for (int part = 20/bigness; part >= 4/bigness; part -= 4/bigness)
        {
        txCircle (x, y, part);
        x -= part;
        y += part;
        }

    txSetColor     (RGB (128, 255, 255));
    txSetFillColor (RGB (193, 224, 244));
    POINT wingL[3] = {{x0 - 15/bigness, y0 + 25/bigness},
                      {x0 + 30/bigness, y0 + 25/bigness},
                      {x0 - 15/bigness, y0 + 75/bigness}};
    txPolygon (wingL, 3);

    POINT wingR[3] = {{x0 - 25/bigness, y0 + 15/bigness},
                      {x0 - 25/bigness, y0 - 35/bigness},
                      {x0 - 75/bigness, y0 + 15/bigness}};
    txPolygon (wingR, 3);
    }

//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует большую красивую бабочку
//!
//! \image html Deffy.png "Деффи - шикарная" width=280px
//!
//! @param   x                    x - координата цетра головы бабочки
//! @param   y                    y - координата цетра головы бабочки
//! @param   sizeX                Размер бабочки
//! @param   sizeY                Размер бабочки
//! @param   flapping             Размер крыла (эффект взмаха крыла)
//! @param   hornDistance         Расстояние между усиками
//!
//! @param   COLORREF wingcolor             Цвет крыльев
//! @param   COLORREF bigpatterncolor       Цвет узора большого крыла
//! @param   COLORREF smallpatterncolor     Цвет узора малого крыла
//! @param   COLORREF outlinecolor          Цвет контура
//! @param   COLORREF Deffycolor            Цвет бабочки
//!
//! @see     Butterfly_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          Deffy (110, 150, 0.6, 0.6, 10, 5,  RGB (217, 0, 217),
//!                 RGB (56, 160, 56), RGB (130, 66, 151), RGB (55, 183, 193), RGB (242, 238, 77));
//! @endcode
//}----------------------------------------------------------------------------------------------
void Deffy (int x, int y, double sizeX, double sizeY, int flapping, int hornDistance, COLORREF wingcolor,
            COLORREF bigpatterncolor, COLORREF smallpatterncolor, COLORREF outlinecolor, COLORREF Deffycolor)
    {
    txSetColor     (outlinecolor, 2);
    txSetFillColor (wingcolor);                        //x=590, y=190

    POINT BigWingR[7] = {{x, y}, {x + ROUND( 60*sizeX) - flapping, y -  ROUND(104*sizeY) + flapping/2},
                                 {x + ROUND(115*sizeX) - flapping, y -  ROUND(110*sizeY) + flapping/2},
                                 {x + ROUND(138*sizeX) - flapping, y -  ROUND( 82*sizeY) + flapping/2},
                                 {x + ROUND(138*sizeX) - flapping, y -  ROUND( 40*sizeY) + flapping/2},
                                 {x + ROUND(108*sizeX) - flapping, y -  ROUND( 12*sizeY) + flapping/2},
                         {x, y}};

    txPolygon (BigWingR, 7);

    POINT BigWingL[7] = {{x, y}, {x - ROUND( 60*sizeX) + flapping, y -  ROUND(104*sizeY) + flapping/2},
                                 {x - ROUND(115*sizeX) + flapping, y -  ROUND(110*sizeY) + flapping/2},
                                 {x - ROUND(138*sizeX) + flapping, y -  ROUND( 82*sizeY) + flapping/2},
                                 {x - ROUND(138*sizeX) + flapping, y -  ROUND( 40*sizeY) + flapping/2},
                                 {x - ROUND(108*sizeX) + flapping, y -  ROUND( 12*sizeY) + flapping/2},
                         {x, y}};

    txPolygon (BigWingL, 7);


    POINT SmallWingR[5] = {{x, y}, {x + ROUND(101*sizeX) - flapping, y },
                                   {x + ROUND(110*sizeX) - flapping, y + ROUND(50*sizeY) },
                                   {x + ROUND( 60*sizeX) - flapping, y + ROUND(78*sizeY) }, {x, y}};

    txPolygon (SmallWingR, 5);


    POINT SmallWingL[5] = {{x, y}, {x - ROUND(101*sizeX) + flapping, y},
                                   {x - ROUND(110*sizeX) + flapping, y + ROUND(50*sizeY)},
                                   {x - ROUND( 60*sizeX) + flapping, y + ROUND(78*sizeY)}, {x, y}};

    txPolygon (SmallWingL, 5);

//========================================================================================
    txSetColor     (bigpatterncolor);
    txSetFillColor (bigpatterncolor);

    POINT BigpatternR [4]= {{x, y}, {x + ROUND(122*sizeX) - flapping, y - ROUND(100*sizeY) + flapping/2},
                                    {x + ROUND(140*sizeX) - flapping, y - ROUND( 80*sizeY) + flapping/2},
                                    {x + ROUND(138*sizeX) - flapping, y - ROUND( 60*sizeY) + flapping/2}};
    txPolygon (BigpatternR, 4);

    POINT BigpatternL [4]= {{x, y}, {x - ROUND(122*sizeX) + flapping, y - ROUND(100*sizeY) + flapping/2},
                                    {x - ROUND(140*sizeX) + flapping, y - ROUND( 80*sizeY) + flapping/2},
                                    {x - ROUND(138*sizeX) + flapping, y - ROUND( 60*sizeY) + flapping/2}};
    txPolygon (BigpatternL, 4);

    txSetColor     (smallpatterncolor);
    txSetFillColor (smallpatterncolor);

    POINT SmallpatternR [4]= {{x, y}, {x + ROUND(107*sizeX) - flapping, y + ROUND(35*sizeY)},
                                      {x + ROUND(113*sizeX) - flapping, y + ROUND(50*sizeY)},
                                      {x + ROUND( 93*sizeX) - flapping, y + ROUND(60*sizeY)}};
    txPolygon (SmallpatternR, 4);

    POINT SmallpatternL [4]= {{x, y}, {x - ROUND(107*sizeX) + flapping, y + ROUND(35*sizeY)},
                                      {x - ROUND(113*sizeX) + flapping, y + ROUND(50*sizeY)},
                                      {x - ROUND( 93*sizeX) + flapping, y + ROUND(60*sizeY)}};
    txPolygon (SmallpatternL, 4);

     txSetColor     (Deffycolor, 2);
     txSetFillColor (Deffycolor);

     txLine   (                  x, y -  ROUND(32*sizeY), x +  ROUND(28*sizeX), y -  ROUND(52*sizeY));
     txLine   (x + ROUND(28*sizeX), y -  ROUND(52*sizeY), x +  ROUND(40*sizeX), y -  ROUND(88*sizeY));
     txLine   (x + ROUND(40*sizeX), y -  ROUND(88*sizeY), x +  ROUND(30*sizeX) - hornDistance, y - ROUND(120*sizeY) - hornDistance);
     txCircle (x + ROUND(30*sizeX) - hornDistance, y - ROUND(120*sizeY) - hornDistance, 5*sizeX);
//===================================================================
     txLine   (                  x, y -  ROUND(32*sizeY), x - ROUND(28*sizeX), y -  ROUND(52*sizeY));
     txLine   (x - ROUND(28*sizeX), y -  ROUND(52*sizeY), x - ROUND(40*sizeX), y -  ROUND(88*sizeY));
     txLine   (x - ROUND(40*sizeX), y -  ROUND(88*sizeY), x - ROUND(30*sizeX) + hornDistance, y - ROUND(120*sizeY) - hornDistance);
     txCircle (x - ROUND(30*sizeX) + hornDistance, y - ROUND(120*sizeY) - hornDistance, 5*sizeX);


     POINT DeffyBody[8] = {{                  x, y - ROUND(40*sizeY)},
                           {x - ROUND( 5*sizeX), y - ROUND(30*sizeY)},
                           {x - ROUND( 2*sizeX), y - ROUND(20*sizeY)},
                           {x - ROUND(10*sizeX), y}, {                 x, y + ROUND(60*sizeY)},
                           {x + ROUND(10*sizeX), y}, {x + ROUND(3*sizeX), y - ROUND(20*sizeY)},
                           {x + ROUND( 5*sizeX), y - ROUND(30*sizeY)}};
     txPolygon (DeffyBody,8);

     }

//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует маленькую желтую птичку из "Angry birds".
//!
//! \image html Chuck.png "Чак - птичка" width=280px
//!
//! @param   x                    x - координата верхней точки головы
//! @param   y                    y - координата верхней точки головы
//! @param   sizeX                Размер птички
//! @param   sizeY                Размер птички
//! @param   eyebrows             Подьем бровей
//! @param   hear                 Подьем хохолка
//!
//! @par     Пример использования:
//!
//! @code
//!          Chuck_draw  (   200, 600, 0.5, 0.5, - 10, 50);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Chuck_draw  (int x, int y, double sizeX, double sizeY, int eyebrows, int hear)
    {
    txSetColor     (RGB(255, 255, 51));
    txSetFillColor (RGB(255, 255, 51));

    POINT bird[14]= {{x, y}, {x - ROUND (15*sizeX), y + ROUND (30*sizeY)}, {x - ROUND (105*sizeX), y + ROUND (160*sizeY)},
                     {x - ROUND ( 90*sizeX), y + ROUND (190*sizeY)}, {x - ROUND ( 45*sizeX), y + ROUND (200*sizeY)},
                     {x - ROUND (  5*sizeX), y + ROUND (220*sizeY)}, {x + ROUND ( 45*sizeX), y + ROUND (215*sizeY)},
                     {x + ROUND ( 90*sizeX), y + ROUND (200*sizeY)}, {x + ROUND (125*sizeX), y + ROUND (190*sizeY)},
                     {x + ROUND (145*sizeX), y + ROUND (170*sizeY)}, {x + ROUND (155*sizeX), y + ROUND (140*sizeY)},
                     {x + ROUND ( 95*sizeX), y + ROUND ( 70*sizeY)}, {x + ROUND ( 45*sizeX), y + ROUND ( 35*sizeY)},
                     {x + ROUND ( 15*sizeX), y + ROUND ( 10*sizeY)}};
    txPolygon (bird, 14);

    txSetColor     (TX_BLACK);
    txSetFillColor (TX_WHITE);
    txCircle (x - 30*sizeX, y + 115*sizeY, 22*sizeX);
    txCircle (x + 75*sizeX, y + 112*sizeY, 22*sizeX);

    txSetFillColor (TX_BLACK);
    txCircle (x - 25*sizeX, y + 112*sizeY, 12*sizeX);
    txCircle (x + 80*sizeX, y + 112*sizeY, 12*sizeX);

    txSetColor(RGB (153, 51, 0), 7);
    txLine    (x + 15*sizeX, y + 100*sizeY, x -  75*sizeX, y + (70 - eyebrows)*sizeY);
    txLine    (x + 45*sizeX, y + 100*sizeY, x + 130*sizeX, y + (50 - eyebrows)*sizeY);

    txSetColor(TX_BLACK, 3);
    txLine (x + 15*sizeX, y +  10*sizeY, x -  (75 + hear/2)*sizeX, y - (30 - hear)*sizeY);
    txLine (x + 15*sizeX, y +  10*sizeY, x -  (85 + hear/2)*sizeX, y - (10 - hear)*sizeY);
    txLine (x + 15*sizeX, y +  10*sizeY, x - (115 + hear/2)*sizeX, y + (20 - hear)*sizeY);

    txLine (x - 85*sizeX, y + 130*sizeY, x - 115*sizeX, y +  90*sizeY);
    txLine (x - 85*sizeX, y + 130*sizeY, x - 125*sizeX, y + 110*sizeY);
    txLine (x - 85*sizeX, y + 130*sizeY, x - 130*sizeX, y + 130*sizeY);

    txSetColor     (RGB (153, 102, 0), 2);
    txSetFillColor (RGB (204, 153, 0));

    POINT beakUp[4] = {{                    x, y + ROUND (145*sizeY)}, {x + ROUND (45*sizeX), y + ROUND (135*sizeY)},
                       {x + ROUND (140*sizeX), y + ROUND (155*sizeY)}, {x + ROUND (35*sizeX), y + ROUND (115*sizeY)}};
    txPolygon (beakUp, 4);

    POINT beakDown[3] = {{                   x, y + ROUND (145*sizeY)}, {x + ROUND (45*sizeX), y + ROUND (135*sizeY)},
                         {x + ROUND (97*sizeX), y + ROUND (150*sizeY)}};
    txPolygon (beakDown, 3);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует скопление мышей. Вид сзади.
//!
//! \image html Twerk.png "Мышки - вид сзади" width=280px
//!
//! @param   x                    x - координата первой "мышки"
//! @param   y                    y - координата первой "мышки"
//! @param   sizeX                Размер мышек
//! @param   sizeY                Размер мышек
//! @param   twerk                Отклонение положения мышки
//! @param   tail_wagging         Колебания хвостика
//!
//! @see     MouseBody_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          Mouse_twerk  (800, 570, 0.3, 0.3, 10, 50);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Mouse_twerk (int x, int y, double sizeX, double sizeY, int twerk, int tail_wagging)
    {
    txSetColor     (RGB (128, 128, 128), 6);
    txSetFillColor (RGB (169, 169, 169));

    txCircle (x - (50 - twerk)*sizeX, y - 60*sizeY, 30*sizeX);
    txCircle (x + (40 - twerk)*sizeX, y - 60*sizeY, 30*sizeX);
    txCircle (x - twerk, y - twerk/10, 60*sizeX);

    txSetColor (TX_BLACK, 2);
    txLine   (x - twerk, y, x - tail_wagging, y - 150*sizeY);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует полноценную мышку (Вид сбоку)
//!
//! \image html Mouse.png "Мышки" width=280px
//!
//! @param   x                    x - координата "шеи" мышки
//! @param   y                    y - координата "шеи" мышки
//! @param   width                Размер мышки (по x)
//! @param   height               Размер мышки (по y)
//! @param   COLORREF bodyColor   Цвет мышки
//! @param   COLORREF earsColor   Цвет ушек мышки
//!
//! @see     Mouse_twerk()
//!
//! @par     Пример использования:
//!
//! @code
//!          MouseBody_draw (750, 500, 0.3, 0.3, RGB (116, 143, 141), RGB (255, 128, 128));
//! @endcode
//}----------------------------------------------------------------------------------------------

void MouseBody_draw (int x, int y, double width, double height, COLORREF bodyColor, COLORREF earsColor)
   {
    txSetColor     (bodyColor);
    txSetFillColor (bodyColor);

    POINT body[3] = {{x, y}, {x + ROUND (90*width), y - ROUND (100*height)}, {x + ROUND (110*height), y + ROUND (20*height)}};
    txPolygon (body, 3);

    POINT head[3] = {{x + ROUND ( 40*width), y - ROUND (100*height)},
                     {x + ROUND (100*width), y - ROUND (140*height)},
                     {x + ROUND (140*width), y - ROUND ( 50*height)}};
    txPolygon (head, 3);

    txCircle (x + 90*width, y - 150*height, 30*width);
    txCircle (x + 22*width, y - 108*height, 30*width);

    txSetColor     (earsColor);
    txSetFillColor (earsColor);
    txCircle (x + 90*width, y - 150*height, 20*width);
    txCircle (x + 22*width, y - 108*height, 20*width);

    txSetColor     (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);

    txCircle (x + 100*width, y - 116*height, 5*width);
    txCircle (x +  80*width, y - 103*height, 5*width);
    txCircle (x + 145*width, y -  50*height, 7*width);
    txLine   (x + 165*width, y -  77*height, x + 125*width, y - 27*height);
    txLine   (x + 185*width, y -  63*height, x + 105*width, y - 37*height);

    txArc    (x +  90*width, y, x - 100*width, y - 20*height, 45, 270);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует котика.
//!
//!\image html Cat.png "Котик" width=280px
//!
//! @param   x                        x - координата центра головы
//! @param   y                        y - координата центра головы
//! @param   width                    Размер котика
//! @param   height                   Размер котика
//! @param   eyebrows                 Подьем бровей котика
//! @param   COLORREF catColor        Цвет котика
//! @param   COLORREF cat_breastColor Цвет грудки котика
//!
//! @par     Пример использования:
//!
//! @code
//!          CatBody_draw (800, 430, 0.7, 0.6, 20.0, RGB (255, 157, 60), RGB (255, 245, 255));
//! @endcode
//}----------------------------------------------------------------------------------------------

void CatBody_draw (int x, int y, double width, double height, double eyebrows, COLORREF catColor, COLORREF cat_breastColor)
    {
    txSetColor     (TX_DARKGRAY, 3);
    txSetFillColor (catColor);

    txRectangle (x + 50*width, y + 120*height, x + 110*width, y + 100*height);

    POINT cat_body[4] = {{x, y}, {x + ROUND (40*width), y},
                         {x + ROUND (60*width), y + ROUND (120*height)},
                         {x - ROUND (30*width), y + ROUND (120*height)}};
    txPolygon (cat_body, 4);

    POINT cats_earL[3] = {{x, y}, {x - ROUND (45*width), y - ROUND (75*height)},
                                  {x + ROUND (25*width), y - ROUND (45*height)}};
    POINT cats_earR[3] = {{x + ROUND (25*width), y - ROUND (45*height)},
                          {x + ROUND (85*width), y - ROUND (75*height)}, {x + ROUND (40*width), y}};
    txPolygon (cats_earL, 3);
    txPolygon (cats_earR, 3);

    txSetFillColor (cat_breastColor);
    txEllipse (x - 10*width, y - 20*height, x + 50*width, y + 100*height);

    txSetFillColor (catColor);
    txCircle   (x + 20*width, y - 30*height, 40*width);

    txSetColor (TX_BLACK, 6);
    txCircle   (           x, y - 30*height, 5*width);
    txCircle   (x + 40*width, y - 30*height, 5*width);

    txSetColor (TX_BLACK);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 20*height);
    txLine (x + 10*width, y - 15*height, x - 45*width, y - 10*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 20*height);
    txLine (x + 30*width, y - 15*height, x + 85*width, y - 10*height);
    txLine (x + 22*width, y - 12*height, x + 22*width, y -  5*height);

    txSetColor (TX_BLACK,3);
    txLine (x +  10*width, y - 45*height, x - 20*width, y - (45 + eyebrows)*height);
    txLine (x +  30*width, y - 45*height, x + 60*width, y - (45 + eyebrows)*height);

    txSetFillColor (TX_LIGHTRED);
    txEllipse (x + 15*width, y - 20*height, x + 30*width, y - 14*height);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует здание мельницы.
//!
//!\image html Mill.png "Мельница"
//!
//! @param   x          x - координата верхней точки мельницы
//! @param   y          y - координата верхней точки мельницы
//! @param   sizeX      Размер башни
//! @param   sizeY      Размер башни
//!
//! @see     Millblades_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          WindMill_draw (675, 180, 1.0, 1.0);
//! @endcode
//}----------------------------------------------------------------------------------------------

void WindMill_draw (int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (183, 104, 87));
    txSetFillColor (RGB (183, 104, 87));
    POINT mill[7] = {{                   x, y - ROUND ( 40*sizeY)}, {x + ROUND (40*sizeX), y - ROUND ( 10*sizeY)},
                     {x + ROUND (60*sizeX), y + ROUND (120*sizeY)}, {x + ROUND (60*sizeX), y + ROUND (170*sizeY)},
                     {x - ROUND (60*sizeX), y + ROUND (170*sizeY)}, {x - ROUND (60*sizeX), y + ROUND (120*sizeY)},
                     {x - ROUND (40*sizeX), y - ROUND ( 10*sizeY)}};
    txPolygon (mill, 7);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует крылья мельницы.
//!
//! \image html Mill.png "Мельница"
//!
//! @param   x0          x0 - верхней точки крыла
//! @param   y0          y0 - верхней точки крыла
//! @param   x           x  - нижней точки крыла
//! @param   y           y  - нижней точки крыла
//!
//! @see     WindMill_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          Millblades_draw (675, 180, ROUND (100*cos(t*0.1) + 675), ROUND (100*sin(t*0.1) + 180));
//! @endcode
//}----------------------------------------------------------------------------------------------

void Millblades_draw (int x0, int y0, int x, int y)
    {
    txSetColor (RGB (109, 91, 82), 25);
    txLine     (x0, y0, x, y);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует созвездие " Большая медведица"
//!
//! \image html BigDipper.png "Большая медведица"
//!
//! @param  x           x - центр первой звезды
//! @param  y           y - центр первой звезды
//! @param  r           радиус звезды
//!
//! @par     Пример использования:
//!
//! @code
//!          BigDipper_draw (1010, 50, 5);
//! @endcode
//}----------------------------------------------------------------------------------------------

void BigDipper_draw ( int x, int y, int r)
    {
    txSetColor     (RGB (176, 196, 222));
    txSetFillColor (RGB ((252 + rand()%255), (252 + rand()%255), (252 + rand()%255)));
    txCircle (x, y, r);
    txCircle (x +  70, y -  70, r/2);
    txCircle (x + 110, y +  30, r/2);
    txCircle (x +  50, y + 110, r/2);
    txCircle (x -  30, y +  30, r/2);
    txCircle (x - 160, y +  50, r/2);
    txCircle (x - 240, y + 110,   r);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует скейтбоард (без колес)
//!
//! \image html Skate.png "Скейтбоард"
//!
//! @param   x          x - координата левого угла эллипса
//! @param   y          y - координата левого угла эллипса
//! @param   sizeX      Размер доски
//! @param   sizeY      Размер доски
//!
//! @see     Skate_wheels_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          Skateboard_draw  (100, 700, 0.8, 0.8);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Skateboard_draw   (int x, int y, double sizeX, double sizeY)
    {
    txSetColor     (RGB (35, 144, 120), 5);
    txSetFillColor (RGB (139, 131, 120));
    txEllipse (x, y, x + 340*sizeX, y + 20*sizeY);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует колеса для скейтбоарда
//!
//! \image html Skate.png "Скейтбоард"
//!
//! @param   x0          x - координата центра первого колеса
//! @param   y0          y - координата центра первого колеса
//! @param   r           Радиус колес
//!
//!
//! @see     Skateboard_draw()
//!
//! @par     Пример использования:
//!
//! @code
//!          Skate_wheels_draw   (-50 + 11*t + ROUND(4*cos(t)) + ROUND (3*sin(t)),
//!                               730 + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Skate_wheels_draw (int x0, int y0,  int r)
    {
    txSetColor     (RGB ( 96, 123, 139), 15);
    txSetFillColor (TX_WHITE);
    txCircle       (x0, y0, r);
    txCircle       (x0 + 170, y0, r);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует просто палку.
//!
//! \image html Stick.png "Многофункциональная палка"
//!
//! @param   x               x - координата верхней точки палки
//! @param   y               y - координата верхней точки палки
//! @param   sizeX           Размер палки
//! @param   sizeY           Размер палки
//! @param   woodenarms      Положение палки
//!
//! @par     Пример использования:
//!
//! @code
//!          Skate_wheels_draw   (-50 + 11*t + ROUND(4*cos(t)) + ROUND (3*sin(t)),
//!                               730 + ROUND (3*cos(t)) - ROUND (4*sin(t)), 20);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Stick_draw (int  x, int  y, double sizeX, double sizeY, int woodenarms)
    {
    txSetColor (RGB (189, 183, 107), 12);
    txLine ( x + 2*woodenarms, y - woodenarms, x + 210*sizeX, y + 180*sizeY);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует кусок сыра.
//!
//! \image html Cheese.png "Кусок сыра"
//!
//! @param   x               x - координата крайней левой точки куска
//! @param   y               y - координата крайней левой точки куска
//! @param   bigness         Размер куска сыра
//!
//! @par     Пример использования:
//!
//! @code
//!          Cheese_draw    (800, 500, 1.0);
//! @endcode
//}----------------------------------------------------------------------------------------------

void Cheese_draw (int x, int y, double bigness)
    {
    txSetColor     (TX_LIGHTRED, 5);
    txSetFillColor (RGB (181, 0, 0));
    POINT cheese[3] = {{x, y}, {x - ROUND(140*bigness), y + ROUND(30*bigness)}, {x + ROUND(150*bigness), y + ROUND(30*bigness)}};
    txPolygon (cheese, 3);

    txSetColor     (RGB (181, 170,  43),2);
    txSetFillColor (RGB (227, 221, 140));
    txRectangle (x - ROUND(140*bigness), y + ROUND(30*bigness), x + ROUND(150*bigness), y + ROUND(80*bigness));

    txCircle (x - ROUND( 80*bigness), y + ROUND(50*bigness), ROUND(5*bigness));
    txCircle (x - ROUND( 45*bigness), y + ROUND(60*bigness), ROUND(5*bigness));
    txCircle (x + ROUND( 10*bigness), y + ROUND(40*bigness), ROUND(5*bigness));
    txCircle (x + ROUND( 60*bigness), y + ROUND(50*bigness), ROUND(5*bigness));
    txCircle (x + ROUND(130*bigness), y + ROUND(55*bigness), ROUND(5*bigness));
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует девочку.
//!
//! \image html Girl.png "Девочка"
//!
//! @param   x                  x - координата шеи девочки
//! @param   y                  y - координата шеи девочки
//! @param   sizeX              Размер девочки
//! @param   sizeY              Размер девочки
//! @param   hands_UP           Изменение положения  рук
//! @param   legs_DISTANCE      Изменение растояния между ногами
//! @param   eyebrows_UP        Положение бровей
//! @param   eyesCRAZYleft      Размер левого глаза
//! @param   eyesPUPILleft      Размер левого зрачка
//! @param   eyesCRAZYright     Размер правого глаза
//! @param   eyesPUPILright     Размер правого зрачка
//! @param   mouthTOPpoint      Положение верхней точки рта
//! @param   mouthLOWERpoint    Положение нижней точки рта
//! @param   COLORREF HairColor Цвет волос
//! @param   COLORREF BodyColor Цвет тела
//!
//!
//! @par      Пример использования:
//!
//! @code
//!           Girl_draw (600, 500, 0.7, 0.7, 120, - 50,-10, 0, 0, 0, 0, 3, 0, RGB (219, 112, 147));
//! @endcode
//}----------------------------------------------------------------------------------------------

void Girl_draw (int x, int y, double sizeX, double sizeY, int hands_UP,
                int legs_DISTANCE, int eyebrows_UP,    int eyesCRAZYleft,
                int eyesPUPILleft, int eyesCRAZYright, int eyesPUPILright,
                int mouthTOPpoint, int mouthLOWERpoint, COLORREF HairColor, COLORREF BodyColor)
    {
    txSetColor (BodyColor, 7);

    txLine (x - 50*sizeX, y + 25*sizeY, x - 100*sizeX, y + (80 - hands_UP)*sizeY);
    txLine (x + 50*sizeX, y + 25*sizeY, x + 100*sizeX, y + (80 - hands_UP)*sizeY);

    txLine (x, y, x - (5 + legs_DISTANCE/2)*sizeX, y + 200*sizeY);
    txLine (x, y, x + (5 + legs_DISTANCE/2)*sizeX, y + 200*sizeY);

    txSetColor     ((TX_BLACK), 2);
    txSetFillColor (TX_BLACK);
    txCircle   (x - 50*sizeX, y + 30*sizeY, 25*sizeX);
    txCircle   (x + 50*sizeX, y + 30*sizeY, 25*sizeX);

    POINT girlsGown[4] = {{x - ROUND (30*sizeX), y}, {x + ROUND(30*sizeX), y},
                          {x + ROUND (70*sizeX), y + ROUND (120*sizeY)},
                          {x - ROUND (80*sizeX), y + ROUND (120*sizeY)}};
    txPolygon (girlsGown, 4);

    txSetFillColor (TX_WHITE);
    txCircle (x + 25*sizeX, y +  25*sizeY, 9*sizeX);
    txCircle (x + 10*sizeX, y +  50*sizeY, 9*sizeX);
    txCircle (x - 30*sizeX, y +  50*sizeY, 9*sizeX);
    txCircle (x - 30*sizeX, y +  80*sizeY, 9*sizeX);
    txCircle (x + 30*sizeX, y +  80*sizeY, 9*sizeX);
    txCircle (x - 15*sizeX, y +  25*sizeY, 9*sizeX);
    txCircle (x - 50*sizeX, y + 110*sizeY, 9*sizeX);
    txCircle (           x, y + 110*sizeY, 9*sizeX);
    txCircle (x + 50*sizeX, y + 110*sizeY, 9*sizeX);

    txSetColor     (HairColor, 5);
    txSetFillColor (HairColor);
    txLine         (x -  40*sizeX, y - 55*sizeY, x - 100*sizeX, y + 20*sizeY);
    txLine         (x - 100*sizeX, y + 20*sizeY, x - 115*sizeX, y + 10*sizeY);
    txLine         (x - 115*sizeX, y + 10*sizeY, x -  40*sizeX, y - 20*sizeY);

    txSetFillColor (TX_BLACK);
    txCircle  (x -  80*sizeX, y -  3*sizeY, 10*sizeX);

    txLine   (x +  40*sizeX, y - 55*sizeY, x + 100*sizeX, y + 20*sizeY);
    txLine   (x + 100*sizeX, y + 20*sizeY, x + 115*sizeX, y + 10*sizeY);
    txLine   (x + 115*sizeX, y + 10*sizeY, x +  40*sizeX, y - 20*sizeY);
    txCircle (x +  80*sizeX, y -  3*sizeY, 10*sizeX);

    txSetColor     (BodyColor);
    txSetFillColor (BodyColor);
    txEllipse      (x - 50*sizeX, y - 70*sizeY, x + 50*sizeX, y);

    txSetColor     (TX_BLACK, 1);
    txSetFillColor (TX_WHITE);
    txLine  (x - 17*sizeX, y - 55*sizeY, x - 37*sizeX, y - (55 - eyebrows_UP)*sizeY);
    txLine  (x + 17*sizeX, y - 55*sizeY, x + 37*sizeX, y - (55 - eyebrows_UP)*sizeY);
    txCircle       (x - 27*sizeX, y - 40*sizeY, (10 -  eyesCRAZYleft)*sizeX);
    txCircle       (x + 27*sizeX, y - 40*sizeY, (10 - eyesCRAZYright)*sizeX);

    txSetColor     (TX_BLUE);
    txSetFillColor (TX_BLUE);
    txCircle       (x - 27*sizeX, y - 40*sizeY, (5 -  eyesPUPILleft)*sizeX);
    txCircle       (x + 27*sizeX, y - 40*sizeY, (5 - eyesPUPILright)*sizeX);

    txSetColor (HairColor, 5);
    txLine (           x,  y - 70*sizeY,            x,     y - 58*sizeY);
    txLine (x -  5*sizeX,  y - 68*sizeY, x -  5*sizeX,     y - 60*sizeY);
    txLine (x - 10*sizeX,  y - 66*sizeY, x - 10*sizeX,     y - 62*sizeY);
    txLine (x +  5*sizeX,  y - 68*sizeY, x +  5*sizeX,     y - 60*sizeY);
    txLine (x + 10*sizeX,  y - 66*sizeY, x + 10*sizeX,     y - 62*sizeY);

    txSetColor     (RGB (207, 58, 96));
    txSetFillColor (RGB (207, 58, 96));
    POINT girlsMouth[4] = {{x - ROUND (22*sizeX), y - ROUND ( 20*sizeY)},
                           {x - ROUND ( 7*sizeX), y - ROUND ((20 - mouthTOPpoint)*sizeY)},
                           {x + ROUND (22*sizeX), y - ROUND ( 20*sizeY)},
                           {                   x, y - ROUND ((10 - mouthLOWERpoint)*sizeY)}};
    txPolygon (girlsMouth, 4);
    }


//{----------------------------------------------------------------------------------------------
//!         Эта функция рисует кактус с рожицей в цветочном горшке.
//!
//! \image html Emo.png "Эмо - кактус"
//!
//! @param   x                  x - координата левой крайней точки горшка
//! @param   y                  y - координата левой крайней точки горшка
//! @param   sizeX              Размер композиции
//! @param   sizeY              Размер композиции
//! @param   eyebrows_UP        Положение бровей
//! @param   eyesCRAZYleft      Размер левого глаза
//! @param   eyesPUPILleft      Размер левого зрачка
//! @param   eyesCRAZYright     Размер правого глаза
//! @param   eyesPUPILright     Размер правого зрачка
//! @param   mouthLOWERpoint    Положение нижней точки рта
//!
//! @see     Cactus_draw ()
//!
//! @par     Пример использования:
//!
//! @code
//!          EMO_Cactus_draw (200, 500, 0.4, 0.4, 20, 10, 1, 10, 1, - 25);
//! @endcode
//}----------------------------------------------------------------------------------------------

void EMO_Cactus_draw  (int x, int y, double sizeX, double sizeY, int eyebrows_UP,
                       int eyesCRAZYleft,  int eyesPUPILleft, int eyesCRAZYright,
                       int eyesPUPILright, int mouthLOWERpoint)
    {
    txSetColor (RGB (128, 64, 64), 10);
    txSetFillColor (RGB (128, 64, 64));
    POINT pot[4] = {{x, y}, {x + ROUND (457*sizeX), y}, {x + ROUND (337*sizeX), y + ROUND (310*sizeY)},
                            {x + ROUND (157*sizeX), y + ROUND (310*sizeY)}};
    txPolygon (pot, 4);
    txSetFillColor (TX_BLACK);
    txEllipse (x + ROUND (3*sizeX), y - ROUND (30*sizeY), x + ROUND (460*sizeX), y + ROUND (27*sizeY));

    txSetColor (TX_GREEN, 5);
    txSetFillColor (RGB (90, 255, 90));
    POINT cactus [8] = {{x + ROUND (177*sizeX), y + ROUND ( 10*sizeY)}, {x + ROUND ( 87*sizeX), y - ROUND (180*sizeY)},
                        {x + ROUND (117*sizeX), y - ROUND (240*sizeY)}, {x + ROUND (177*sizeX), y - ROUND (280*sizeY)},
                        {x + ROUND (287*sizeX), y - ROUND (280*sizeY)}, {x + ROUND (337*sizeX), y - ROUND (240*sizeY)},
                        {x + ROUND (357*sizeX), y - ROUND (180*sizeY)}, {x + ROUND (287*sizeX), y + ROUND ( 10*sizeY)}};
    txPolygon (cactus, 8);

    POINT child_cactus [8] = {{x + ROUND (282*sizeX), y - ROUND (280*sizeY)}, {x + ROUND (287*sizeX), y - ROUND (360*sizeY)},
                              {x + ROUND (327*sizeX), y - ROUND (405*sizeY)}, {x + ROUND (397*sizeX), y - ROUND (410*sizeY)},
                              {x + ROUND (452*sizeX), y - ROUND (360*sizeY)}, {x + ROUND (457*sizeX), y - ROUND (295*sizeY)},
                              {x + ROUND (417*sizeX), y - ROUND (260*sizeY)}, {x + ROUND (337*sizeX), y - ROUND (240*sizeY)}};
    txPolygon (child_cactus, 8);

    txSetColor (TX_BLACK, 5);
    txLine (x + ROUND (192*sizeX), y - ROUND ((240 - eyebrows_UP)*sizeY), x + ROUND (127*sizeX), y - ROUND ((240 + eyebrows_UP)*sizeY));
    txLine (x + ROUND (237*sizeX), y - ROUND ((240 - eyebrows_UP)*sizeY), x + ROUND (302*sizeX), y - ROUND ((240 + eyebrows_UP)*sizeY));

    txLine (x + 177*sizeX, y - 110*sizeY, x + 217*sizeX, y -  (90 - mouthLOWERpoint)*sizeY);
    txLine (x + 217*sizeX, y - (90 - mouthLOWERpoint)*sizeY, x + 257*sizeX, y - 110*sizeY);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_WHITE);
    txEllipse (x + (132 -  eyesCRAZYleft)*sizeX, y - 225*sizeY, x + (187 +  eyesCRAZYleft)*sizeX, y - 155*sizeY);
    txEllipse (x + (247 - eyesCRAZYright)*sizeX, y - 225*sizeY, x + (302 + eyesCRAZYright)*sizeX, y - 155*sizeY);

    txSetFillColor (TX_BLACK);
    txCircle (x + 167*sizeX, y - 185*sizeY, (15 -  eyesPUPILleft)*sizeX);
    txCircle (x + 282*sizeX, y - 185*sizeY, (15 - eyesPUPILright)*sizeX);
    }
