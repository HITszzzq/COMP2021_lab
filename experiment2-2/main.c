#include <stdio.h>
#include <math.h>

int main()
{
    printf("Number:\n");
    printf("subject No.2 - program No.2\n\n");

    double a,b,c;
    double p,s;

    printf("����������������a,b,c:");
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
                    printf("�ȱ�");
                }
                else
                {
                    printf("����");
                }
            }
            if(fabs(a*a+b*b-c*c)<=0.1||fabs(a*a+c*c-b*b)<=0.1||fabs(b*b+c*c-a*a)<=0.1)
            {
                printf("ֱ��");
            }
            printf("������\n");
            printf("���������S=%f\n",s);
        }
        else
        {
            printf("����������\n");
        }
    }
    else
    {
        printf("������������Ϊ�����α߳�\n");
    }



    return 0;
}
