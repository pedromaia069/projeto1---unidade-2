#ifndef RETANGULO_H
#define RETANGULO_H
#include "poligono.h"

class retangulo : public Poligono {
private:
    Point pt[3];
public:
    retangulo(float x, float y, float largura, float altura);
};

#endif // RETANGULO_H
