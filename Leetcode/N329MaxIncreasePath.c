int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize) {
    int** lenMatrix = (int**)malloc(sizeof(int*)*matrixRowSize);
    
    int i=0;
    int j=0;
    int result = 1;
    
    for(;i<matrixRowSize;i++){
        lenMatrix[i] = (int*)malloc(sizeof(int)*matrixColSize);
        for(j=0;j<matrixColSize;j++){
            if(i == 0 && j == 0){
                lenMatrix[i][j] = 1;
            }else if(i == 0 && j > 0){
                lenMatrix[i][j] = matrix[i][j] > matrix[i][j-1] ? (lenMatrix[i][j-1] + 1) : 1;
            }else if(i > 0 && j == 0){
                lenMatrix[i][j] = matrix[i][j] > matrix[i-1][j] ? (lenMatrix[i-1][j] + 1) : 1;
            }
            else{
                int topDown = matrix[i][j] > matrix[i-1][j] ? (lenMatrix[i-1][j] + 1) : 1;
                int leftRight = matrix[i][j] > matrix[i][j-1] ? (lenMatrix[i][j-1] + 1) : 1;
                lenMatrix[i][j] = (topDown > leftRight) ? topDown : leftRight;
            }
            if(result < lenMatrix[i][j]){
                result = lenMatrix[i][j];
            }
        }
    }

    for(i=0;i<matrixRowSize;i++){
        free(lenMatrix[i]);
    }
    
    free(lenMatrix);
    
    return result;
}


int main(int argc, char const *argv[])
{
    
    int** matrix = (int**)malloc(sizeof(int*)*3);

    
    matrix[0] = (int*)malloc(sizeof(int)*3);
    matrix[0][0] = 7;
    matrix[0][1] = 8;
    matrix[0][2] = 9;
    
    matrix[1] = (int*)malloc(sizeof(int)*3);
    matrix[1][0] = 9;
    matrix[1][1] = 7;
    matrix[1][2] = 6;

    matrix[2] = (int*)malloc(sizeof(int)*3);
    matrix[2][0] = 7;
    matrix[2][1] = 2;
    matrix[2][2] = 3;

    printf("%d\n", longestIncreasingPath(matrix,3,3));

    return 0;
}