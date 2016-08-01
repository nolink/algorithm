

#include <stdio.h>
#include <stdlib.h>

void euler_trail(int here, int graph[26][26], int counter[26], int* trail_count){
	for(int there=0;there<26;there++){
		if(counter[there] && graph[here][there]){
			graph[here][there]--;
			euler_trail(there, graph, counter, trail_count);
		}
	}
	(*trail_count)++;
}

int can_chain(char** words, int count){

	int graph[26][26] = {0};
	int counter[26] = {0};

	int i=0, j=0, k=0;

	for(i=0;i<count;i++){
		graph[words[i][0] - 'a'][words[i][1] - 'a'] = 1;
		counter[words[i][0] - 'a'] = 1;
	}

	for(i=0;i<26;i++){
		if(counter[i]){
			int graph_copy[26][26] = {0};
			int trail_count = 0;
			for(j=0;j<26;j++){
				for(k=0;k<26;k++){
					graph_copy[j][k] = graph[j][k];
				}
			}
			euler_trail(i, graph_copy, counter, &trail_count);
			printf("--%d\n", trail_count);
			if(trail_count >= count){
				return 1;
			}
		}
	}

	return 0;
}


int main(int argc, char const *argv[])
{
	char** words = (char**)malloc(sizeof(char*)*4);
	words[0] = "dg";
	words[1] = "gd";
	words[2] = "dn";
	words[3] = "nd";

	printf("%d\n", can_chain(words, 4));

	char** words2 = (char**)malloc(sizeof(char*)*2);
	words2[0] = "ab";
	words2[1] = "cd";
	
	printf("%d\n", can_chain(words2, 2));	

	return 0;
}
