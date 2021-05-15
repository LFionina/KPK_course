//==================================================================
//@file BivenLib.h                                                //
//                                                                //
//  librari of functions for a novice programmer Biven            //
//  библиотека начинающего программиста Бочкарев Игорь Викторович //
//                                                                //
// (c) Bochkarev Igor V, teachar at school number 175 in Samara.  //
//                                                                //
//@date                  01/05/2021                               //
//{
//==================================================================
//!
//!@note  Библиотека начинающего программиста  BivenLib.h
//!       это собрание персонажей анимации первого мультика-программы.
//!       в первой версии в библиотеку включены следующие функции-персонажи
//!       BoyDraw -   мужчина
//!       SunDraw -   солнце
//!       TreeDraw -  дерево
//!       HouseDraw - домик
//!}
//==================================================================

#ifndef BIVENLIB_H_INCLUDED
#define BIVENLIB_H_INCLUDED



#endif // BIVENLIB_H_INCLUDED

namespace Biven
{
void HouseDraw (int x, int y, double sizeX, double sizeY, double GableUp, double GableX, double roofRight, double roofLeft);
void TreeDraw  (int x, int y, double sizeX, double sizeY);
void SunDraw   (double x, double y, double size, double sizeChet, double sizeNChet, double sizeEyse,
                double EyeLeftX, double EyeRightX, double EyeLeftUp, double EyeRightUp );
void BoyDraw   (double x, double y, double sizeX, double sizeY, int shovelUp,
                double LeftKneeX,  double LeftKneeY,  double LeftFootX,  double LeftFootY,
                double RightKneeX, double RightKneeY, double RightFootX, double RightFootY);
void StarShip  (int x, int y, double sizeShip);

//!{================================================================================================
//! рисуем мужчину, относительный центр координат находится в точке соприкосновения головы и туловища.
//!
//!@param x           x - координата по горизонтальной оси точки отсчета мужчины,
//!@param y           y - координато по оси y (направлена вниз),
//!@param sizeX        - размер масштабирования по оси х,
//!@param sizeY        - размер масштабирования по оси Y,
//!@param shovelUp     - параметр отвечает за поднятие лопаты 1 - лопата внизу  (-1) лопата поднята вверх ,
//!@param LeftKneeX    - параметр отвечает за расположение левого колена по оси Х,
//!@param LeftKneeY    - параметр отвечает за расположение левого колена по оси Y,
//!@param LeftFootX    - параметр отвечает за расположение левой стопы по оси Х
//!@param LeftFootY    - параметр отвечает за расположение левой стопы по оси Y
//!
//!@param RightKneeX   - параметр отвечает за расположение правого колена по оси Х,
//!@param RightKneeY   - параметр отвечает за расположение правого колена по оси Y,
//!@param RightFootX   - параметр отвечает за расположение правой стопы по оси Х
//!@param RightFootY   - параметр отвечает за расположение правой стопы по оси Y
//!
//!@note  мужчина пока с прямыми руками, но планируются локти с возможностями копяния лопатой.
//!
//!       Особенности движения ног при анимации:
//!       Базовое движение - левое колено вверху, правое колено внизу и наооборот.
//!       чтобы сделать еще фазу движения - когда ноги вместе - это надо показать человека стоящего,
//!       необходимо сделать смещение фазы подъема колен на какую либо величину (подбирается индивидуально)
//!       в предлагаемом примере величина смещения равна 2.
//!       пример кода будет выглядеть следующим образом:
//!       \code
//!       BoyDraw ( 50 + 0.2*t, 600 - 0.25*t, 2, 2, 1,
//!               ((t + 2) / 20) % 2 * 2,        ((t + 2) / 20) % 2 * 7,
//!               ((t + 2) / 20) % 2,        ((t + 2) / 20) % 2 * 7,
//!               ((t / 20) % 2 * (-1) + 1) * 2, ((t / 20) % 2 * (-1) + 1) * 7,
//!               ((t / 20) % 2 * (-1) + 1), ((t / 20) % 2 * (-1) + 1) * 7);
//!
//!       \endcode
//!
//!
//!
//!
//}==================================================================================================


void BoyDraw (double x, double y, double sizeX, double sizeY, int shovelUp,
              double LeftKneeX,  double LeftKneeY,  double LeftFootX,  double LeftFootY,
              double RightKneeX, double RightKneeY, double RightFootX, double RightFootY)
    {
    txSetColor  (TX_BLUE);
    txCircle    (x, y - 5*sizeY, 5*((sizeX + sizeY) / 2));

    txSetColor      (TX_BLUE, 2);
    txSetFillColor  (TX_RED);
    POINT shirt [4] = {{ROUND (x - 6*sizeX), ROUND (y)},            {ROUND (x + 6*sizeX), ROUND (y)},
                       {ROUND (x + 3*sizeX), ROUND (y + 16*sizeY)}, {ROUND (x - 3*sizeX), ROUND (y +16*sizeY)}};
    txPolygon (shirt, 4);

    txSetColor (TX_BLUE, 4);
    txLine (ROUND (x - 1*sizeX),                 ROUND (y + 16*sizeY),                 ROUND (x - (2 + LeftKneeX) * sizeX), ROUND (y + (22 - LeftKneeY) * sizeY));
    txLine (ROUND (x - (2 + LeftKneeX) * sizeX), ROUND (y + (22 - LeftKneeY) * sizeY), ROUND (x - (3 + LeftFootX) * sizeX), ROUND (y + (28 - LeftFootY) * sizeY));

    txLine (ROUND (x + 1*sizeX),                  ROUND (y + 16*sizeY),                  ROUND (x + (2 + RightKneeX) * sizeX), ROUND (y + (22 - RightKneeY) * sizeY));
    txLine (ROUND (x + (2 + RightKneeX) * sizeX), ROUND (y + (22 - RightKneeY) * sizeY), ROUND (x + (3 + RightFootX) * sizeX), ROUND (y + (28 - RightFootY) * sizeY));

    txLine (ROUND (x -  3*sizeX), ROUND (y +  3*sizeY), ROUND (x - 14*sizeX), ROUND (y +  6*sizeY*shovelUp));
    txLine (ROUND (x +  5*sizeX), ROUND (y +  3*sizeY), ROUND (x + 12*sizeX), ROUND (y + 15*sizeY));

    txLine (ROUND (x - 14*sizeX), ROUND (y +  3*sizeY*shovelUp), ROUND (x - 14*sizeX), ROUND (y + 23*sizeY*shovelUp));
    txSetFillColor  (TX_GRAY);
    POINT shovel [4] = {{ROUND (x - 17*sizeX), ROUND (y + 23*sizeY*shovelUp)}, {ROUND (x - 11*sizeX), ROUND (y + 23*sizeY*shovelUp)},
                        {ROUND (x - 12*sizeX), ROUND (y + 27*sizeY*shovelUp)}, {ROUND (x - 16*sizeX), ROUND (y + 27*sizeY*shovelUp)}};
    txPolygon (shovel, 4);
    }

//------------------------------------------------------------------------
void HouseDraw (int x, int y, double sizeX, double sizeY, double GableUp, double GableX, double roofRight, double roofLeft)
    {
    txSetColor      (TX_GREEN);

    txSetFillColor  (TX_GREEN);
    txRectangle (x - 100*sizeX, y - 70*sizeY, x, y);

    txSetFillColor  (TX_LIGHTGRAY);
    txRectangle (x - 36*sizeX, y - 42*sizeY, x - 15*sizeX, y);

    txSetFillColor  (TX_YELLOW);
    txRectangle (x - 79*sizeX, y - 42*sizeY, x - 65*sizeX, y - 22*sizeY);
    txLine      (x - 73*sizeX, y - 42*sizeY, x - 73*sizeX, y - 22*sizeY);

    txSetFillColor  (TX_RED);
    POINT roof [3] = {{ROUND (x - 120*sizeX*roofLeft),  ROUND (y -  70*sizeY)},
                      {ROUND (x -  50*sizeX*GableX),    ROUND (y - 128*sizeY*GableUp)},
                      {ROUND (x +  20*sizeX*roofRight), ROUND (y -  70*sizeY)}};
    txPolygon  (roof, 3);

    txSetFillColor  (TX_BROWN);
    POINT chimney [4] = {{ROUND (x - 85*sizeX), ROUND (y - 99*sizeY)},          {ROUND (x - 85*sizeX), ROUND (y - 117*sizeY*GableUp)},
                         {ROUND (x - 76*sizeX), ROUND (y - 117*sizeY*GableUp)}, {ROUND (x - 76*sizeX), ROUND (y - 107*sizeY)}};
    txPolygon (chimney, 4);
    }

//------------------------------------------------------------------------
void TreeDraw (int x, int y, double sizeX, double sizeY)
    {
    txSetColor (TX_BROWN, 4);
    txLine   (x, y, x, y - 30 * sizeY);

    txSetColor  (TX_BROWN, 2);
    txLine   (x,           y -  8*sizeY, x +  9*sizeX, y - 20*sizeY);
    txLine   (x +  9*sizeX, y - 20*sizeY, x + 18*sizeX, y - 23*sizeY);
    txLine   (x,            y - 13*sizeY, x -  9*sizeX, y - 20*sizeY);
    txLine   (x -  9*sizeX, y - 20*sizeY, x - 16*sizeX, y - 20*sizeY);
    txLine   (x,            y - 20*sizeY, x +  9*sizeX, y - 37*sizeY);
    txLine   (x,            y - 30*sizeY, x -  4*sizeX, y - 39*sizeY);

    txSetColor  (TX_GREEN, 2);
    txSetFillColor (TX_GREEN);
    txCircle (x,            y - 30*sizeY, 3 * (sizeX + sizeY));
    txCircle (x +  9*sizeX, y - 20*sizeY, 3 * (sizeX + sizeY));
    txCircle (x + 18*sizeX, y - 23*sizeY, 3 * (sizeX + sizeY));
    txCircle (x -  9*sizeX, y - 20*sizeY, 3 * (sizeX + sizeY));
    txCircle (x - 16*sizeX, y - 20*sizeY, 3 * (sizeX + sizeY));
    txCircle (x +  9*sizeX, y - 37*sizeY, 3 * (sizeX + sizeY));
    txCircle (x -  4*sizeX, y - 39*sizeY, 3 * (sizeX + sizeY));
    }

//------------------------------------------------------------------------
void SunDraw (double x, double y, double size, double sizeChet, double sizeNChet, double sizeEyse,
              double EyeLeftX, double EyeRightX, double EyeLeftUp, double EyeRightUp )
    {
    txSetColor     (TX_YELLOW, 4);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 20*size);
    txLine (ROUND (x + 15*size), ROUND (y - 14*size), ROUND (x + 40*size*sizeNChet), ROUND (y - 37*size*sizeNChet));
    txLine (ROUND (x + 19*size), ROUND (y -  4*size), ROUND (x + 39*size*sizeChet),  ROUND (y -  7*size*sizeChet));
    txLine (ROUND (x + 20*size), ROUND (y +  9*size), ROUND (x + 37*size*sizeNChet), ROUND (y + 18*size*sizeNChet));
    txLine (ROUND (x +  8*size), ROUND (y + 18*size), ROUND (x + 16*size*sizeChet),  ROUND (y + 36*size*sizeChet));
    txLine (ROUND (x),           ROUND (y + 20*size), ROUND (x),                     ROUND (y + 63*size*sizeNChet));
    txLine (ROUND (x),           ROUND (y - 20*size), ROUND (x),                     ROUND (y - 63*size*sizeChet));
    txLine (ROUND (x -  8*size), ROUND (y + 18*size), ROUND (x - 16*size*sizeNChet), ROUND (y + 36*size*sizeNChet));
    txLine (ROUND (x - 15*size), ROUND (y - 14*size), ROUND (x - 40*size*sizeChet),  ROUND (y - 37*size*sizeChet));
    txLine (ROUND (x - 20*size), ROUND (y +  9*size), ROUND (x - 37*size*sizeNChet), ROUND (y + 18*size*sizeNChet));
    txLine (ROUND (x - 19*size), ROUND (y -  4*size), ROUND (x - 39*size*sizeChet),  ROUND (y -  7*size*sizeChet));

    txSetColor (TX_BLACK, 1);
    txSetFillColor (TX_WHITE);
    txCircle (ROUND (x - 10*size*EyeLeftX),  ROUND (y - 10*size*EyeLeftUp),  4*size*sizeEyse);
    txCircle (ROUND (x + 10*size*EyeRightX), ROUND (y - 10*size*EyeRightUp), 4*size*sizeEyse);
    txSetFillColor (TX_BLACK);
    txCircle (ROUND (x -  9*size*EyeLeftX),  ROUND (y - 10*size*EyeLeftUp),  2.7*size*sizeEyse);
    txCircle (ROUND (x + 11*size*EyeRightX), ROUND (y - 10*size*EyeRightUp), 2.7*size*sizeEyse);

    txSetFillColor (TX_TRANSPARENT);
    POINT smile [5] = {{ROUND (x - 11*size), ROUND (y + 7*size)}, {ROUND (x),          ROUND (y + 13*size)},
                       {ROUND (x + 11*size), ROUND (y + 7*size)}, {ROUND (x + 5*size), ROUND (y +  9*size)},
                       {ROUND (x -  5*size), ROUND (y + 9*size)}};
    txPolygon (smile, 5);
    }
//------------------------------------------------------------------------

void StarShip (int x, int y, double sizeShip)
    {
    txSetColor (TX_BLUE, 4);
    txSetFillColor (RGB (0, 0, 255));
    txEllipse (ROUND (x - 60.0*sizeShip), ROUND (y - 24.7*sizeShip), ROUND (x + 60.0*sizeShip), ROUND (y + 24.7*sizeShip));
    txLine    (ROUND (x - 60.1*sizeShip), ROUND (y),                 ROUND (x - 54.0*sizeShip), ROUND (y + 16.7*sizeShip));
    txLine    (ROUND (x - 54.0*sizeShip), ROUND (y + 16.7*sizeShip), ROUND (x),                 ROUND (y + 54.7*sizeShip));
    txLine    (ROUND (x),                 ROUND (y + 54.7*sizeShip), ROUND (x + 53.7*sizeShip), ROUND (y + 24.7*sizeShip));
    txLine    (ROUND (x + 53.7*sizeShip), ROUND (y + 24.7*sizeShip), ROUND (x + 59.7*sizeShip), ROUND (y +  2.2*sizeShip));
    txLine    (ROUND (x),                 ROUND (y - 96.1*sizeShip), ROUND (x - 59.1*sizeShip), ROUND (y -  4.3*sizeShip));
    txLine    (ROUND (x),                 ROUND (y - 96.1*sizeShip), ROUND (x - 44.5*sizeShip), ROUND (y + 16.6*sizeShip));
    txLine    (ROUND (x),                 ROUND (y - 96.1*sizeShip), ROUND (x + 41.9*sizeShip), ROUND (y + 17.7*sizeShip));
    txLine    (ROUND (x),                 ROUND (y - 96.1*sizeShip), ROUND (x + 59.0*sizeShip), ROUND (y -  4.5*sizeShip));
    txLine    (ROUND (x),                 ROUND (y + 54.7*sizeShip), ROUND (x),                 ROUND (y + 24.7*sizeShip));

    POINT Support1 [3] = {{ROUND (x - 47.6*sizeShip), ROUND (y + 21.2*sizeShip)}, {ROUND (x - 43.5*sizeShip), ROUND (y + 49.9*sizeShip)}, {ROUND (x - 40.2*sizeShip), ROUND (y + 26.4*sizeShip)}};
    txPolygon (Support1, 3);
    POINT Support2 [3] = {{ROUND (x - 27*sizeShip),   ROUND (y + 75.1*sizeShip)}, {ROUND (x - 28.9*sizeShip), ROUND (y + 24.7*sizeShip)}, {ROUND (x - 16.5*sizeShip), ROUND (y + 30.4*sizeShip)}};
    txPolygon (Support2, 3);
    POINT Support3 [3] = {{ROUND (x + 30.2*sizeShip), ROUND (y + 78.2*sizeShip)}, {ROUND (x + 33.5*sizeShip), ROUND (y + 24.7*sizeShip)}, {ROUND (x + 15.6*sizeShip), ROUND (y + 30.4*sizeShip)}};
    txPolygon (Support3, 3);
    POINT Support4 [3] = {{ROUND (x + 48.3*sizeShip), ROUND (y + 57.7*sizeShip)}, {ROUND (x + 38.6*sizeShip), ROUND (y + 33.1*sizeShip)}, {ROUND (x + 48.3*sizeShip), ROUND (y + 27.7*sizeShip)}};
    txPolygon (Support4, 3);
    }

//-----------------------------------------------------------------------------
}

