//{===========================================================================
//! @file       LFioninaLib.h
//!
//!             Библиотека объектов
//!
//!@author  (C) Фионина Людмила Евгеньевна, г. Самара,
//!@date          2021
//!
//!@mainpage
//!   БИБЛИОТЕКА ПЕРСОНАЖЕЙ ДЛЯ СОЗДАНИЯ МУЛЬТФИЛЬМА
//!
//!@image html title.png
//!
//!@par   Назначение
//!
//!       Данная библиотека составлена из основных функций, которые используются
//!     для создания мультфильма и состоит из трех разделов:
//!     - общие функции, которые можно использовать в любых мультфильмах, созданных
//!       на основе учебной библиотеки "Тупого художника" TXLib.h;
//!     - функции основных персонажей, которые используются в мультфильме "Медовая история";
//!     - примеры использования функция библиотеки.
//!
//!       This library is composed of the basic functions that are used
//!     to create a cartoon and consists of three sections:
//!     - general functions that can be used in any cartoons.
//!       based on the educational library TXLib.h;
//!     - functions of the main characters that are used in the cartoon "Honey Story";
//!     - examples of using the library function.
//!
//! @defgroup Misc      Разное
//! @defgroup Persons   Персонажи
//! @defgroup Examples  Примеры
//!
//!
//!
//}===========================================================================

#include "TXLib.h"

void ClearScreen(COLORREF colorBackGround);
void SubTitlesDraw (int x, int y,
                    int sizeFont, const char nameFont[],
                    COLORREF colorFont,
                    const char text[]);
void TreeOneDraw (int x,  int y, double size,
                  double inclineX,
                  int widthTree, int heightTree,
                  int pxLine,
                  int colorLine, int colorTree);

void BearDraw (int x, int y, double size,
               COLORREF colorEye, double dBetweenEyes, double radiusEyes,
               int noseY,
               int dBetweenEars,
               int dChestMove,
               int lHandX, int lHandY,
               int rHandX, int rHandY,
               int lFoodX, int lFoodY,
               int rFoodX, int rFoodY);

void BarrelDraw (double x, double y, double size);
void BeeDraw (int x, int y, double size);
void BushDraw (int x, int y, double size);
void CupTee (int x, int y, int orientation);
void BeeHomeDraw (int x, int y, double size);

void FlowerDraw (int x, int y, double size,
                 COLORREF colorPetal, COLORREF colorCenter);

void HomeDraw (double x, double y,    int heightRoof,
               int widthWindow, int heightWindow, double size);

void ExampleOne();
void ExampleTwo();
//{-----------------------------------------------------------------------------
//! @ingroup Misc
//! Очищает экран заданным цветом (из списка базовых цветов библиотеки TXLib.h
//!
//! @param colorBackGround  Базовый цвет из библиотеки TXLib.h
//!
//! @par  Пример использования:
//! @code
//!         ClearScreen(TX_BLACK);
//! @endcode
//}-----------------------------------------------------------------------------

void ClearScreen(COLORREF colorBackGround)
    {
    txSetColor     (colorBackGround);
    txSetFillColor (colorBackGround);
    txClear        ();
    }

//{-----------------------------------------------------------------------------
//! @ingroup Misc
//!
//! Выводит на экран текстовые субтитры, начиная с указанного места,
//! заданным шрифтом, размером шрифта и цветом
//!
//! @param x         x - координата начальной точки текста
//! @param y         y - координата начальной точки текста
//! @param sizeFont  sizeFont - размер шрифта
//! @param nameFont  nameFont - название гарнируты шрифта
//! @param colorFont colorFont - цвет шрифта из библиотеки TXLib.h
//! @param text      text - текстовая строка (сами субтирты)
//!
//! @par  Пример использования:
//! @code
//!         SubTitlesDraw (180, 590, 30, "Bookman Old Style", TX_YELLOW, "В одном лесу...");
//! @endcode
//}-----------------------------------------------------------------------------

void SubTitlesDraw (int x, int y,
                    int sizeFont, const char nameFont[],
                    COLORREF colorFont,
                    const char text[])
    {
    txSetColor     (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle    (x, y, x + 500, y + 65);
    txSetColor     (colorFont);
    txSelectFont   (nameFont, sizeFont);
    txTextOut      (x + 10, y + 15, text);
    }

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует бочонок для меда
//!
//!@note <i>В бочонок Мишка обычно складывает мед для хранения.
//!      Потом угощает гостей чаем с душистым медком.</i>
//!
//! <table border = 0>
//! <tr><td> @image html barrel.png  </td>
//! <td>
//! @param x     x - координата начальной точки (верхняя левая)
//! @param y     y - координата начальной точки (верхняя левая)
//! @param size  size - размер бочонка
//! </td>
//! </tr>
//! </table>
//!
//!@note Бочонок рисуется при помощи эллипсов с контурами, "верхушка" и "низ" эллипсов "срезается" прямоугольниками цвета фона.
//!
//!
//! @par  Пример использования:
//! @code
//!         BarrelDraw  (737, 670, 1.5);
//! @endcode
//}-----------------------------------------------------------------------------

void BarrelDraw (double x, double y, double size)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (RGB (255, 204, 102));
    txEllipse   (x,           y, x + 100*size,        y - 100*size);
    txEllipse   (x + 20*size, y, x + (100 - 20)*size, y - 100*size);
    txEllipse   (x + 40*size, y, x + (100 - 40)*size, y - 100*size);
    txSetFillColor (TX_BLACK);
    txRectangle (x, y,             x + 100*size, y - 15*size        );
    txRectangle (x, y - 100*size , x + 100*size, y - (100 - 15)*size);
    }

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует пчелу заданного размера
//!
//!@note <i>Пчелки собирают мед и редко делятся им с Мишкой, поэтому он часто его ворует</i>
//!
//! <table border = 0>
//! <tr><td> @image html bee.png  </td>
//! <td>
//! @param x     x - координата начальной точки (точка соединения головы и тела пчелы)
//! @param y     y - координата начальной точки (точка соединения головы и тела пчелы)
//! @param size  size - размер пчелы
//! </td>
//! </tr>
//! </table>
//!
//!
//! @par  Пример использования:
//! @code
//!         BeeDraw (300, 250, 1);
//! @endcode
//}-----------------------------------------------------------------------------

void BeeDraw (int x,int y, double size)
    {
    txSetFillColor (RGB (30, 30, 0));
    txSetColor     (RGB (255, 255, 0),3);
    txCircle  (x,          y - 5*size, 5*size);
    txEllipse (x - 5*size, y,          x + 5*size, y + 15*size);

    txSetColor     (RGB (255, 255, 0),2*size);
    txLine (x -  4*size, y +  5*size, x +  4*size, y +  5*size);
    txLine (x -  4*size, y + 10*size, x +  4*size, y + 10*size);

    txSetFillColor (RGB (185, 235, 225));
    txSetColor     (RGB (50, 50, 0),2);
    txEllipse (x - 15*size, y, x, y +  6*size);
    txEllipse (x + 15*size, y, x, y +  6*size);
    }

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует дом с заданной высотой крыши и размерами окна
//!
//!@note <i>Домик, в котором живет Мишка - прочный, выстроен из добротных бревен с тисовой крышей и большим окном</i>
//!
//! <table border = 0>
//! <tr><td> @image html home.png  </td>
//! <td>
//! @param x            x - координата начальной точки (левый нижний угол)
//! @param y            y - координата начальной точки (левый нижний угол)
//! @param heightRoof   heightRoof - высота крыши дома
//! @param widthWindow  widthWindow - ширина окна дома
//! @param heightWindow heightWindow - высота окна дома
//! @param size         size - размер дома
//! </td>
//! </tr>
//! </table>
//!
//! @par  Пример использования:
//! @code
//!         HomeDraw    (900, 250, 150, 160, 90, 0.7);
//! @endcode
//}-----------------------------------------------------------------------------

void HomeDraw (double x, double y,    int heightRoof,
               int widthWindow, int heightWindow, double size)
    {
    txSetColor     (RGB (177, 137, 77));
    txSetFillColor (RGB (177, 137, 77));
    txRectangle (x, y,            x + 300*size, y -  30*size);
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
    POINT roof[5] = {{int(x -  10*size), int(y - 175*size)               },
                     {int(x + 310*size), int(y - 175*size)               },
                     {int(x + 200*size), int(y - (175 + heightRoof)*size)},
                     {int(x + 100*size), int(y - (175 + heightRoof)*size)},
                     {int(x -  10*size), int(y - 175*size)}};
    txPolygon (roof, 5);
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

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует чайную чашку
//!
//!@note <i>Чайная чашка из фамильного сервиза бабушки Мишки.
//!         Только для почетных гостей</i>
//!
//! <table border = 0>
//! <tr><td> @image html cup.png  </td>
//! <td>
//! @param x            x - координата начальной точки (верхний внешний край чашки)
//! @param y            y - координата начальной точки (верхний внешний край чашки)
//! @param orientation  orientation - ориентация (для зеркального отображения чашки)
//! </td>
//! </tr>
//! </table>
//!
//! @par  Пример использования:
//! @code
//!       CupTee (150, 150, +1);
//!       CupTee (150, 150, -1);
//! @endcode
//}-----------------------------------------------------------------------------

void CupTee(int x, int y, int orientation)
    {
    txSetColor     (RGB (120, 34,  95), 2);
    txSetFillColor (RGB (208, 92, 175));
    POINT cup[11] = {{x - 40*orientation, y + 50},
                     {x - 60*orientation, y - 50},
                     {x + 60*orientation, y - 50},
                     {x + 55*orientation, y - 25},
                     {x + 90*orientation, y - 25},
                     {x + 90*orientation, y + 30},
                     {x + 70*orientation, y + 30},
                     {x + 70*orientation, y - 10},
                     {x + 50*orientation, y - 10},
                     {x + 40*orientation, y + 50},
                     {x - 40*orientation, y + 50}};
    txPolygon (cup, 11);
    }

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует улей
//!
//!@note <i>Улей для пчелок. Последняя модель на рынке "Умных вещей". </i>
//!
//! <table border = 0>
//! <tr><td> @image html beehome.png  </td>
//! <td>
//! @param x     x - координата начальной точки (верхний левый угол стен улья)
//! @param y     y - координата начальной точки (верхний левый угол стен улья)
//! @param size  size - размер улья
//! </td>
//! </tr>
//! </table>
//!
//!@note <i>Пчелы очень любят свои дома и не отстают от современного прогресса,
//!         оснащая их последними разработками противомедвежьей сигнализации.</i>
//!
//! @par  Пример использования:
//! @code
//!       BeeHomeDraw (150, 150, 1.3);
//! @endcode
//}-----------------------------------------------------------------------------

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

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует куст
//!
//!@note <i>Кусты - неотъемлемая часть современного лесного декора.
//!         Могут расти сами собой, а могут быть специально посажены для красоты.</i>
//!
//! <table border = 0>
//! <tr><td> @image html bush.png  </td>
//! <td>
//! @param x     x - координата начальной точки (основание куста)
//! @param y     y - координата начальной точки (основание куста)
//! @param size  size - размер куста
//! </td>
//! </tr>
//! </table>
//!
//! @par  Пример использования:
//! @code
//!       BushDraw (50, 50, 1);
//! @endcode
//}-----------------------------------------------------------------------------

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

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует елку
//!
//!@note <i>Самый лучший лес - еловый. Воздух в нем насыщен ароматами
//!         положительно влияющими на дружелюбную атмосферу.</i>
//!
//! <table border = 0>
//! <tr><td> @image html tree.png  </td>
//! <td>
//! @param x           x - координата начальной точки (верхний треугольник, левая точка основания)
//! @param y           y - координата начальной точки (верхний треугольник, левая точка основания)
//! @param size        size - размер елки
//! @param inclineX    inclineX - смещение верхушки елки по Х (для эффекта качания)
//! @param widthTree   widthTree - ширина треугольников елки
//! @param heightTree  heightTree - высота треугольников елки
//! @param pxLine      pxLine - ширина линии контура елки
//! @param colorLine   colorLine - значение темноты зеленого цвета для контура
//! @param colorTree   colorTree  - значение темноты зеленого цвета для заливки елки
//! </td>
//! </tr>
//! </table>
//!
//! @par  Пример использования:
//! @code
//!       TreeOneDraw (50, 50, 1, 0.5, 10, 25, 2, 50, 70);
//! @endcode
//}-----------------------------------------------------------------------------

void TreeOneDraw (int x, int y, double size, double inclineX, int widthTree, int heightTree,
                  int pxLine, int colorLine, int colorTree)
    {
    txSetColor     (RGB (0, 255-colorLine, 0), pxLine);
    txSetFillColor (RGB (0, 255-colorTree, 0)        );
    txLine (x + inclineX,         y,                     x - widthTree/2*size, y + heightTree*size  );
    txLine (x + inclineX,         y,                     x + widthTree/2*size, y + heightTree*size  );
    txLine (x - widthTree/2*size, y + heightTree*size,   x + widthTree/2*size, y + heightTree*size  );
    txFloodFill (x, y + heightTree*size-5);

    txLine (x + inclineX/2,       y + heightTree*size,   x - widthTree/2*size, y + heightTree*2*size);
    txLine (x + inclineX/2,       y + heightTree*size,   x + widthTree/2*size, y + heightTree*2*size);
    txLine (x - widthTree/2*size, y + heightTree*2*size, x + widthTree/2*size, y + heightTree*2*size);
    txFloodFill (x, y + heightTree/2*3*size);

    txLine (x + inclineX/4,       y + heightTree*2*size, x + widthTree/2*size, y + heightTree*3*size);
    txLine (x + inclineX/4,       y + heightTree*2*size, x - widthTree/2*size, y + heightTree*3*size);
    txLine (x - widthTree/2*size, y + heightTree*3*size, x + widthTree/2*size, y + heightTree*3*size);
    txFloodFill (x, y + heightTree/2*5*size);

    txSetColor     (RGB (177, 101, 54));
    txSetFillColor (RGB (177, 101, 54));
    txRectangle (x - widthTree/5*size, y + heightTree*3*size+1, x + widthTree/5*size, y + heightTree*3*size+heightTree/5);
    }

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует медвежонка
//!
//!@note <i>Медвежонок Мишка - один из главных персонажей мультфильма "Медовая история"
//!         Учится быть вежливым и уважительным к труду других.</i>
//!
//! <table border = 0>
//! <tr><td> @image html bear.png  </td>
//! <td>
//! @param x            x - координата начальной точки (между головой и телом)
//! @param y            y - координата начальной точки (между головой и телом)
//! @param size         size - размер межвежонка
//! @param colorEye     colorEye - цвет глаз
//! @param dBetweenEyes dBetweenEyes - расстояние между глазами
//! @param radiusEyes   radiusEyes - радиус глаз
//! @param noseY        noseY - координата для движения носа вверх вниз
//! @param dBetweenEars dBetweenEars - расстояние между ушами
//! @param dChestMove   dChestMove  - смещение нагрудника на теле
//! @param lHandX       lHandX - Х координата левой лапы
//! @param lHandY       lHandY - Y координата левой лапы
//! @param rHandX       rHandX - Х координата правой лапы
//! @param rHandY       rHandY - Y координата правой лапы
//! @param lFoodX       lFoodX - Х координата левой ноги
//! @param lFoodY       lFoodY - Y координата левой ноги
//! @param rFoodX       rFoodX - Х координата правой ноги
//! @param rFoodY       rFoodY - Y координата правой ноги
//! </td>
//! </tr>
//! </table>
//!
//! @par  Пример использования:
//! @code
//!       BearDraw (665, 495, 3.0, TX_YELLOW, 0, 1, 0, 30, 5, 25, 0, 25, 0, 21, 47, 19, 47);
//! @endcode
//}-----------------------------------------------------------------------------

void BearDraw (int x, int y, double size,
               COLORREF colorEye, double dBetweenEyes, double radiusEyes,
               int noseY, int dBetweenEars, int dChestMove,
               int lHandX, int lHandY, int rHandX, int rHandY,
               int lFoodX, int lFoodY,int rFoodX, int rFoodY)
    {
    txSetColor     (TX_WHITE);
    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - (dBetweenEars/2  )*size, y - 43*size, 10*size);
    txCircle (x + (dBetweenEars/2  )*size, y - 43*size, 10*size);

    txSetFillColor (RGB (238, 209, 111));
    txCircle (x - (dBetweenEars/2-1)*size, y - 42*size, 8*size);
    txCircle (x + (dBetweenEars/2-1)*size, y - 42*size, 8*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x, y - 25*size, 25*size);

    txSetFillColor (colorEye);
    txCircle (x - 8*size+dBetweenEyes, y - 33*size, 4*size*radiusEyes);
    txCircle (x + 8*size+dBetweenEyes, y - 33*size, 4*size*radiusEyes);

    txSetFillColor (RGB (0, 0, 0));
    txCircle (x - 8*size+dBetweenEyes, y - 31*size, 2*size*radiusEyes);
    txCircle (x + 8*size+dBetweenEyes, y - 31*size, 2*size*radiusEyes);

    txSetColor     (RGB (0, 0, 0));
    txLine (x - 5*size, y - 25*size+noseY, x + 5*size, y - 25*size+noseY);
    txLine (x,          y - 20*size+noseY, x + 5*size, y - 25*size+noseY);
    txLine (x - 5*size, y - 25*size+noseY, x,          y - 20*size+noseY);
    txFloodFill    (x,  y - 23*size+noseY);

    txSetColor     (TX_RED);
    txSetFillColor (TX_RED);
    txEllipse (x - 2*size, y - 15*size, x + 2*size, y - 8*size);

    txSetColor     (RGB (255, 255, 255));
    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - lHandX*size, y + lHandY*size, 10*size);
    txCircle (x + rHandX*size, y + rHandY*size, 10*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x - lFoodX*size, y + lFoodY*size, 10*size);
    txCircle (x + rFoodX*size, y + rFoodY*size, 10*size);

    txSetFillColor (RGB (177, 101, 54));
    txCircle (x, y + 25*size, 25*size);
    txSetFillColor (RGB (238, 209, 111));
    txCircle (x, y + 13*size+dChestMove, 13*size);
    }

//{-----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует цветок заданного размера и цвета самого цветка
//!
//!@note <i>Цветок - источник пыльцы для производства меда.</i>
//!
//! <table border = 0>
//! <tr><td> @image html flower.png  </td>
//! <td>
//! @param x           x - координата начальной точки (нижний конец стебля)
//! @param y           y - координата начальной точки (нижний конец стебля)
//! @param size        size - размер цветка
//! @param colorPetal  colorPetal - цвет лепестков цветка
//! @param colorCenter colorCenter - цвет серединки цветка
//! </td>
//! </tr>
//! </table>
//!
//! @par  Пример использования:
//! @code
//!         FlowerDraw  (115, 555, 1.5, TX_BLUE, TX_ORANGE);
//! @endcode
//}-----------------------------------------------------------------------------

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
    txCircle (x,          y - 43*size, 5*size);
    txCircle (x,          y - 60*size, 5*size);
    txCircle (x - 8*size, y - 48*size, 5*size);
    txCircle (x + 8*size, y - 48*size, 5*size);
    txCircle (x - 8*size, y - 55*size, 5*size);
    txCircle (x + 8*size, y - 55*size, 5*size);

    txSetFillColor (colorCenter);
    txCircle (x,          y - 51*size, 6*size);
    }


