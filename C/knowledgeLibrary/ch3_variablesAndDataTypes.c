#include<stdio.h>


/*
    Note:
        -   fracA vs fracB
        -   printf(1/3) vs printf((float)1/3)
*/
int main(){
    int integer = 177;
    int octal = 0177;   // 0 in front makes it base 8
    int hex = 0xFFEF0D;
    float fl = 0.00225;
    float fracA = 1 / 3;
    float fracB = 1.0f / 3.0f;
    char c = 'A';


    printf("integer: %i\t\toctal: %o\tleading 0: %#o\n\n", octal, octal, octal);
    printf("integer: %i\thex: %x\tleading 0: %#X\n\n", hex, hex, hex);
    printf("integer: %i\t\tchar: %c\t\n\n", c, c);
    printf("float: %f\t\tscientific notation: %e\tpleasing: %g\n\n", fl, fl, fl);
    printf("floatA: %f\t\tfloatB: %f\t\t1/3: %f\t\t(float)1/3: %f\n\n", fracA, fracB, 1/3, (float)1/3);

    return 0;
}