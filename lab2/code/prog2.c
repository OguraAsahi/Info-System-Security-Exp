#include <stdio.h>

void fmtstr(char* str)
{
    unsigned int *framep;
    unsigned int *ret;
    
    //把ebp寄存器的值放在变量framep中，后面会把该值打印出来，
    //这个变量的目的是找到fmtstr()函数的返回地址存放的位置：ebp+4时返回地址的内存地址，
    //此外，还打印了调用printf()函数前后该返回地址存放的内容，目的是看内容是否发生改变，如果没有说明攻击存在问题。
    asm("movl %%ebp, %0" : "=r" (framep));
    ret = framep + 1;
   
    /* print out information for experiment purpose */
    printf("The address of the input array: 0x%.8x\n", (unsigned)str);
    printf("The value of the frame pointer: 0x%.8x\n", (unsigned)framep);
    printf("The value of the return address(before): 0x%.8x\n", *ret);

    printf(str); 

    printf("\nThe value of the return address(after): 0x%.8x\n", *ret);
}

int main() 
{ 
    FILE *badfile;    
    char str[200];

    badfile = fopen("badfile", "rb");
    fread(str, sizeof(char), 200, badfile);
    fmtstr(str);
    return 1; 
}