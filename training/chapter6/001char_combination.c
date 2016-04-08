
#include <stdio.h>


/* how many combinations can be, the combination length will be step
   example:
      chars: [1,2,3,4]
      len: 4
      step: 2
    print result:
      12,13,14,23,24,34

 */
void print_combination(int* chars, int len, int step){

	

}


int main(int argc, char const *argv[])
{
	
	int chars[4];
	int i = 0;
	for(;i<4;i++){
		chars[i] = i+1;
	}

	print_combination(chars, 4, 2);

	return 0;
}