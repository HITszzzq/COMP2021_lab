#include <stdio.h>

int main()
{
    printf("Number:\n");
    printf("subject No.3 - program No.1\n\n");

    int a,b;
    int c[200]={0};
    int d,e,f,g;
    int count=0;
    int flag=0;

    for(a=100;a<=200;a++)       //打印素数
    {
        for(b=2;b<a;b++)
        {
            if(a%b==0)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("%d ",a);
            count++;
            c[a]=1;
        }
        if(count==10)
        {
            printf("\n");
            count=0;
        }
        flag=0;
    }

    printf("\n");
    count=0;

    for(a=100;a<=200;a++)       //打印反转数
    {
        if(c[a]==1)
        {
            f=a%10;
            e=(a%100)/10;
            d=a/100;
            g=100*f+10*e+d;
            printf("%d ",g);
            count++;
        }
        if(count==10)
        {
            printf("\n");
            count=0;
        }
    }

    return 0;
}
