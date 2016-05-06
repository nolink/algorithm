
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substr(char* origin, int from){

	int len = strlen(origin);

	char* result = (char*)malloc(sizeof(char)*(len-from+1));

	strcpy(result, origin+from);

	return result;
}

int match(char* str, char* pattern){

	int idx=0;
	int str_len = strlen(str);
	int pattern_len = strlen(pattern);
	while(idx < str_len && idx  < pattern_len 
		&& (pattern[idx] == '?' || str[idx] == pattern[idx])){
		idx++;
	}

	if(idx == pattern_len){
		return idx == str_len;
	}

	if(pattern[idx] == '*'){

		int skip = 0;
		for(skip=0;skip<=str_len - idx;skip++){
			if(match(substr(str, idx+skip), substr(pattern, idx+1))){
				return 1;
			}
		}

	}

	return 0;

}



int main(int argc, char const *argv[])
{
	printf("%d\n", match("help", "he?p"));
	printf("%d\n", match("heap", "he?p"));
	printf("%d\n", match("helpp", "he?p"));
	printf("%d\n", match("help", "*p*"));
	printf("%d\n", match("papa", "*p*"));
	printf("%d\n", match("hello", "*p*"));
	printf("%d\n", match("babbbc", "*bb*"));
	return 0;
}

