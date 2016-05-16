

#include <stdio.h>


int triangle_path(int data[5][5], int cache[5][5], int x, int y){

	if(x >= 5 || y >= 5){
		return 0;
	}

	int* ret = &cache[x][y];

	if(*ret > 0){
		return *ret;
	}

	int current = data[x][y];

	int down = triangle_path(data, cache, x, y+1);
	int right = triangle_path(data, cache, x+1, y);

	return (*ret = down > right ? down + current : right + current);

}


int main(int argc, char const *argv[])
{
	int case1[5][5] = {{6,-1,-1,-1,-1},{1,2,-1,-1,-1},{3,7,4,-1,-1},{9,4,1,7,-1},{2,7,5,9,4}};
	int case2[5][5] = {{1,-1,-1,-1,-1},{2,4,-1,-1,-1},{8,16,8,-1,-1},{32,64,32,64,-1},{128,256,128,256,128}};

	int cache1[5][5] = {{0},{0},{0},{0},{0}};
	int cache2[5][5] = {{0},{0},{0},{0},{0}};

	printf("%d\n", triangle_path(case1, cache1, 0, 0));
	printf("%d\n", triangle_path(case2, cache2, 0, 0));

	return 0;
}
