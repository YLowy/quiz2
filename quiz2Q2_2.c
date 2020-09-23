/*
This is for hexchar2val and allow "0XFF" "0xCAFEBABE" "0x8BADF00D"
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
uint8_t hexchar2val(uint8_t in)
{
    const uint8_t letter = in & 0x40;
    const uint8_t shift = (letter >> 3) | (letter >> 6);
    return (in + shift) & 0xf;
}
int Hexspeak(char input[]){
	size_t len = strlen(input); 
	assert(len <= 18);
	//printf("len : %d \n",len);
	assert(input[0]=='0' && (input[1]=='x'||input[1]=='X'));
	// make sure 0x ________
	
	unsigned int answer = 0;
	for(int i=2;i<=len-1;i++){
		answer <<= 4;
		answer |= hexchar2val(input[i]);
		//printf("i: %d : %d\n",i,answer);
	}
	
	return answer;
}
int main(){
	char input[] = "0xF";
	printf("Input :%s \t Output :%d  \n",input, Hexspeak(input));
	
	
	
	return 0;
} 
