#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int AnswerCheck(int x,int y,char z);//������������Ž��������������ʲ����������Ƿ���ȷ����ȷ����1�����󷵻�0

int main()
{
    printf("Number:\n");
    printf("subject No.4 - program No.2\n\n");

    printf("CAI-V2.0\n\n");

    int i,mag1,mag2,flag,count,mag;
    char cal;

    srand(time(NULL));

    do{
        count=0;
        for(i=0;i<10;i++)
        {
            mag1=rand()%10+1;
            mag2=rand()%10+1;
            mag=rand()%4;

            switch(mag)
            {
                case 0:cal='+';
                        break;
                case 1:cal='-';
                        break;
                case 2:cal='*';
                        break;
                case 3:cal='/';
                        break;
            }

            flag=AnswerCheck(mag1,mag2,cal);
            count=count+flag;
        }
        printf("Total score is %d\n",count*10);
        printf("Accuracy is %d%%\n",count*10);
    }while(count<7.5);

    return 0;
}

int AnswerCheck(int x,int y,char z)
{
    int truth,answer,tip;
    printf("%d %c %d = ",x,z,y);
    scanf("%d",&answer);
    switch(z)//�жϷ��Ų���������
    {
        case '+':truth=x+y;
                break;
        case '-':truth=x-y;
                break;
        case '*':truth=x*y;
                break;
        case '/':truth=x/y;
                break;
    }
    if(answer==truth)//��ȷ���������䲢����1
    {
        tip=rand()%4;
        switch(tip)
        {
            case 0:printf("Very good!\n");
                    break;
            case 1:printf("Excellent!\n");
                    break;
            case 2:printf("Nice work!\n");
                    break;
            case 3:printf("Keep up the good work!\n");
                    break;
        }
        return 1;
    }
    else//������������䲢����0
    {
        tip=rand()%4;
        switch(tip)
        {
            case 0:printf("No.Please try next subject.\n");
                    break;
            case 1:printf("Wrong.Be careful.\n");
                    break;
            case 2:printf("Don't give up!\n");
                    break;
            case 3:printf("Not correct.Keep trying.\n");
                    break;
        }
        return 0;
    }
}
