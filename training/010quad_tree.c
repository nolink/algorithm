                                                                                                                                                                                                                                                                                                               

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char x[2] = {'x', '\0'};

char* reverse(char* compressed, int size, int* idx){

	char* result = NULL;

	char current = compressed[(*idx)];

	(*idx)++;

	if(current == 'b' || current == 'w'){
		result = (char*)malloc(sizeof(char)*2);
		result[0] = current;
		result[1] = '\0'; 
		return result;
	}
	char* upperLeft = reverse(compressed, size, idx);
	char* upperRight = reverse(compressed, size, idx);
	char* downLeft = reverse(compressed, size, idx);
	char* downRight = reverse(compressed, size, idx);

	result = (char*)malloc(sizeof(char)*(strlen(upperLeft)+strlen(upperRight)+strlen(downLeft)+strlen(downRight)+2));

	strcpy(result, x);
	strcat(result, downLeft);
	strcat(result, downRight);
	strcat(result, upperLeft);
	strcat(result, upperRight);

	return result;

}

int main(int argc, char const *argv[])
{
	int idx = 0;
	printf("%s\n", reverse("w", 1, &idx));
	idx = 0;
	printf("%s\n", reverse("xbwwb", 5, &idx));
	idx = 0;
	printf("%s\n", reverse("xbwxwbbwb", 9, &idx));
	idx = 0;
	printf("%s\n", reverse("xxwwwbxwxwbbbwwxxxwwbbbwwwwbb", 29, &idx));
	return 0;
}
