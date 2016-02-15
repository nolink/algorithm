int uniquePaths(int m, int n) {
    
    if(m <= 0 || n <= 0){
		return 0;
	}

	if(m == 1 || n == 1){
		return 1;
	}
    
    int paths[m][n];
    int i=0;
    int j=0;
    
    for(i=m-1,j=0;j<n-1;j++){
        paths[i][j] = 1;
    }
    
    for(i=0,j=n-1;i<m-1;i++){
        paths[i][j] = 1;
    }
    
   	for(i=m-2;i>=0;i--){
   		for(j=n-2;j>=0;j--){
   			paths[i][j] = paths[i][j+1] + paths[i+1][j];
   		}
   	}

   	return paths[0][0];
    
}