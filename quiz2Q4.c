#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
const uint32_t D = 3;
#define M ((uint64_t)(UINT64_C(0xFFFFFFFFFFFFFFFF) / (D) + 1))

/* compute (n mod d) given precomputed M */
uint32_t quickmod(uint32_t n)
{   uint64_t quotient = ((__uint128_t) M * n) >> 64;
    return n - quotient * D;
}

bool divisible(uint32_t n)
{
    return n * M <= (M -1);
}

int main(){
    uint32_t x = 0x98;
    printf("x=%x \t ans = %d\n",x,quickmod(x));
    if(divisible(x))
        printf("True\n");
}
