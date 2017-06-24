

int _start(){
    volatile int a = 2;
    volatile int b = 5;
    volatile int c = a + b;
    volatile int d = a * c;
    volatile int e = d / 4;
    return d;
}
