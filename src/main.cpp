#include<mbed.h>

asm(".global _printf_float");
using ThisThread::sleep_for;


InterruptIn sw(D6);
DigitalOut led(D10);

int swstatus = 0;
int flag = 0;

unsigned int checker = 0;
unsigned int unsintmax = ~0;

void fallfunc(){//fall
    if(swstatus){
        swstatus = 0;
    }
}
void risefunc(){//rise
    if(swstatus == 0){
        swstatus = 1;
    }
}

int main(){
    sw.rise(risefunc);
    sw.fall(fallfunc);
    while(1){
        checker = (checker << 1) + swstatus;
        flag = (checker == unsintmax);
        led = flag;
        printf("sw:%d flag:%d\n",swstatus,flag);
    }
}



