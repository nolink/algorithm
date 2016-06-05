

#include <stdio.h>
#include <stdlib.h>


int cover(int* colors[], int rows, int cols){

	int i=0,j=0;

	int white_count=0, first_white_row=-1, first_white_col=-1;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(colors[i][j] == 0){
				if(first_white_row == -1 && first_white_col == -1){
					first_white_row = i;
					first_white_col = j;
				}
				white_count++;
			}
		}
	}

	if(white_count % 3 != 0){
		return 0;
	}

	if(first_white_row == -1 && first_white_col == -1){
		return 1;
	}

	int result=0;

	
	colors[first_white_row][first_white_col] = 1;

	//第一个点，向右，第二个点在右下
	if(first_white_col + 1 < cols && colors[first_white_row][first_white_col + 1] == 0 
		&& first_white_row + 1 < rows &&  colors[first_white_row+1][first_white_col + 1] == 0 ){
		colors[first_white_row][first_white_col+1] = 1;
		colors[first_white_row+1][first_white_col+1] = 1;

		result += cover(colors, rows, cols);

		colors[first_white_row][first_white_col+1] = 0;
		colors[first_white_row+1][first_white_col+1] = 0;
	}
	

	//第一个点，向下
	if(first_white_row + 1 < rows && colors[first_white_row+1][first_white_col] == 0){
		colors[first_white_row+1][first_white_col] = 1;
		if(first_white_col - 1 >= 0 && colors[first_white_row+1][first_white_col-1] == 0){
			//第二个点在左下
			colors[first_white_row+1][first_white_col-1] = 1;
			result += cover(colors, rows, cols);
			colors[first_white_row+1][first_white_col-1] = 0;
		}
		if(first_white_col + 1 < cols && colors[first_white_row+1][first_white_col+1] == 0){
			//第二个点向右
			colors[first_white_row+1][first_white_col+1] = 1;
			result += cover(colors, rows, cols);
			colors[first_white_row+1][first_white_col+1] = 0;
		}

		colors[first_white_row+1][first_white_col] = 0;
	}

	//第一个点，向右，第二个点，向下
	if(first_white_row + 1 < rows && colors[first_white_row+1][first_white_col] == 0
		&& first_white_col + 1 < cols && colors[first_white_row][first_white_col+1] == 0){
		colors[first_white_row+1][first_white_col] = 1;
		colors[first_white_row][first_white_col+1] = 1;

		result += cover(colors, rows, cols);

		colors[first_white_row+1][first_white_col] = 0;
		colors[first_white_row][first_white_col+1] = 0;
	}

	colors[first_white_row][first_white_col] = 0;

	return result;

}

int main(int argc, char const *argv[])
{
	
	// printf("type the case count: ");

	// int case_count;
	// scanf("%d", &case_count);

	// int i=0, j=0, k=0;
	// int height;
	// int width;
	// int** colors;
	// for(i=0;i<case_count;i++){
	// 	printf("type height and width for case %d: ", i);

 //        scanf("%d", &height);
 //        getchar();
 //        scanf("%d", &width);

 //        colors = (int**)malloc(sizeof(int)*height);
 //        char* tmp = (char*)malloc(sizeof(char)*width);
        
 //        for(j=0;j<height;j++){
 //        	printf("line %d: ", j+1);
 //        	colors[j] = (int*)malloc(sizeof(int)*width);
 //        	gets(tmp);
 //        	for(k=0;k<width;k++){
 //        		colors[j][k] = tmp[k] == '#' ? 1 : 0;
 //        	}
 //        }

 //        printf("%d\n", cover(colors, height, width));

 //        free(tmp);

 //        for(j=0;j<height;j++){
 //        	free(colors[j])
 //        }

 //        free(colors);
	// }


	int i=0;

	int case1[][7] = {{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,1,0,0,0,1,1}};

	int** p1 = (int**)malloc(sizeof(int*)*3);
	for(i=0;i<3;i++){
		p1[i] = case1[i];
	}

	printf("%d\n", cover(p1, 3, 7));

	free(p1);

	int case2[][7] = {{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,1,0,0,1,1,1}};
	int** p2 = (int**)malloc(sizeof(int*)*3);
	for(i=0;i<3;i++){
		p2[i] = case2[i];
	}

	printf("%d\n", cover(p2, 3, 7));
	free(p2);

	int case3[][10] = {{1,1,1,1,1,1,1,1,1,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,0,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1}};

	int** p3 = (int**)malloc(sizeof(int*)*8);
	for(i=0;i<8;i++){
		p3[i] = case3[i];
	}

	printf("%d\n", cover(p3, 8, 10));
	free(p3);

	return 0;
}
