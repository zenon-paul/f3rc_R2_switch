#include<mbed.h>

asm(".global _printf_float");
using ThisThread::sleep_for;


InterruptIn sw(D6);

int swstats = 0;
int flag = 0;
unsigned int checker = 0;
unsigned int unsintmax = ~0;

void fallfunc(){//fall
    if(swstats){
        swstats = 0;
    }
}
void risefunc(){//rise
    if(swstats == 0){
        swstats = 1;
    }
}

int main(){
    sw.rise(risefunc);
    sw.fall(fallfunc);
    while(1){
        checker = checker << 1;
        checker += (swstats == 1)?1:0;
        if(checker == unsintmax){
            flag = 1;
        }
        else{
            flag = 0;
        }
        printf("swstatus:%d flag:%d\n",swstats,flag);
    }
}


