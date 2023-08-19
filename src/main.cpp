#include<mbed.h>

asm(".global _printf_float");
using ThisThread::sleep_for;


InterruptIn sw(D6);

int status = 0;
int status2 = 0;
unsigned int checker = 0;
unsigned int unsintmax = ~0;

void test2(){//fall
    if(status2){
        le2 = 0;
        status2 = 0;
    }
}
void test(){//rise
    if(status2 == 0){
        le2 = 1;
        status2 = 1;
    }
}

int main(){
    sw.rise(test);
    sw.fall(test2);
    while(1){
        checker = checker << 1;
        checker += (status2 == 1)?1:0;
        if(checker == unsintmax){
            status = 1;
        }
        else{
            status = 0;
        }
        printf("S2:%d S:%d\n",status2,status);
    }
}


