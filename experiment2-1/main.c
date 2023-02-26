#include <stdio.h>
#include<stdlib.h>
#define PI 3.14159

int main()
{
    printf("Number:\n");
    printf("subject No.2 - program No.1\n\n");

    const float pi=3.14159;
    float r,s1,v1,s2,v2;

    printf("Please input R:");
    scanf("%f",&r);

    if(r<=0)
    {
        printf("Error!\n");
        exit(0);
    }

    s1=4*pi*r*r;
    v1=((float)4/3)*pi*r*r*r;
    s2=4*PI*r*r;
    v2=((float)4/3)*PI*r*r*r;

    printf("S=%f,V=%f\n",s1,v1);
    printf("S=%f,V=%f\n",s2,v2);

    return 0;
}
