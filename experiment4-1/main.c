#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int AnswerCheck(int x,int y);//函数功能：实现将生成数据进行乘法提问并检验输入是否正确，正确返回1，错误返回0

int main()
{
    printf("Number:\n");
    printf("subject No.4 - program No.1\n\n");

    printf("CAI-V1.0\n\n");

    int i,mag1,mag2,flag=0,count=0;

    srand(time(NULL));

    for(i=0;i<10;i++)
    {
        mag1=rand()%10+1;
        mag2=rand()%10+1;
        flag=AnswerCheck(mag1,mag2);
        count=count+flag;
    }

    printf("Total score is %d\n",count*10);
    printf("Accuracy is %d%%",count*10);

    return 0;
}

int AnswerCheck(int x,int y)
{
    int truth,answer,j=0;
    truth=x*y;
    do{
        printf("%d * %d = ",x,y);
        scanf("%d",&answer);
        j++;
        if(answer==truth)
        {
            printf("Right!\n");
            return 1;//正确则跳出函数返回1
        }
        else
        {
            if(j!=3)
            {
                printf("Wrong!Please try again.\n");
            }
            else
            {
                printf("Wrong!Test next subject!\n");
            }
        }
    }while(j<3);
    return 0;//错误则返回0
}
