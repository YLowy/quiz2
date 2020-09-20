#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    for (int i = 0; i < size; i++)
        if (str[i] & 0x80) /* i.e. (unsigned) str[i] >= 128 */
            return false;
    return true;
}

int main(){
	printf("This is for linux 2020 Quiz 2 Question 1 \n");
	
	char a = 'a';
	unsigned char b = 0x88;
	unsigned char nonASCII = 0x88;
	printf("%x 's return : %d \n",a,is_ascii(&a,sizeof(char)));
	printf("%x 's return : %d \n",b,is_ascii(&b,sizeof(char)));
	printf("%x 's return : %d \n",nonASCII,is_ascii(&nonASCII,sizeof(char)));
	return 0;
} 
