#include <stdio.h>
#include <math.h>
#define N 1.42e8

int main()
{
    printf("Number:\n");
    printf("subject No.3 - program No.2\n\n");

/*利用前项计算后项*/
    double i;
    double a=1;
    double sum1=1;
    double v1;

    for(i=2;i<=64;i++)
    {
        a=a*2;
        sum1=sum1+a;
    }

    printf("sum1=%e\n",sum1);

    v1=sum1/N;
    printf("v1=%e\n",v1);
/*直接计算累加的通项*/
    double j,b;
    double sum2=0;
    double v2;

    for(j=1;j<=64;j++)
    {
        b=pow(2,j-1);
        sum2=sum2+b;
    }

    printf("sum2=%e\n",sum2);

    v2=sum2/N;
    printf("v2=%e\n",v2);

    return 0;
}
