#include <stdio.h>

int main()
{
    char a;
    int b;
    short int c;
    float d;
    double e;

    printf("Number:\n");
    printf("subject No.1 - program No.1\n\n");

    printf("Please input char a:");
    scanf("%c",&a);
    printf("char a = %c, size of char is %d\n",a,sizeof(char));

    printf("Please input int b:");
    scanf("%d",&b);
    printf("int b = %d, size of int is %d\n",b,sizeof(int));

    printf("Please input short c:");
    scanf("%d",&c);
    printf("short c = %d, size of short is %d\n",c,sizeof(short));

    printf("Please input float d:");
    scanf("%f",&d);
    printf("float d = %f, size of float is %d\n",d,sizeof(float));

    printf("Please input double e:");
    scanf("%lf",&e);
    printf("double e = %f, size of double is %d\n",e,sizeof(double));

    return 0;
}
