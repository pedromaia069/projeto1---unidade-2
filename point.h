#ifndef POINT_H
#define POINT_H


class Point
{
private:
    float x, y; // guardar a posição do ponto.
public:
    Point(void);
    Point(float mx, float my);
    void setX(float mx);
    void setY(float my);
    void setXY(float mx,float my);
    float getX(void);
    float getY(void);
    Point add(Point p1);
    Point sub(Point p1);
    float norma();
    void translada(float a, float b);
    void imprime();
    Point operator= (const Point &p);
    ~Point();
};

#endif // POINT_H
