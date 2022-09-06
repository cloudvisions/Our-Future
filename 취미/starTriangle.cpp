#include <stdio.h>

#define SIZE 10


void main(){
	
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j <= i; j++)
			putchar('*');
		putchar('\n');
		
	}
}