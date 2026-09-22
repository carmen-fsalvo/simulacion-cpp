matrix<double> jacobidiagonalizacion (matrix<double> A, int im, int jm, double tolerancia, double max,matrix<double>& U) {

cout << " A: " << endl << A << endl;

int n= A.rowno();

int contador=0;

double theta;

matrix<double> R(n,n);R.unit();
//matrix<double> U(n,n);U.unit();
matrix<double> Anew(n,n);Anew.unit();
Anew=A;


  
 
do{
    A=Anew;

    //vusco valor maximo de A=Anew con el código usado para crear la función buscarvalormax:

    int n=A.rowno();
    double max=0;
    for(int i=0; i<n; ++i){
    for (int j=0; j<n; ++j){
        if(i<j){
            if(abs(A(i,j))>max){
                max=abs(A(i,j));
                im=i;
                jm=j;
            }

        }
    }
    }


    if(A(im,im)== A(jm,jm)){
    double theta=atan(1);

   

    }
    else{
    double theta=0.5*atan(2*A(im,jm)/(A(im,im)-A(jm,jm)));

    }

    R(im,im)=cos(theta);
    R(im,jm)=-sin(theta);
    R(jm,im)=sin(theta);
    R(jm,jm)=cos(theta);


 Anew = (~R)*A*R; // matriz de autovalores


 U=U*R; // matriz de autovectores


 contador++ ;

} while (max>tolerancia);
cout << "ey" << endl;
cout << "matriz de autovectores: "<< U << endl;

return Anew;


}