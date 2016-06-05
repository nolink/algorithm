
#include <stdio.h>


int v1(int n){
	if(n == 1) return 1;
	return n + v1(n-1);
}

int v2(int n){
	return n*(n+1)/2;
}

int v3(int n){
	if(n == 1) return 1;
	if(n % 2 == 1) return v3(n-1)+n;
	return 2*v3(n/2)+(n/2)*(n/2);
}


int main(int argc, char const *argv[])
{
	printf("v1: %d, v2: %d, v3: %d\n", v1(10), v2(10), v3(10));
	return 0;
}
