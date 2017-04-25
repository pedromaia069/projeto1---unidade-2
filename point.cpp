#include "point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point()
{
}

Point::Point(float mx, float my)
{
    x=mx;
    y=my;
}

void Point::setX(float mx)
{
    x = mx;
}

void Point::setY(float my)
{
    y = my;
}

void Point::setXY(float mx, float my)
{
    x = mx;
    y = my;
}

float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}

Point Point::add(Point p1)
{
    this->x += p1.x;
    this->y += p1.y;

    return (*this);
}

Point Point::sub(Point p1)
{
    this->x -= p1.x;
    this->y -= p1.y;

    return (*this);
}

float Point::norma()
{
    float retorno;
    retorno = sqrt((x*x) + (y*y));

    return (retorno);
}

void Point::translada(float a, float b)
{
    x += a;
    y += b;
}

void Point::imprime()
{
    cout<<"("<<x<<","<<y<<")";
}

Point Point::operator=(const Point &p)
{
    this->x=p.x;
    this->y=p.y;

    return(*this);
}

Point::~Point()
{

}


