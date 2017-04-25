#ifndef POLIGONO_H
#define POLIGONO_H
#include "point.h"
class Poligono
{
private:
    int vt=0; //verticies passadas pelo usuário
    Point vert[101];
public:
    Poligono();
    Poligono(float a, float b);
    void insert(Point ponto);
    int getVertices();
    void setVertices(int mvt);
    void imprime();
    float area();
    void translada(float a, float b);
    void rotaciona(float x0, float y0, float angulo);
};

#endif // POLIGONO_H
