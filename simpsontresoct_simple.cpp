#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#define pi (4*atan(1))
#define num_int 30
using namespace std;



double func(double tmax,double phi){
    double k=0.;
    k=sin(tmax/2);
  double func=(2/pi)/(sqrt(1-(k*k*pow(sin(phi),2))));
return func;
}

double trapecio(double a,double b,double (*func) (double,double),double tmax, double phi){

    double sum=0.;
    double fa=func(tmax,a);
    double fb=func(tmax,b);
    double h=0.;
    double I=0.;
    h=(b-a)/num_int;
   
    for(int i=1;i<num_int;++i){

        sum=sum+func(tmax,(a+i*h));

    }

    I=(h/2)*(fa+2*sum+fb);
    
    return I;
}

double simpsontercio_simple(double a,double b,double (*func) (double,double),double tmax, double phi){
    double S_ter=0.;
    double fa=func(tmax,a);
    double fb=func(tmax,b);
    double h=(b-a)/2;

    //metodo simple:
   S_ter=h/3.*(fa+4*func(tmax,(a+b)/2)+fb);
  

    return S_ter;
}

double simpsontercio_complex(double a,double b,double (*func) (double,double),double tmax, double phi){
    double I_ter=0.;
    double sum=0.;
    double fa=func(tmax,a);
    double fb=func(tmax,b);
    double h=(b-a)/num_int;

    //método compuesto:
    for(int i=1;i<num_int;++i){
    
    if (i%2==0){
        sum=sum+2*func(tmax,(a+i*h));
    }
    else{
        sum=sum+4*func(tmax,(a+i*h));
    }
    }

    I_ter=h/3.*(fa+sum+fb);

    return I_ter;
}

double simpsontresoct_simple(double a,double b,double (*func) (double,double),double tmax, double phi){
    double S_tresoct=0.;
    double fa=func(tmax,a);
    double fb=func(tmax,b);
    double h=(b-a)/3;

    //metodo simple:
   S_tresoct=3*h/8.*(fa+3*func(tmax,(2*a+b)/3)+3*func(tmax,(a+2*b)/3)+fb);
  

    return S_tresoct;
}

double simpsontresoct_complex(double a,double b,double (*func) (double,double),double tmax, double phi){
    double I_tresoct=0.;
    double sum=0.;
    double fa=func(tmax,a);
    double fb=func(tmax,b);
    double h=(b-a)/num_int;

    //método compuesto:
    for(int i=1;i<num_int;++i){
    
    if (i%3==0){
        sum=sum+2*func(tmax,(a+i*h));
    }
    else{
        sum=sum+3*func(tmax,(a+i*h));
    }
    }

    I_tresoct=3*h/8.*(fa+sum+fb);

    return I_tresoct;
}

int main(){

    

    double phi,tmax=0;
    double a=0.;
    double b=pi/2.;
    double I[31], S_ter[31], I_ter[31] ,S_tresoct[31],I_tresoct[31];
    

    //double a =func(tmax,phi);
    
    for(tmax=0.;tmax<((5.*pi)/6.);tmax=(tmax+(pi/36.))){
   int i = tmax*36./pi;
    I[i]=trapecio(a,b,func,tmax,phi);
    S_ter[i]=simpsontercio_simple(a,b,func,tmax,phi);
    I_ter[i]=simpsontercio_complex(a,b,func,tmax,phi);
    S_tresoct[i]=simpsontresoct_simple(a,b,func,tmax,phi);
    I_tresoct[i]=simpsontresoct_complex(a,b,func,tmax,phi);

    cout << "ángulo: "<< tmax*180./pi << " ; posición en la que se guarda: " << i << endl << "Soluciones de trapecio: " <<I[i] << endl << "soluciones de Simpson 1/3 simple: " << S_ter[i] << endl << "Soluciones de Simpson 1/3 compuesto: " <<I_ter[i] << endl << "soluciones de Simpson 3/8 simple: " <<S_tresoct[i] << endl << "soluciones de Simpson 3/8 compuesto: " <<I_tresoct[i] << endl;
    }

    

    std::ofstream file2("P7_T13c.txt");
    for (int j = 0; j < 31; j++) {
    file2 << I_ter[j] << ", ";
    }
    file2.close();

    std::ofstream file3("P7_T38c.txt");
    for (int j = 0; j < 31; j++) {
    file3 << I_tresoct[j] << ", ";
    }
    file3.close();

    std::ofstream file4("P7_Ttrapecio.txt");
    for (int j = 0; j < 31; j++) {
    file4 << I[j] << ", ";
    }
    file4.close();

    std::ofstream file5("P7_T13s.txt");
    for (int j = 0; j < 31; j++) {
    file5 << S_ter[j] << ", ";
    }
    file5.close();

    std::ofstream file6("P7_T38s.txt");
    for (int j = 0; j < 31; j++) {
    file6 << S_tresoct[j] << ", ";
    }
    file6.close();

    

    return 0;
}
