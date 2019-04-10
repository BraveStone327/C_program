#include<stdio.h>

int count = 0;
void hello(){
    if(count == 10) return;
    else{
        printf("Why always, Hello World!!\n");
        count ++;
        hello();
    }
}
void main()
{
    printf("Why always, Hello World!!\n");
    hello();
}
