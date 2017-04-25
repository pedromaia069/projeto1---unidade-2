#include <iostream>
#include "point.h"
#include "poligono.h"
#include "retangulo.h"

#define PI 3.14159265

using namespace std;

int main()
{
    retangulo ret(0,0,3,4);

    float area = ret.area();
    cout<<endl<<"Area incial = "<<area<<endl;
    cout<<"Retangulo inicial: ";
    ret.imprime();


    ret.translada(-3,4);
    area = ret.area();
    cout<<endl<<"Area transladada = "<<area<<endl;
    cout<<"Retangulo transladado: ";
    ret.imprime();


    ret.rotaciona(-1.5,6.0, PI);
    area = ret.area();
    cout<<endl<<"Area rotacionada = "<<area<<endl;
    cout<<"Retangulo rotacionado: ";
    ret.imprime();



}
