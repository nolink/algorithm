

#include <stdio.h>


int paths[5][5] = {{0,2,4,3,6}, {2,0,1,5,7}, {4,1,0,8,9}, {3,5,8,0,4}, {6,4,9,7,0}};

int all_visited(int* visited, int size){

	int i=0;
	for(i=0;i<size;i++){
		if(visited[i] == -1){
			return 0;
		}
	}

	return 1;

}

long shortest(int* visited, int size, long current, int last){

	int i=0; long ret=-1;
	if(all_visited(visited, size)){
		return current + paths[visited[0]][visited[last]];
	}

	
	for(i=0;i<size;i++){
		if(visited[i] == -1){
			visited[i] = i;
			int candidate = shortest(visited, size, current+paths[last][i], i);
			printf("i: %d, candidate: %d\n", i, candidate);
			if(ret == -1 || ret > candidate){
				ret = candidate;
			}
			visited[i] = -1;
		}
	}
	return ret;
}



int main(int argc, char const *argv[])
{
	
	int visited[] = {-1,-1,-1,-1,-1};

	printf("%ld\n", shortest(visited, 5, 0, 0));

	return 0;
}
