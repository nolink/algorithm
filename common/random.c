

#include "random.h"
#include "time.h"

int rand(int max){
	static unsigned seed=0;

	if(seed == 0){
		time_t raw_time;
    	time(&raw_time);
    	seed = (unsigned)raw_time;
	}
    
    unsigned ret = seed;
    seed =  ((seed * 214013u) + 2531011u);

    return ret % max + 1;

}
