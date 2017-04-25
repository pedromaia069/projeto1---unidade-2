#include "retangulo.h"
#include "poligono.h"
#include "point.h"

retangulo::retangulo(float x, float y, float largura, float altura) : Poligono(x,y)
{
    pt[0].setXY(largura,y);
    pt[1].setXY(largura,altura);
    pt[2].setXY(x,altura);
    insert(pt[0]);
    insert(pt[1]);
    insert(pt[2]);
}
