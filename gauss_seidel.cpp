matrix<double> gauss_seidel(matrix<double> A, matrix<double> b,double tolerancia, int& iteraciones){
int n= A.rowno();
matrix<double> x(n,1); x.null();
matrix<double> xold=x;
double diferencia=0.;


do{
for(int i=0; i<n; ++i){
    double sum1=0., sum2=0.;
    for(int j=0; j<i-1; ++j){
        
            sum1+= A(i,j)*x(j,0);
            
         }
    for (int j=i+1; j<n;++j){
        sum2+= A(i,j)*x(j,0);
    }

    double xnew=(b(i,0)-sum1-sum2)/A(i,i);
    x(i,0)=xnew;

    diferencia=fabs(x(i,0)-xold(i,0));

    xold=x;
    
    int iteraciones=iteraciones +1;

}  
}while(diferencia < tolerancia);
return x;

}
