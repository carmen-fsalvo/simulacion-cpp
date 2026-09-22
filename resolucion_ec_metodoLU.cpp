#include <iostream> 
#include <fstream>  
#include <string>
#include <iomanip>

using namespace std;

#include <cmath>
#include <cmatrix>

using namespace techsoft;

#include "metodolu_triagonal.cpp"




double q(double x){
    return 0.;
}
matrix<double> vector_p(double a,int n,double h){
    double x=a;
    matrix<double> p(n,1);
    for(int i=0.;i<n;++i){
        p(i,0)=-2./x;
        x+=h;
    }
    return p;
}
double r(double x){
    return 0.;
}

matrix<double> finite_diff(matrix<double> p,double (*q) (double),double (*r) (double) ,double h, double a, double b,double u0,double un){
double n=(b-a)/h;
matrix<double> A(n-1,n-1); A.null();
matrix<double> B(n-1,1); B.null();
matrix<double> u(n-1,1); u.null();
for(int i=0;i<=n-2;++i){
    for(int j=0;j<=n-2;++j){
    
    if(i==j){
        A(i,j)=2+(h*h*q(i));
    }
    else if(j==i+1){
        A(i,j)=(p(i,0)*h/2.)-1;
    }
    else if(j==i-1){
        A(i,j)=-((h/2.*p(i,0))+1);
    }

    }

    if(i==0){
        B(i,0)= (-h*h*r(i)) + ((h/2.*p(i,0))+1)*u0;
    }
    else if(i==n-2){
        B(i,0)= (-h*h*r(i)) - ((h/2.*p(i,0))-1)*un;
    }

    else{ B(i,0)= -h*h*r(i);}
   


    }
    cout << "A: " << A << endl << "B: " << B << endl;
    // Ahora resulevo la ecuación Au=B con el método de LU que me dará el vector u desde la segunda posición hasta la penúltima:

    u=metodolu_triagonal(A,B);

    
    cout << "u: " << endl << u << endl;
    return u;

}

int main(){


    double h=1.,a=5.,b=10.,u0=110.,un=0.,n=(b-a)/h;
  
    matrix<double> u((b-a)/h,1);u.null();
    matrix<double> p=vector_p(a,n,h);
    
    u=finite_diff(p,q,r,h,a,b,u0,un);




    return 0;
}
