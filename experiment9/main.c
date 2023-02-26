/***************************************
**文件名：experiment9 学生成绩管理系统5.0
**创建人：
**日期：2020.11.14
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student//定义结构体“学生”:学号、姓名、各科成绩、总成绩
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
**函数名：ReadScore
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：读入学生相关数据（姓名、学号、各科成绩），由各科成绩加和算出总成绩
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
**函数名：CourseTotalAver
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：输出每门课程总成绩和平均成绩
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
**函数名：PrintScore
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：输出学生学号姓名和各科成绩
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
**函数名：SelectionSort
**输入：*stu,stunum,cournum,(*compare)(int a,int b)
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**(*compare)--升序或降序函数
**功能：实现升序或降序的选择排序
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
**函数名：Ascending
**输入：a，b--要比较的数
**输出：a>b输出0,a<b输出1
**功能：实现升序
***************************************/
int Ascending(int a,int b)
{
    return a<b;
}

/***************************************
**函数名：Descending
**输入：a，b--要比较的数
**输出：a>b输出1,a<b输出0
**功能：实现降序
***************************************/
int Descending(int a,int b)
{
    return a>b;
}

/***************************************
**函数名：SelectionSortNum
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：实现依学号的选择排序
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
**函数名：SelectionSortName
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：实现依姓名的选择排序
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
**函数名：LinSearch
**输入：*stu,x,stunum,cournum
***stu--学生相关数据
**x--要查找的学号
**stunum--学生数
**cournum--课程数
**输出：学号存在返回0，学号不存在则输返回-1
**功能：根据学号查找成绩和排名
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
**函数名：LinSearchName
**输入：*stu,input[],stunum,cournum
***stu--学生相关数据
**input[]--要查找的姓名
**stunum--学生数
**cournum--课程数
**输出：学号存在返回0，学号不存在则输返回-1
**功能：根据姓名查找成绩和排名
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
**函数名：PrintGrade
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：实现分类别统计
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
**函数名：WritetoFile
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：将学生信息写入文件
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
**函数名：ReadfromFile
**输入：*stu,stunum,cournum
***stu--学生相关数据
**stunum--学生数
**cournum--课程数
**功能：将学生信息读出文件
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
