#include <stdio.h>

void fmtstr(char* str)
{
    unsigned int *framep;
    unsigned int *ret;
    
    //��ebp�Ĵ�����ֵ���ڱ���framep�У������Ѹ�ֵ��ӡ������
    //���������Ŀ�����ҵ�fmtstr()�����ķ��ص�ַ��ŵ�λ�ã�ebp+4ʱ���ص�ַ���ڴ��ַ��
    //���⣬����ӡ�˵���printf()����ǰ��÷��ص�ַ��ŵ����ݣ�Ŀ���ǿ������Ƿ����ı䣬���û��˵�������������⡣
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