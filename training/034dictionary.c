

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b){
	return a < b ? a : b;
}

void dfs(int graph[26][26], int visited[26], int result[26], int counter[26], int idx, int* result_idx){
	visited[idx] = 1;
	for(int j=0;j<26;j++){
		if(counter[j] && graph[idx][j] && !visited[j]){
			dfs(graph, visited, result, counter, j, result_idx);
		}
	}
	result[*result_idx] = idx;
	(*result_idx)++;
}

void dictionary(char** words, int count){
	int i=0,j=0;
	//build graph
	int graph[26][26];
	int counter[26];
	int visited[26];
	int result[26];
	int reverse_result[26];

	for(i=0;i<26;i++){
		counter[i] = 0;
		visited[i] = 0;
		result[i] = 0;
		reverse_result[i] = 0;
		for(j=0;j<26;j++){
			graph[i][j] = 0;
		}
	}

	for(i=0;i<count - 1;i++){
		char* w1 = words[i];
		char* w2 = words[i+1];
		int len = min(strlen(w1), strlen(w2));
		for(j=0;j<len;j++){
			if(w1[j] != w2[j]){
				graph[w1[j] - 'a'][w2[j] - 'a'] = 1;
				counter[w1[j] - 'a'] = 1;
				break;
			}
		}
	}

	//build the order
	int result_idx = 0;
	for(i=0;i<26;i++){
		if(counter[i] &&!visited[i]){
			dfs(graph, visited, result,counter, i, &result_idx);
		}
	}

	for(i=0;i<26;i++){
		reverse_result[i] = result[25-i];
	}

	//check the cycle
	for(i=0;i<26;i++){
		for(j=i+1;j<26;j++){
			if(counter[j] && graph[reverse_result[j]][reverse_result[i]] == 1){
				printf("invalid"); 
				return;
			}
		}
	}

	
}


int main(int argc, char const *argv[])
{
	char** words = (char**)malloc(sizeof(char*)*5);
	words[0] = "gg";
	words[1] = "kia";
	words[2] = "lotte";
	words[3] = "lg";
	words[4] = "hanwha";

	dictionary(words,5);
	return 0;
}