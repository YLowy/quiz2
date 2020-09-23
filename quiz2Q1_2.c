/*
This is for testing whether the mask 0808080808080808 is correct or not
*/
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while ((i + 8) <= size) {
    	
        uint64_t payload;
        memcpy(&payload, str + i, 8);
       
		
        if (payload & 0x8080808080808080)
            return false;
        i += 8;
    }
    while (i < size) {
        if (str[i] & 0x80)
            return false;
        i++;
    }
    return true;
}

int main(){
	printf("This is for linux 2020 Quiz 2 Question 1 \n");
	
	char a = 'a';
	unsigned char b = 0x68;
	unsigned char nonASCII = 0x88;
	unsigned int intASCII = 0x62626262;
	unsigned int nonintASCII = 0x62626288;
	printf("%x 's return : %d \n",a,is_ascii(&a,sizeof(char)));
	printf("%x 's return : %d \n",b,is_ascii(&b,sizeof(char)));
	printf("%x 's return : %d \n",nonASCII,is_ascii(&nonASCII,sizeof(char)));
	printf("%x 's return : %d \n",intASCII,is_ascii((char*)&intASCII,sizeof(intASCII)));
	printf("%x 's return : %d \n",nonintASCII,is_ascii((char*)&nonintASCII,sizeof(intASCII)));
	return 0;
} 
