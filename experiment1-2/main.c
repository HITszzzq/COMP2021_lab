#include <stdio.h>

int main()
{
    char a;
    int i,j;

    printf("Number:\n");
    printf("subject No.1 - program No.2\n\n");

    printf("Please input a lower case:");
    scanf("%c",&a);

    a=a-32;

/*��ѭ����䣬ʹ��3��*/
    for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
        {
            if(i%2!=0)
            {
                printf("%c ",a);
            }
            else
            {
                printf(" %c",a);
            }
        }
        printf("\n");
    }
/*1��
    printf("%c %c %c %c %c %c %c %c\n"
" %c %c %c %c %c %c %c %c\n"
"%c %c %c %c %c %c %c %c\n"
" %c %c %c %c %c %c %c %c\n"
"%c %c %c %c %c %c %c %c\n"
" %c %c %c %c %c %c %c %c\n"
"%c %c %c %c %c %c %c %c\n"
" %c %c %c %c %c %c %c %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);*/
    return 0;
}
