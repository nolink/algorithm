

#include <stdio.h>
#include <stdlib.h>


int take_friend(int* taken, int student_count, int** grouped_friendships){

	int i=0;
	int firstFree = -1;

	for(i=0;i<student_count;i++){
		if(!taken[i]){
			firstFree=i;
			break;
		}
	}

	if(firstFree == -1){
		return 1;
	}

	int result = 0;
	for(i=firstFree+1;i<student_count;i++){

		if(!taken[i] && grouped_friendships[firstFree][i]){
			taken[firstFree] = taken[i] = 1;
			result += take_friend(taken, student_count, grouped_friendships);
			taken[firstFree] = taken[i] = 0;
		}

	}

	return result;
}

int picnic(int student_count, int friendship_count, int* friendships){

	if(friendship_count == 0){
		return 0;
	}

	int** grouped_friendships = (int**)malloc(sizeof(int*)*student_count);

	int i=0;
	int j=0;
	for(i=0;i<student_count;i++){
		grouped_friendships[i] = (int*)malloc(sizeof(int)*(student_count));
		for(j=0;j<student_count;j++){
			grouped_friendships[i][j]=0;
		}
	}

	for(i=0;i<2*friendship_count;i+=2){
		grouped_friendships[friendships[i]][friendships[i+1]] = 1;
		grouped_friendships[friendships[i+1]][friendships[i]] = 1;
	}

	int* taken = (int*)malloc(sizeof(int)*student_count);

	for(i=0;i<student_count;i++){
		taken[i] = 0;
	}

	int result = take_friend(taken, student_count, grouped_friendships);

	for(i=0;i<student_count;i++){
		free(grouped_friendships[i]);
	}

	free(grouped_friendships);

	return result;
}

int main(int argc, char const *argv[])
{
	
	printf("type the case count: ");

	int case_count;
	scanf("%d", &case_count);

	int i=0, j=0;
	int student_count;
	int friendship_count;
	int* friendships;
	for(i=0;i<case_count;i++){
		printf("type student count and friendship count for case %d: ", i);

        scanf("%d", &student_count);
        getchar();
        scanf("%d", &friendship_count);

        friendships = (int*)malloc(sizeof(int)*2*friendship_count);

        printf("please input the friendships: ");
        for(j=0;j<2*friendship_count;){
        	scanf("%d", &friendships[j++]);
        	getchar();
        	scanf("%d", &friendships[j++]);
        }

        // printf("\nstudent_count: %d, friendship_count: %d\n", student_count, friendship_count);
        // for(j=0;j<2*friendship_count;j++){
        // 	printf("%d ", friendships[j]);
        // }
        // printf("\n");
        //3
        //2 1
        //0 1
        //4 6
        //0 1 1 2 2 3 3 0 0 2 1 3
        //6 10
        //0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5

        printf("%d\n", picnic(student_count, friendship_count, friendships));

        free(friendships);
	}

	return 0;
}
