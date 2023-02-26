/***************************************
**�ļ�����experiment9 ѧ���ɼ�����ϵͳ5.0
**�����ˣ�
**���ڣ�2020.11.14
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student//����ṹ�塰ѧ����:ѧ�š����������Ƴɼ����ܳɼ�
{
    long num;
    char name[15];
    int score[6];
    int total;
}STU;

void ReadScore(STU *stu,int stunum,int cournum);
void CourseTotalAver(STU *stu,int stunum,int cournum);
void PrintScore(STU *stu,int stunum,int cournum);
void SelectionSort(STU *stu,int stunum,int cournum,int (*compare)(int a,int b));
int Ascending(int a,int b);
int Descending(int a,int b);
void SelectionSortNum(STU *stu,int stunum,int cournum);
void SelectionSortName(STU *stu,int stunum,int cournum);
int LinSearch(STU *stu,long x,int stunum,int cournum);
int LinSearchName(STU *stu,char input[],int stunum,int cournum);
void PrintGrade(STU *stu,int stunum,int cournum);
void WritetoFile(STU *stu,int stunum,int cournum);
void ReadfromFile(STU *stu,int stunum,int cournum);

int main()
{
    printf("Number:\n");
    printf("subject No.8 - program No.1\n\n");

    int choice,flag1=0,flag2=0,flag3=0,i,stunum=0,cournum=0;
    long x;
    char input[15];
    STU stu[30];

    printf("1.Input record\n"
           "2.Calculate total and average score of every course\n"
           "3.Calculate total and average score of every student\n"
           "4.Sort in descending order by total score of every student\n"
           "5.Sort in ascending order by total score of every student\n"
           "6.Sort in ascending order by number\n"
           "7.Sort in dictionary order by name\n"
           "8.Search by number\n"
           "9.Search by name\n"
           "10.Statistic analysis for every course\n"
           "11.List record\n"
           "12.Write to a file\n"
           "13.Read from a file\n"
           "0.Exit\n\n");

    do{
        printf("Please enter your choice:");
        scanf("%d",&choice);

        if(choice==0)
        {
            exit(0);
        }
        else if((choice==1||choice==13)&&flag1==0)
        {
            flag1=1;
        }
        else if(choice!=1&&choice!=13&&choice>0&&choice<=13&&flag1==0)
        {
            printf("Record hasn't been input!\n");
            choice=14;
        }


        switch(choice)
        {
            case 1:
                A:printf("Please input the number of students(1-30):");
                scanf("%d",&stunum);
                if(stunum<=0||stunum>30)
                {
                    printf("Please input right number!\n");
                    fflush(stdin);
                    goto A;
                }
                B:printf("Please input the number of courses(1-6):");
                scanf("%d",&cournum);
                if(cournum<=0||cournum>6)
                {
                    printf("Please input right number!\n");
                    fflush(stdin);
                    goto B;
                }
                ReadScore(stu,stunum,cournum);
                break;

            case 2:
                CourseTotalAver(stu,stunum,cournum);
                break;

            case 3:
                printf("      ID     NAME    TOTAL  AVERAGE\n");//8 1 8 1 8 1 8
                for(i=0;i<stunum;i++)
                {
                    printf("%8ld %8s %8d %8.1f\n",stu[i].num,stu[i].name,stu[i].total,(float)stu[i].total/cournum);
                }
                printf("\n");
                break;

            case 4:
                SelectionSort(stu,stunum,cournum,Descending);
                PrintScore(stu,stunum,cournum);
                break;

            case 5:
                SelectionSort(stu,stunum,cournum,Ascending);
                PrintScore(stu,stunum,cournum);
                break;

            case 6:
                SelectionSortNum(stu,stunum,cournum);
                PrintScore(stu,stunum,cournum);
                break;

            case 7:
                SelectionSortName(stu,stunum,cournum);
                PrintScore(stu,stunum,cournum);
                break;

            case 8:
                SelectionSort(stu,stunum,cournum,Descending);
                printf("Please input student's ID:");
                scanf("%ld",&x);
                flag2=LinSearch(stu,x,stunum,cournum);
                if(flag2==-1)
                {
                    printf("Not found!\n\n");
                }
                break;

            case 9:
                SelectionSort(stu,stunum,cournum,Descending);
                printf("Please input student's name:");
                scanf("%s",input);
                flag3=LinSearchName(stu,input,stunum,cournum);
                if(flag3==-1)
                {
                    printf("Not found!\n\n");
                }
                break;

            case 10:
                PrintGrade(stu,stunum,cournum);
                break;

            case 11:
                PrintScore(stu,stunum,cournum);
                break;

            case 12:
                WritetoFile(stu,stunum,cournum);
                break;

            case 13:
                E:printf("Please input the number of students(1-30):");
                scanf("%d",&stunum);
                if(stunum<=0||stunum>30)
                {
                    printf("Please input right number!\n");
                    fflush(stdin);
                    goto E;
                }
                F:printf("Please input the number of courses(1-6):");
                scanf("%d",&cournum);
                if(cournum<=0||cournum>6)
                {
                    printf("Please input right number!\n");
                    fflush(stdin);
                    goto F;
                }
                ReadfromFile(stu,stunum,cournum);
                PrintScore(stu,stunum,cournum);
                break;

            default:
                printf("Please input right number!\n");
                break;
        }
        system("PAUSE");
    }while(1);

    return 0;
}

/***************************************
**��������ReadScore
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ�����ѧ��������ݣ�������ѧ�š����Ƴɼ������ɸ��Ƴɼ��Ӻ�����ܳɼ�
***************************************/
void ReadScore(STU *stu,int stunum,int cournum)
{
    int i,j;

    for(i=0;i<stunum;i++)
    {
        stu[i].total=0;
        printf("Input student's ID:");
        scanf("%ld",&stu[i].num);
        printf("Input student's name:");
        scanf("%s",stu[i].name);
        for(j=0;j<cournum;j++)
        {
            C:printf("Input student's score of course %d:",j+1);
            scanf("%d",&stu[i].score[j]);
            if(stu[i].score[j]<0||stu[i].score[j]>100)
            {
                printf("Please input right number!\n");
                goto C;
            }
            stu[i].total=stu[i].total+stu[i].score[j];
        }
    }

    printf("\n");

    return;
}

/***************************************
**��������CourseTotalAver
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ����ÿ�ſγ��ܳɼ���ƽ���ɼ�
***************************************/
void CourseTotalAver(STU *stu,int stunum,int cournum)
{
    int i,j,total=0;

    printf("  COURSE    TOTAL  AVERAGE\n");//8 1 8 1 8

    for(j=0;j<cournum;j++)
    {
        for(i=0;i<stunum;i++)
        {
            total=total+stu[i].score[j];
        }
        printf("%8d %8d %8.1f\n",j+1,total,(float)total/stunum);
    }

    printf("\n");

    return;
}

/***************************************
**��������PrintScore
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ����ѧ��ѧ�������͸��Ƴɼ�
***************************************/
void PrintScore(STU *stu,int stunum,int cournum)
{
    int i,j;

    printf("      ID     NAME ");//8 1 8 1
    for(j=0;j<cournum;j++)
    {
        printf("  COURSE%d",j+1);
    }
    printf("    TOTAL  AVERAGE\n");//1 8 1 8

    for(i=0;i<stunum;i++)
    {
        printf("%8ld %-8s",stu[i].num,stu[i].name);
        for(j=0;j<cournum;j++)
        {
            printf(" %8d",stu[i].score[j]);
        }
        printf(" %8d",stu[i].total);
        printf(" %8.1f\n",(float)stu[i].total/cournum);
    }

    printf("\n");

    return;
}

/***************************************
**��������SelectionSort
**���룺*stu,stunum,cournum,(*compare)(int a,int b)
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**(*compare)--���������
**���ܣ�ʵ����������ѡ������
***************************************/
void SelectionSort(STU *stu,int stunum,int cournum,int (*compare)(int a,int b))
{
    int i,j,k;
    STU temp;

    for(i=0;i<stunum-1;i++)
    {
        k=i;
        for(j=i+1;j<stunum;j++)
        {
            if((*compare)(stu[j].total,stu[k].total))
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp=stu[k];
            stu[k]=stu[i];
            stu[i]=temp;
        }
    }

    return;
}

/***************************************
**��������Ascending
**���룺a��b--Ҫ�Ƚϵ���
**�����a>b���0,a<b���1
**���ܣ�ʵ������
***************************************/
int Ascending(int a,int b)
{
    return a<b;
}

/***************************************
**��������Descending
**���룺a��b--Ҫ�Ƚϵ���
**�����a>b���1,a<b���0
**���ܣ�ʵ�ֽ���
***************************************/
int Descending(int a,int b)
{
    return a>b;
}

/***************************************
**��������SelectionSortNum
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ�ʵ����ѧ�ŵ�ѡ������
***************************************/
void SelectionSortNum(STU *stu,int stunum,int cournum)
{
    int i,j,k;
    STU temp;

    for(i=0;i<stunum-1;i++)
    {
        k=i;
        for(j=i+1;j<stunum;j++)
        {
            if(Ascending(stu[j].num,stu[k].num))
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp=stu[k];
            stu[k]=stu[i];
            stu[i]=temp;
        }
    }

    return;
}

/***************************************
**��������SelectionSortName
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ�ʵ����������ѡ������
***************************************/
void SelectionSortName(STU *stu,int stunum,int cournum)
{
    int i,j,k;
    STU temp;

    for(i=0;i<stunum-1;i++)
    {
        k=i;
        for(j=i+1;j<stunum;j++)
        {
            if(strcmp(stu[j].name,stu[k].name)<0)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp=stu[k];
            stu[k]=stu[i];
            stu[i]=temp;
        }
    }

    return;
}

/***************************************
**��������LinSearch
**���룺*stu,x,stunum,cournum
***stu--ѧ���������
**x--Ҫ���ҵ�ѧ��
**stunum--ѧ����
**cournum--�γ���
**�����ѧ�Ŵ��ڷ���0��ѧ�Ų��������䷵��-1
**���ܣ�����ѧ�Ų��ҳɼ�������
***************************************/
int LinSearch(STU *stu,long x,int stunum,int cournum)
{
    int i,j;

    for(i=0;i<stunum;i++)
    {
        if(stu[i].num==x)
        {
            printf("rank %d",i+1);
            for(j=0;j<cournum;j++)
            {
                printf(" %d",stu[i].score[j]);
            }
            printf(" %d\n\n",stu[i].total);
            return 0;
        }
    }
    return -1;
}

/***************************************
**��������LinSearchName
**���룺*stu,input[],stunum,cournum
***stu--ѧ���������
**input[]--Ҫ���ҵ�����
**stunum--ѧ����
**cournum--�γ���
**�����ѧ�Ŵ��ڷ���0��ѧ�Ų��������䷵��-1
**���ܣ������������ҳɼ�������
***************************************/
int LinSearchName(STU *stu,char input[],int stunum,int cournum)
{
    int i,j;

    for(i=0;i<stunum;i++)
    {
        if(strcmp(stu[i].name,input)==0)
        {
            printf("rank %d",i+1);
            for(j=0;j<cournum;j++)
            {
                printf(" %d",stu[i].score[j]);
            }
            printf(" %d\n\n",stu[i].total);
            return 0;
        }
    }
    return -1;
}

/***************************************
**��������PrintGrade
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ�ʵ�ַ����ͳ��
***************************************/
void PrintGrade(STU *stu,int stunum,int cournum)
{
    int i,j,excellent=0,good=0,average=0,passing=0,failed=0;

    for(j=0;j<cournum;j++)
    {
        for(i=0;i<stunum;i++)
        {
            if(stu[i].score[j]<=100&&stu[i].score[j]>=90)
            {
                excellent++;
            }
            else if(stu[i].score[j]<90&&stu[i].score[j]>=80)
            {
                good++;
            }
            else if(stu[i].score[j]<80&&stu[i].score[j]>=70)
            {
                average++;
            }
            else if(stu[i].score[j]<70&&stu[i].score[j]>=60)
            {
                passing++;
            }
            else
            {
                failed++;
            }
        }

        printf("Course %d\n",j+1);
        printf("Excellent(90-100) %d %d%%\n",excellent,(100*excellent)/stunum);
        printf("Good(80-89)       %d %d%%\n",good,(100*good)/stunum);
        printf("Average(70-79)    %d %d%%\n",average,(100*average)/stunum);
        printf("Passing(60-69)    %d %d%%\n",passing,(100*passing)/stunum);
        printf("Failed(0-59)      %d %d%%\n",failed,(100*failed)/stunum);

        excellent=0;
        good=0;
        average=0;
        passing=0;
        failed=0;
    }

    return;
}

/***************************************
**��������WritetoFile
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ���ѧ����Ϣд���ļ�
***************************************/
void WritetoFile(STU *stu,int stunum,int cournum)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("Failure to open student.txt!\n");
        exit(0);
    }
    for(i=0;i<stunum;i++)
    {
        fprintf(fp,"%8ld %-8s",stu[i].num,stu[i].name);
        for(j=0;j<cournum;j++)
        {
            fprintf(fp," %8d",stu[i].score[j]);
        }
        fprintf(fp," %8d\n",stu[i].total);
    }
    fclose(fp);
}

/***************************************
**��������ReadfromFile
**���룺*stu,stunum,cournum
***stu--ѧ���������
**stunum--ѧ����
**cournum--�γ���
**���ܣ���ѧ����Ϣ�����ļ�
***************************************/
void ReadfromFile(STU *stu,int stunum,int cournum)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("Failure to open student.txt!\n");
        exit(0);
    }
    for(i=0;i<stunum;i++)
    {
        fscanf(fp,"%8ld",&stu[i].num);
        fscanf(fp," %8s",stu[i].name);
        for(j=0;j<cournum;j++)
        {
            fscanf(fp," %8d",&stu[i].score[j]);
            if(stu[i].score[j]<0||stu[i].score[j]>100)
            {
                printf("There are wrong numbers!\n");
            }
        }
        fscanf(fp," %8d",&stu[i].total);
    }
    fclose(fp);
}
