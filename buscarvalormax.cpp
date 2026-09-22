double buscarvalormax(matrix<double> A,int& im, int& jm){
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


return max;

}



