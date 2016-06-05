

#include <stdio.h>
#include <stdlib.h>

//左上，上，右上，左，右，左下，下，右下
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int token_exists(char** matrix, int sizeX, int sizeY, int fromX, int fromY, char* token, int sizeT, int idx){

	if(fromX < 0 || fromX > sizeX - 1 || fromY < 0 || fromY > sizeY - 1){
		return 0;
	}

	if(matrix[fromX][fromY] != token[idx]){
		return 0;
	}

	if(idx == sizeT - 1){
		return 1;
	}

	idx++;
	int i=0;
	for(i=0;i<8;i++){
		if(token_exists(matrix, sizeX, sizeY, fromX+dx[i], fromY+dy[i], token, sizeT, idx)){
			return 1;
		}
	}
	return 0;

	// if(fromX > 0){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX-1, fromY, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(fromX < sizeX - 1){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX+1, fromY, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(fromY > 0){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX, fromY-1, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(fromY < sizeY - 1){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX, fromY+1, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(fromX > 0 && fromX < sizeX - 1){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX-1, fromY-1, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(fromX > 0 && fromY < sizeY - 1){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX-1, fromY+1, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(visited[fromX][fromY][6] == 0){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX+1, fromY-1, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }
	// if(visited[fromX][fromY][7] == 0){
	// 	if(token_exists(matrix, sizeX, sizeY, fromX+1, fromY+1, token, sizeT, idx)){
	// 		return 1;
	// 	}
	// }

	// return 0;
}

int main(int argc, char const *argv[])
{
	char** matrix = (char**)malloc(sizeof(char*)*5);

	matrix[0] = "URLPM";
	matrix[1] = "XPRET";
	matrix[2] = "GIAET";
	matrix[3] = "XTNZY";
	matrix[4] = "XOQRS";

	printf("%d\n", token_exists(matrix, 5, 5, 2, 2, "GIRL", 4, 0));

	return 0;
}


