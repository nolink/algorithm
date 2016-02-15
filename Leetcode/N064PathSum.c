int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    
    if(NULL == grid){
        return 0;
    }
    
    int i=0;
    int j=0;
    if(gridRowSize == 1 && gridColSize == 1){
        return grid[0][0];
    }else if(gridRowSize == 1 && gridColSize != 1){
        for(i=1;i<gridColSize;i++){
            grid[0][0] += grid[0][i];
        }
        return grid[0][0];
    }
    else if(gridRowSize != 1 && gridColSize == 1){
        for(i=1;i<gridRowSize;i++){
            grid[0][0] += grid[i][0];
        }
        return grid[0][0];
    }
    
    
    for(i=gridRowSize-2;i>=0;i--){
        grid[i][gridColSize-1] += grid[i+1][gridColSize-1];
    }
    
    for(j=gridColSize-2;j>=0;j--){
        grid[gridRowSize-1][j] += grid[gridRowSize-1][j+1];
    }
    
    for(i=gridRowSize-2;i>=0;i--){
        for(j=gridColSize-2;j>=0;j--){
            grid[i][j] += grid[i][j+1] > grid[i+1][j] ? grid[i+1][j] : grid[i][j+1];
        }
    }
    
    return grid[0][0];
}