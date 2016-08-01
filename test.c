

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

int nthUglyNumber(int n) {
        if(n <= 1) return n;
        int two = 1, three = 1, five = 1, nth = 1;
        for(int i=2;i<=n;i++){
            int two_next = two*2;
            int three_next = three*3;
            int five_next = five*5;
            if(two_next < three_next && two_next < five_next){
                nth = two = two_next;
            }else if(three_next < five_next && three_next < two_next){
                nth = three = three_next;
            }else if(five_next < two_next && five_next < three_next){
                nth = five = five_next;
            }
        }
        return nth;
    }

int main(int argc, char const *argv[])
{
	
	printf("%d\n", nthUglyNumber(6));

	return 0;
}