#include <stdio.h>

#define SIZE 81

void mengerSponge(int i, int j, int size);

void main(){
	
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++)
			mengerSponge(i, j, SIZE);
		putchar('\n');
	}
	
}

void mengerSponge(int i, int j, int size){
	
	if((i / size) % 3 == 1 && (j / size) % 3 == 1)
		putchar(' ');
	
	else if(size == 1)
		putchar('*');
	
	else 
		mengerSponge(i, j, size / 3);
	
	
}