#include <iostream>
#include <cstdlib>
#include "list_vector.h"
#include "polinomio.h"

using namespace std;


int main()
{
    int x=2;
    polynomial<int> polinomio1;
    polynomial<int> polinomio2;
    int grado1=5;
    int grado2=4;
    int coefficienti1[6]={2,-3,4,0,-2,12};
    int coefficienti2[5]={1,4,5,2,-3};
    polinomio1.input(grado1,coefficienti1);
    polinomio1.output();
    system("pause");
    cout<<"\n\nIl valore di polinomio calcolato in "<<x<<" e':"<<polinomio1.valore(x);
    polinomio2.input(grado2,coefficienti2);
    polinomio2.output();
    polinomio1.somma(polinomio2);
    cout<<"\n\nSomma dei due polinomi:";
    polinomio1.output();
    cout<<"\n\nIl valore di polinomio somma in "<<x<<" e':"<<polinomio1.valore(x);
    polynomial<int> polinomio3;
    polynomial<int> polinomio4;
    int grado3=2;
    int grado4=1;
    int coefficienti3[3]={2,3,4};
    int coefficienti4[2]={3,1};
    polinomio3.input(grado3,coefficienti3);
    polinomio4.input(grado4,coefficienti4);
    polinomio3.output();
    polinomio4.output();
    polinomio3.moltiplica(polinomio4);
    polinomio3.output();
    polinomio4=polinomio3;
    polinomio4.output();
    polynomial<float> polinoimio5;
    float coefficienti5[3]={2.345,4.567,0.500};
    polinoimio5.input(grado3,coefficienti5);
    polinoimio5.output();
    cout<<"IL valore e'"<<polinoimio5.valore(3);
    return 0;
}
