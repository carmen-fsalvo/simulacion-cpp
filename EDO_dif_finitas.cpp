#include <iostream> 
#include <fstream>  
#include <string>
#include <iomanip>

using namespace std;

#include <cmath>
#include "cmatrix"

using namespace techsoft;

#include "metodolu2_c.cpp"

const double r0 = 5. ;
const double rf = 10. ;
const double u0 = 110. ; // u(r0) = u0
const double uf = 0. ; // u(rf) = uf

matrix<double> pvector(double h) {
	
	int n = (rf-r0)/h ; 
	double r=r0 ;
	matrix<double> p(n,1);
	
	for (int i = 0; i<n ; ++i){
		
		p(i,0) = -2./r ;
		r+=h ;	
	}
	
	return p  ;
}

double q(double r) {
	return 0. ;
}

double s(double r) {
	return 0. ;
}


void diferenciasfinitas (matrix<double> p, double (*q) (double), double (*s) (double), double h, double a, double b, double x0, double xf, int m){
	
	int n = (xf-x0)/h ;
	
	matrix <double> A(n-1,n-1); A.null() ;
	matrix <double> B(n-1,1); B.null() ;
	
	if (m ==1){
		string infile1 = "p13potencial1.txt";
		ofstream ffa(infile1);
		
		if(ffa.is_open()){
		}else cout << "No se ha podido abrir el fichero " << infile1 << endl;
		
		ffa << r0 << " " << a << endl; // 
		
		for (int i=0 ; i<=(n-2); ++i){
			for (int j=0 ; j<=(n-2); ++j){
				if (i == j){
					A(i,j) = 2+h*h*q(i) ;
				}
				else if (i == (j-1)) {
					A(i,j) = (h/2.)*p(i,0)-1 ;
				}
				else if (i == (j+1)) {
					A(i,j)= -((h/2.)*p(i,0)+1) ;
				}
			}
			
			if (i == 0){
				B(i,0) = -h*h*s(i) + ((h/2.)*p(i,0)+1)*a;
			}
			else if (i == (n-2)) {
				B(i,0) = -h*h*s(i) - ((h/2.)*p(i,0)-1)*b;
			}
			else {
				B(i,0) = -h*h*s(i) ;
			}
		}
			
		matrix <double> complu = metodolu2(A,B) ;
		
		cout << complu << endl;
		
		matrix <double> w(n-1,1); w.null() ;
		double k = r0 ;
		
		for (int i=0 ; i<(n-1); ++i){
			
			w(i,0) = k + h;	
			k = k+h ;
		}
		
		for (int i=0 ; i<(n-1); ++i){
			
			ffa << w(i,0) << " " << complu(i,0) << endl; 	
		}
		
		ffa << rf << " " << b << endl; // meto valores finales
			
		ffa.close();
	}
	else{
		string infile2 = "p13potencial2.txt";
		ofstream ffb(infile2);
		
		if(ffb.is_open()){
		}else cout << "No se ha podido abrir el fichero " << infile2 << endl;
		
		ffb << r0 << " " << a << endl; // 
		
		for (int i=0 ; i<=(n-2); ++i){
			for (int j=0 ; j<=(n-2); ++j){
				if (i == j){
					A(i,j) = 2+h*h*q(i) ;
				}
				else if (i == (j-1)) {
					A(i,j) = (h/2.)*p(i,0)-1 ;
				}
				else if (i == (j+1)) {
					A(i,j)= -((h/2.)*p(i,0)+1) ;
				}
			}
			
			if (i == 0){
				B(i,0) = -h*h*s(i) + ((h/2.)*p(i,0)+1)*a;
			}
			else if (i == (n-2)) {
				B(i,0) = -h*h*s(i) - ((h/2.)*p(i,0)-1)*b;
			}
			else {
				B(i,0) = -h*h*s(i) ;
			}
		}
			
		matrix <double> complu = metodolu2(A,B) ;
		
		cout << complu << endl;
		
		matrix <double> w(n-1,1); w.null() ;
		double k = r0 ;
		
		for (int i=0 ; i<(n-1); ++i){
			
			w(i,0) = k + h;	
			k = k+h ;
		}
		
		for (int i=0 ; i<(n-1); ++i){
			
			ffb << w(i,0) << " " << complu(i,0) << endl; 	
		}
		
		ffb << rf << " " << b << endl; // meto valores finales
			
		ffb.close();	
	}
	
	// cout << A << "\n\n" << B << endl ;
}


int main (){
	
	// double h = 1;
	// diferenciasfinitas(p,q,s,h,u0,uf,r0,rf) ;
	
	double h1 = 0.05 , h2 = 0.02 ;
	
	matrix<double> p1 = pvector(h1) ;
	matrix<double> p2 = pvector(h2) ;
	
	cout << "Resultados para h=0.05:\n" << endl ;
	diferenciasfinitas(p1,q,s,h1,u0,uf,r0,rf,1) ;
	
	cout << "Resultados para h=0.02:\n" << endl ;
	diferenciasfinitas(p2,q,s,h2,u0,uf,r0,rf,2) ;
	
	return 0 ;
	
}