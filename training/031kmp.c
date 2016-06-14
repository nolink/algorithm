

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
	return a > b ? a : b;
}

int* partial(char* needle, int n_len){

	int* pi = (int*)malloc(sizeof(int)*n_len);

	int i=0, j=0, k=0;

	for(i=0;i<n_len;i++){
		pi[i] = 0;
	}

	// for(i=2;i<=n_len;i++){
	// 	for(j=i-1;j>0;j--){
	// 		int match = 1;
	// 		for(k=i-j;k<i;k++){
	// 			if(needle[k-(i-j)] != needle[k]){
	// 				match = 0;
	// 				break;
	// 			}
	// 		}
	// 		if(match){
	// 			pi[i-1] = j;
	// 			break;
	// 		}
	// 	}
	// }

	// for(i=1;i<n_len;i++){                    //后缀的长度，i=1, 后缀的长度为 n_len - 1, 依次类推，n_len -2 , ...，下标从1开始
	// 	for(j=0;j<n_len-i;j++){                 //前缀的长度，与后缀长度一致，下标从0开始，
	// 		if(needle[i+j] != needle[j]){
	// 			break;
	// 		}
	// 		pi[i+j] = max(pi[i+j], j+1);
	// 	}
	// }

	//在自己(后缀，母串)里面找自己（前缀，子串），母串从1开始，子串从0开始
	i=1;
	while(i+j < n_len){

		if(j < n_len && needle[i+j] == needle[j]){
			j++;
			pi[i+j-1] = j;
		}else{
			if(j == 0){
				i++;
			}else{
				i += j - pi[j-1];
				j = pi[j-1];
			}
		}

	}

	return pi;

}

void kmp(char* haystack, int h_len, char* needle, int n_len){

	int* pi = partial(needle, n_len);

	int begin=0, matched=0;

	while(begin <= n_len-matched){

		if(matched < n_len && haystack[begin+matched] == needle[matched]){
			matched++;
			if(matched == n_len){
				printf("%d\n", begin);
			}
		}else{
			if(matched == 0){
				begin++;
			}else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}

	}
	
}



int main(int argc, char const *argv[])
{
	int i=0;

	int* pi = partial("aabaabac", 8);
	for(i=0;i<8;i++){
		printf("%d\n", pi[i]);
	}

	return 0;
}
