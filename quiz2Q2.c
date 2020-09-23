/*
This is for hexchar2val
*/
#include <stdio.h>
#include<stdint.h>
uint8_t hexchar2val(uint8_t in)
{
    const uint8_t letter = in & 0x40;
    const uint8_t shift = (letter >> 3) | (letter >> 6);
    return (in + shift) & 0xf;
}

int main(){
	printf("This is for linux 2020 Quiz 2 Question 2 \n");
	
	char a = 'f';
	printf("%c 's return : %d \n",a,hexchar2val(a));
	return 0;
} 
