#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
#include <cmatrix>
using namespace techsoft;

int main(){
  // Nombre del fichero que contiene la matriz
  string infile = "matrizA.txt";

  // Abrimos el fichero para leerlo
  ifstream ff(infile);
  if (ff.is_open()){
    // Leemos el número de filas y columnas de la matriz
    // en la primera línea del directorio
    int nrows=0, ncols=0;
    ff >> nrows >> ncols;

    // Declaramos y leemos la matriz
    matrix<double> A(nrows,ncols);
    ff >> A;
    
    ff.close();
    
    




  }else cout <<"No se ha podido abrir el fichero " << infile << endl;

    // Nombre del fichero que contiene la matriz
  string infile = "vectorb.txt";

  // Abrimos el fichero para leerlo
  ifstream ff(infile);
  if (ff.is_open()){
    // Leemos el número de filas y columnas de la matriz
    // en la primera línea del directorio
    int nrows=0, ncols=0;
    ff >> nrows >> ncols;

    // Declaramos y leemos la matriz
    matrix<double> b(nrows,ncols);
    ff >> b;
    
    ff.close();
    


  return 0;
}
}
















