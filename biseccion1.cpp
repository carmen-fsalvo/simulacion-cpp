#include <iostream>
#include <cmath>
#include <string>
using namespace std;



double bisectriz(double (*f)(double), double x1, double x2, double tolerancia, int contador){
    double x3;
    int contador=0;

  if (f(x1)*f(x2)<0){
    do  {
        
        x3=(x1+x2)/2;
        if (f(x3)*f(x1)<0){
            x2=x3;
            contador=contador+1;

        }
        else {
            x1=x3;
        }

    } while (fabs(x2-x1)> 2*tolerancia || fabs(f(x3)) > tolerancia);

    
    return x3;
  }
  else{
    
    cout << "x1 y x2 no validos pues f(x1)*f(x2)>0" << endl;
    return 0;
  }

}



double f(double x){

    return  -24*((pow(x,-7))*(2*pow(x,-6)-1));}



int main(){

    double x1, x2, x3, tolerancia=pow(10,-12);
    int contador=0;

    cout << "Escribir un número x1 para determinar el intervalo [x1,x2]: " << endl;
    cin >> x1;

    cout << "Escribir un número x2 para determinar el intervalo [x1,x2]: " << endl;
    cin >> x2;

    // Utilizo la función bisectriz creada anteriormente:

    cout << bisectriz(f, x1, x2, tolerancia, contador) << endl;



    return 0;
}











