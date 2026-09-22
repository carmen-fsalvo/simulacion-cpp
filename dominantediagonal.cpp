double dominantediagonal(matrix<double> A){
int n=A.nrowno();
double sum1=0, sum2=0;

for(int i=0; i<n;++i){
    for(int j=0;j<n;++j){
      if(int i!=j){
        sum1=sum1+A(i,j);
    
       }
       else {sum2=sum2+A(i,j);}

    }
}
if(sum2>sum1){
    return "La matriz es dominante diagonal"
}

else{return "La matriz no es dominante diagonal"}

}