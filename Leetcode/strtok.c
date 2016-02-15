
#include <stdio.h>  
#include <string.h>  
#include <conio.h>  

char* my_strtok2(char* s, const char* delim){
	static char* _s = NULL;
	char* tok;

	if(s == NULL && (s = _s) == NULL){
		return NULL;
	}

	//首先将s定位到第一个非delim字符
	while((*s != '\0') && (NULL != strchr(delim, *s))){
		s++;
	}

	if(*s == '\0'){
		_s = NULL;
		return NULL;
	}

	//tok为返回结果，将tok指向第一个非delim字符
	tok = s;

	char* idx;
	while((*s) != '\0' && (idx = strchr(delim, *s)) == NULL){
		s++;
	}

	if(*s == '\0'){
		_s = NULL;
	}

	if(idx != NULL){
		_s = s + 1;
		*s = '\0';
	}

	return tok;
}

char* my_strtok(char* s, const char* delim){
	
	static char* _s = NULL;
	
	if(NULL == _s){
		_s = s;
	}
	
	if(NULL == _s){
		return NULL;
	}

	if(*_s == '\0'){
		return NULL;
	}
	
	char* p = _s;
	char* idx = NULL;
	while((*_s) != '\0' && NULL == (idx = strchr(delim, *_s))){
		_s++;
	}
	
	if(NULL != idx){
		char* t = _s;
		_s++;
		*t = '\0';
		while((*_s) != '\0' && NULL != (idx = strchr(delim, *_s))){
			_s++;
		}
	}

	return p;
	
}

 
char string[] = "A string\tof ,,tokens\nand some  more tokens";  
char seps[]   = " ,\t\n";  
char *token;  
int main(void)  
{  
    printf( "Tokens:\n" );  
    token = my_strtok2( string, seps );   
    while(token !=NULL)  
    {  
         printf("%s\n",token);  
         token=my_strtok2(NULL,seps);  
    }  
    getch();  
    return 0;  
}  

