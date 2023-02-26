#include <stdio.h>
#include <math.h>

int main()
{
    printf("Number:\n");
    printf("subject No.2 - program No.2\n\n");

    double a,b,c;
    double p,s;

    printf("请输入三角形三边a,b,c:");
    scanf("%lf%*c%lf%*c%lf",&a,&b,&c);

    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));

    if(a>=0&&b>=0&&c>=0)
    {
        if(a+b>c&&b+c>a&&a+c>b)
        {
            if(fabs(a-b)<=0.1||fabs(b-c)<=0.1||fabs(c-a)<=0.1)
            {
                if(fabs(a-b)<=0.1&&fabs(b-c)<=0.1&&fabs(c-a)<=0.1)
                {
                    printf("等边");
                }
                else
                {
                    printf("等腰");
                }
            }
            if(fabs(a*a+b*b-c*c)<=0.1||fabs(a*a+c*c-b*b)<=0.1||fabs(b*b+c*c-a*a)<=0.1)
            {
                printf("直角");
            }
            printf("三角形\n");
            printf("三角形面积S=%f\n",s);
        }
        else
        {
            printf("不是三角形\n");
        }
    }
    else
    {
        printf("请输入正数作为三角形边长\n");
    }



    return 0;
}
