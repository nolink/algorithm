

#include <stdio.h>


int cache[100][100] = {0};
int mod = 10*1000*1000;

int poly_inner(int n, int first){

	if(n <= 1 || n <= first){
		return 1;
	}

	int* result = &cache[n][first];

	if(0 != *result){
		return *result;
	}

	int second = 1;

	for(;second<=n-first;second++){
		int join = first + second - 1;
		*result += (join * poly_inner(n - first, second)) % mod;
		*result %= mod;
	}

	return *result;

}


int poly(int n){

	int i=1;
	int result = 0;
	for(;i<=n;i++){
		result += poly_inner(n, i);
	}
	return result;
}


int main(int argc, char const *argv[])
{
	printf("%d\n", poly(92));
	return 0;
}
