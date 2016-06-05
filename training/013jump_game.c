
#include <stdio.h>

int board[7][7] = {{2,5,1,6,1,4,1},{6,1,1,2,2,9,3},{7,2,3,2,1,3,1},{1,1,3,1,7,1,2},{4,1,2,3,4,1,2},{3,3,1,2,3,4,1},{1,5,2,9,4,7,0}};

int can_arrive(int x, int y){

	if(x >= 7 || y >= 7){
		return 0;
	}

	if(x == 6 && y == 6){
		return 1;
	}

	int current = board[x][y];

	return can_arrive(x+current, y) || can_arrive(x, y+current);

}

//0为初始，-1为不可达，1为可达
int cache[7][7] = {{0},{0},{0},{0},{0},{0},{0}};

int can_arrive_2(int x, int y){

	if(x >= 7 || y >= 7){
		return 0;
	}

	if(x == 6 && y == 6){
		return 1;
	}

	int* current = &cache[x][y];

	if(*current != 0){
		return *current == 1 ? 1 : 0;
	}

	return (*current = (can_arrive_2(x+board[x][y], y) || can_arrive_2(x, y+board[x][y])) ? 1 : -1) == 1 ? 1 : 0;

}


int main(int argc, char const *argv[])
{
	
	printf("%d\n", can_arrive(0,0));

	printf("%d\n", can_arrive_2(0,0));

	return 0;
}
