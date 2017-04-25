#include "poligono.h"
#include "point.h"
#include <iostream>
#include <math.h>

#define PI 3.14159265

using namespace std;

Poligono::Poligono(float a, float b)
{
    vert[0].setXY(a,b);
    vt++;
}

void Poligono::insert(Point ponto)
{
    if(vt<100){
        vert[vt]=ponto;
        vert[vt+1]=vert[0];
        vt++;
    }else {
        cout<<"foi atingido o limeite de 100 vertices"<<endl;
    }
}

int Poligono::getVertices()
{
    return vt;
}

void Poligono::imprime()
{
    for(int i= 0; i<vt;i++){
        cout<<"("<< vert[i].getX() <<","<< vert[i].getY()<<")"<<"->";
    }
    cout<<"("<< vert[vt].getX() <<","<< vert[vt].getY()<<")"<<endl;
}

//esse método de calcular a área foi obtido no site:
//http://www.profcardy.com/cardicas/como-obter-area-de-poligono-por-coordenadas.php
float Poligono::area()
{
    int i;
    float ax,bx;
    float area;
    ax=bx=0;
    if(vt>=3){
        for(i=0;i<vt;i++){
           ax += vert[i].getX()*vert[i+1].getY();
           bx += vert[i].getY()*vert[i+1].getX();
        }
        if(ax>bx){
            area = (ax-bx)/2;
        }else
            area = (bx-ax)/2;

        return area;
     }else
        return -1;

}

void Poligono::translada(float a, float b)
{
    int i;
    for(i=0;i<=vt;i++)
        vert[i].translada(a,b);

}

void Poligono::rotaciona(float x0, float y0, float angulo)
{
    double teta;
    float xn, yn;//posição dos pontos em relação ao ponto de referencia
    float nx, ny;//posições dos pontos após a rotação
    float normal, rotacao;//normal e o angulo em radiano para rotação.
    int i; // iterador
    bool flag = true; //sinaliza se será preciso rotacionar o ponto ou nao.

    rotacao = angulo;

    for(i=0; i<vt; i++){
        xn = vert[i].getX()-x0;//posição de x em relação ao eixo.
        yn = vert[i].getY()-y0;//posição de y em relação ao eixo.
        normal = sqrt((xn*xn)+(yn*yn));//pitagoras
        if(xn>0 && yn>0){ //1° quadrante
            teta = atan(yn/xn);
        }else if(xn<0 && yn>0){ //2° quadrante
            teta = PI + atan(yn/xn);
        }else if(xn<0 && yn<0){ //3° quadrante
            teta = PI + atan(yn/xn);
        }else if(xn>0 && yn<0){ //4° quadrante
            teta = 2*PI + atan(yn/xn);
        }else if(xn == 0 && yn>0){
            teta = PI/2;
         }else if(xn == 0 && yn<0){
            teta = -PI/2;
         }else if(xn>0 && yn==0){
            teta = 0;
         }else if(xn<0 && yn==0){
            teta = PI;
        }else{
            flag = false;
        }
        if(flag){
            teta+=rotacao;
            nx = cos(teta)*normal+x0;
            ny = sin(teta)*normal+y0;
        }else{
            nx = xn;
            ny = yn;
        }

        //só ajustando os pontos, a função sin e cos não retorna 0, sempre um numero muito pequeno
        //na faixa de 10^-12
        if(nx>-0.000001 && nx < 0.000001){
           nx = 0;
        }
        if(ny>-0.000001 && ny < 0.000001){
            ny = 0;
        }

        vert[i].setXY(nx,ny);//atualiza o ponto;
    }
    vert[vt]=vert[0];
}


