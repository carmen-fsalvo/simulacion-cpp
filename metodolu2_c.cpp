matrix<double> metodolu2 (matrix<double> A, matrix<double> b) { // lo que entra entre parentesis

	int n = A.rowno() ;
	
	matrix<double> d(n,1) ; d.null() ;
	matrix<double> ds(n,1) ; ds.null() ;
	ds(n-1,0) = 0. ;
	matrix<double> df(n,1) ; df.null() ;
	df(n-1,0) = 0. ;
	
	matrix<double> L(n,n); L.unit() ;
	matrix<double> U(n,n); U.null() ;
	matrix<double> z(n,1); z.null() ;
	matrix<double> x(n,1); x.null() ;
	
	// saco las diagonales
	
	for (int i=0; i<n; ++i){
		
		for (int j=0; j<n; ++j){
			
			if(i == j){	
				d(i,0) = A(i,j) ;	
			}
			else if(i == j-1){
				ds(i,0) = A(i,j) ;
			}
			else if(i == j+1){
				df(i,0) = A(i,j) ;
			}
		}	
	}
	
	// creo deltas
	
	matrix<double> delta(n,1); delta.null() ;
	delta(0,0) = d(0,0) ;
	matrix<double> deltaf(n,1); deltaf.null() ;
	deltaf(0,0) = 0. ;
	
	for (int i=1; i<n; ++i){
			
		deltaf(i,0) = df(i,0)/delta(i-1,0) ;
		delta(i,0) = d(i,0)-deltaf(i,0)*ds(i-1,0) ;
	}
	
	
	// matriz L
	
	for (int i=0; i<n; ++i){
		
		for (int j=0; j<n; ++j){
			
			if(i == j+1){	
				L(i,j) = deltaf(i,0) ;	
			}
		}	
	}
	
	
	// matriz U
	
	for (int i=0; i<n; ++i){
		
		for (int j=0; j<n; ++j){
			
			if(i == j){	
				U(i,j) = delta(i,0) ;	
			}
			else if(i == j-1){
				U(i,j) = ds(i,0) ;
			}
		}	
	}
	
	// cout << A << "\n\n" << b ; 
	// cout << d << "\n\n" << ds << "\n\n" << df << "\n\n"   ;
	// cout << deltaf << "\n\n" << delta << "\n\n" ;
	// cout << U << endl ;
	
	// obtengo z, resuelvo por sustitucion regresiva
	for (int i=0;i<=(n-1);++i){
		double sum=0.0;
		for (int j=0;j<=i-1;j++){
			sum=sum+L(i,j)*z(j,0);
			}
		z(i,0)=b(i,0)-sum;
	}
	
	// obtengo x de la misma manera
	for (int i=(n-1); i>=0; --i){
	 	double sum=0.0;
	 	for (int j=i+1; j<=n-1; j++){
	 		sum=sum+U(i,j)*x(j,0);
			}	
		x(i,0)=(z(i,0)-sum)/U(i,i);
	} 
	
	return x;
}