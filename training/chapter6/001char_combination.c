
#include <stdio.h>


/* how many combinations can be, the combination length will be m
   example:
      chars: [1,2,3,4]
      len: 4
      step: 2
    print result:
      12,13,14,23,24,34

 */
void print_combination(int* chars, int len, int m, int* visitedIdx, int visitedLen){

	int i=0;
	if(m == 0){
		for(i=0;i<visitedLen;i++){
			printf("%d", chars[visitedIdx[i]]);
		}
		printf("\n");
		return;
	}

	int smallest = visitedLen == 0 ? 0 : visitedIdx[visitedLen-1] + 1;

	for(i=smallest;i<len;i++){
		visitedIdx[visitedLen] = i;
		print_combination(chars, len, m-1, visitedIdx, visitedLen+1);
	}

}


int main(int argc, char const *argv[])
{
	
	int chars[4];
	int visited[4];
	int i = 0;
	for(;i<4;i++){
		chars[i] = i+1;
		visited[i] = i+1;
	}

	print_combination(chars, 4, 2, visited, 0);

	return 0;
}