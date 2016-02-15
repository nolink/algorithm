int getRep(char c){
	switch(c){
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
}

int validPrefix(char c, char prev){
	switch(c){
	case 'I':
		return prev == 'V';
	case 'V':
		return prev == 'I';
	case 'X':
		return prev == 'I' || prev == 'L';
	case 'L':
		return prev == 'X';
	case 'C':
		return prev == 'D' || prev == 'X';
	case 'D':
		return prev == 'C';
	case 'M':
		return prev == 'C';
	}
}

int romanToInt(char* s) {
 	int len = strlen(s);

 	int current = 0;
 	while(len > 0){
 		char c = s[len - 1];
 		len--;

 		int value = getRep(c);
 		int repeat = 1;
 		char temp = 'N';
 		while(len > 0){
	 		temp = s[len - 1];
	 		len--;
	 		if(temp != c){
	 			break;
	 		}
	 		repeat++;
 		}

 		if(temp != 'N'){
 			if(temp == c){
 				current += value * repeat;
 			}else{
 				int tempV = getRep(temp);
 				if(validPrefix(c, temp) && tempV > value){
 					current += tempV + value * repeat;
 				}else if(validPrefix(c, temp) && tempV <= value){
 					current += value * repeat - tempV;
 				}else{
 					current += value * repeat;
 					len++;
 				}
 			}
 		}
 		else{
 			current += value;
 		}
 		
 	}
 	return current;
}