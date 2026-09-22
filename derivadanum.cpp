double* derivadanum(double h,int nlen, double* x){

    double* d1= new double[nlen];

    for(int i=0; i<nlen;i++){

        if(i==0){
            d1[i]=(x[i+1]-x[i])/h;
        }
        else if(i==nlen-1){
            d1[i]=(x[i]-x[i-1])/h;
        }
        else{

        d1[i]=(x[i+1]-x[i-1])/(2.*h);
        }

    }


    return d1;
}