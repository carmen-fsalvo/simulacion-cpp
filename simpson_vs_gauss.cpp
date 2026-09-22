#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std; 


const double pi=(4*atan(1));
const double R = 6.96e10;      // Å^(-1)
const double a = 1.2e-23;      // J s^(-1) cm^(-2) Å^(-1)
const double b = 1215.16;      // Å
const double sigma = 50;       // Å
const double h = 6.626e-34;    // J s
const double c = 2.998e18;     // Å s^(-1)
const double x0 = 0.;
const double xf = 912.;

using namespace std;

double simpsontercio_complex(double (*f) (double),double num_int){
    double I_ter=0.;
    double sum=0.;
    double fa=f(x0);
    double fb=f(xf);
    double in=(xf-x0)/num_int;

    //método complejo:
    for(int i=1;i<num_int;++i){
    
    if (i%2==0){
        sum=sum+2*f(x0+i*in);
    }
    else{
        sum=sum+4*f(x0+i*in);
    }
    }

    I_ter=(in/3.)*(fa+sum+fb);

    return I_ter;
}

double func(double lambda){

    double func=(lambda/(h*c))*a*exp(-(pow(lambda-b,2))/(2*sigma*sigma));

    return func;
}

double  cuad_gauss(double num_int, double(*func)(double)){

    double x[5]={0,(1/3.)*sqrt(5-2*sqrt(10/7.)),-(1/3.)*sqrt(5-2*sqrt(10/7.)),(1/3.)*sqrt(5+2*sqrt(10/7.)),-(1/3.)*sqrt(5+2*sqrt(10/7.))};
    double w[5]={(128/225.),((322+13*sqrt(70))/900.),((322+13*sqrt(70))/900.) ,((322-13*sqrt(70))/900.),((322-13*sqrt(70))/900.)};
    double sum=0.;

    for (int i=0; i<5; ++i){

        sum=sum+(w[i]* func(((b-a)/2.)*x[i]+((a+b)/2.)));

    
    }
    double integral= ((b-a)/2.)*sum;
    return integral;
}
// Gaussian quadrature with 5 points
double gaussian_quadrature(double (*func)(double), double a, double b, int n) {
    double x[] = {-0.90617985, -0.53846931, 0, 0.53846931, 0.90617985};
    double w[] = {0.23692689, 0.47862867, 0.56888889, 0.47862867, 0.23692689};

    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += w[i] * func(0.5 * (b - a) * x[i] + 0.5 * (b + a));
    }

    return 0.5 * (b - a) * result;
}


int main(){

    double num_int=150.,n=5;
    double I_ter=0,I_gauss=0, Qsimpson=0,Qgauss=0,Qgauss2=0;
    I_ter=simpsontercio_complex(func,num_int);
    Qgauss=cuad_gauss(num_int,func);
    Qgauss2=gaussian_quadrature(func,a,b,n);
    Qsimpson=4*pi*R*R*I_ter;

    cout << "Solución por el método de Simpson: " << Qsimpson << endl << "Solución por el método de Gauss: " << Qgauss << endl;


    return 0;
}

