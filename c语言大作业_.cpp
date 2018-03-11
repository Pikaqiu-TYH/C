#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
struct student_type//为了储存给出过题文件的内容 
{
	int id;
	int problem_id;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}grade[100000];
struct student//给每个人的过题记录进行时间排序 
{
	int id;
	int problem_id;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}stu[1000];
struct student1//给新的过题的记录进行间接性储存 
{
	int id;
	int problem_id;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}grade1[100000];
struct grade_calculate//收集每个人每道题的记录，进行排名，和给出对应积分 
{
	int id;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}gra[10000];
struct performance//最后的积分和成绩的排名 
{
	int id;
	int integral;
	int grade;
}stud[1000];
int cmp(const void *a,const void *b) 
{
	return *(int*)a-*(int*)b;
}
int sort_cmp(const void *a,const void *b)
{
	struct performance *p1,*p2;
    p1=(performance *)a;
    p2=(performance *)b;
    if(p1->grade!=p2->grade) return p1->grade-p2->grade;
    else
    {
    	if(p1->integral!=p2->integral) return p1->integral-p2->integral;
    	else 
    	{
    		return 1;
    	}
    }
}
int sort_comp(const void *a,const void *b)
{
	struct student *p1,*p2;
    p1=(student *)a;
    p2=(student *)b;
    if(p1->year!=p2->year) return p1->year-p2->year;
    else
    {
    	if(p1->month!=p2->month) return p1->month-p2->month;
    	else 
    	{
    		if(p1->day!=p2->day) return p1->day-p2->day;
    		else 
    		{
    			if(p1->hour!=p2->hour) return p1->hour-p2->hour;
	    		else 
	    		{
	    			if(p1->min!=p2->min) return p1->min-p2->min;
		    		else 
		    		{
		    			if(p1->sec!=p2->sec) return p1->sec-p2->sec;
			    		else 
			    		{
			    			return 1;
			    		}
		    		}
	    		}
    		}
    	}
    }
}
int cmmp(const void *a,const void *b)
{
	struct grade_calculate *p1,*p2;
    p1=(grade_calculate *)a;
    p2=(grade_calculate *)b;
    if(p1->year!=p2->year) return p1->year-p2->year;
    else
    {
    	if(p1->month!=p2->month) return p1->month-p2->month;
    	else 
    	{
    		if(p1->day!=p2->day) return p1->day-p2->day;
    		else 
    		{
    			if(p1->hour!=p2->hour) return p1->hour-p2->hour;
	    		else 
	    		{
	    			if(p1->min!=p2->min) return p1->min-p2->min;
		    		else 
		    		{
		    			if(p1->sec!=p2->sec) return p1->sec-p2->sec;
			    		else 
			    		{
			    			return 1;
			    		}
		    		}
	    		}
    		}
    	}
    }
}
int main()
{
	FILE *fp;
	int a=0,b=0,c,d,e,i,j,y=0,x,v;
	char arr[100],ch,filename[]="E:/编程/c2017.txt",filename1[]="E:/编程/要删除的文件.txt",filename2[]="E:/编程/成绩.txt",newname[100];
	struct tm time_cha;
	time_t t1,t2;
	long int l;
	fp=fopen(filename,"r+");
	if(fp==NULL)
	{
		printf("cannot open the file!\n"); 
		exit(1);
	}
	else
	{
		fgets(arr,100,fp);//把第一行的记录取走，方便后续读取数据 
		while(!feof(fp))
		{
			fscanf(fp,"%d %d %d-%d-%d %d:%d:%d\n",&grade[a].id,&grade[a].problem_id,&grade[a].year,&grade[a].month,&grade[a].day,&grade[a].hour,&grade[a].min,&grade[a].sec);
			a++;
		}
	}
	fclose(fp);
	int L,N,p,f;
	printf("请输入时长：\n");
	scanf("%d",&L);
	printf("请输入过题数：\n");
	scanf("%d",&N); 
	printf("文件名：%s  时长：%d 过题数：%d\n",filename1,L,N);
	fp=fopen(filename1,"w");         //进行统计个人做题数，时长。 
	if(fp==NULL)
	{
		printf("cannot open the file!\n"); 
		exit(1);
	}
	else
	{
		for(i=0,f=0;i<a;i=b) //扫描所有过题记录 
		{
			y++;//统计人数 
			for(j=0,c=i;;j++,c++)//把同一个人所做的题存于一个结构体中 
			{
				stu[j].problem_id=grade[c].problem_id;
				stu[j].year=grade[c].year;
				stu[j].month=grade[c].month;
				stu[j].day=grade[c].day;
				stu[j].hour=grade[c].hour;
				stu[j].min=grade[c].min;
				stu[j].sec=grade[c].sec;
				if(grade[i].id!=grade[c].id) break;
			}
			b=c;//每一次i的位置 
			d=j;//结构体数组的大小 
			qsort(stu,d,sizeof(stu[0]),sort_comp);//对时间进行排序 	
			for(x=0,j=1;j<d;j++)
			{
				time_cha.tm_year = stu[x].year - 1900;
				time_cha.tm_mon = stu[x].month - 1;
				time_cha.tm_mday = stu[x].day;
				time_cha.tm_hour = stu[x].hour;
				time_cha.tm_min = stu[x].min;
				time_cha.tm_sec = stu[x].sec;
				t1 = mktime(&time_cha);
				time_cha.tm_year = stu[j].year - 1900;
				time_cha.tm_mon = stu[j].month - 1;
				time_cha.tm_mday = stu[j].day;
				time_cha.tm_hour = stu[j].hour;
				time_cha.tm_min = stu[j].min;
				time_cha.tm_sec = stu[j].sec;
				t2 = mktime(&time_cha);
				l=round((t2*1.0-t1*1.0)/60.0);//算两两间隔时长 
				if(l>L) x++,j=x;
				else if(l<=L&&j-x+1>=N)
				{
					for(p=j;p<d;p++)//算最大满足时长和题数 
					{
						time_cha.tm_year = stu[p].year - 1900;
						time_cha.tm_mon = stu[p].month - 1;
						time_cha.tm_mday = stu[p].day;
						time_cha.tm_hour = stu[p].hour;
						time_cha.tm_min = stu[p].min;
						time_cha.tm_sec = stu[p].sec;
						t2 = mktime(&time_cha);
						l=round((t2*1.0-t1*1.0)/60.0);
						if(l>L) break;
					}
					time_cha.tm_year = stu[p-1].year - 1900;
					time_cha.tm_mon = stu[p-1].month - 1;
					time_cha.tm_mday = stu[p-1].day;
					time_cha.tm_hour = stu[p-1].hour;
					time_cha.tm_min = stu[p-1].min;
					time_cha.tm_sec = stu[p-1].sec;
					t2 = mktime(&time_cha);
					l=round((t2*1.0-t1*1.0)/60.0);
					fprintf(fp,"ID        开始时间                时长 （min）               过题数\n");
					fprintf(fp,"%d    %d-%d-%d %d:%d:%d           %d(min)                    %d\n",grade[i].id,stu[x].year,stu[x].month,stu[x].day,stu[x].hour,stu[x].min,stu[x].sec,l,p-x);
					fprintf(fp,"\n");
					for(v=x;v<=p-1;v++)
					{
						fprintf(fp,"          %d  %d-%d-%d %d:%d:%d\n",stu[v].problem_id,stu[v].year,stu[v].month,stu[v].day,stu[v].hour,stu[v].min,stu[v].sec);
						stu[v].problem_id=0;
					}
					fprintf(fp,"\n");
					x=p;
				    j=x;
				}
			}
			for(j=0;j<d;j++)
			{
				if(stu[j].problem_id!=0)
				{
					grade1[f].id=grade[i].id;
					grade1[f].problem_id=stu[j].problem_id;
					grade1[f].year=stu[j].year;
					grade1[f].month=stu[j].month;
					grade1[f].day=stu[j].day;
					grade1[f].hour=stu[j].hour;
					grade1[f].min=stu[j].min;
					grade1[f].sec=stu[j].sec;
					f++;
				}
			}
	    }  
	}	
	fclose(fp);
	printf("请输入文件名字：");
	scanf("%s",newname);
	strcat(newname, ".txt");
	rename(filename,newname);//用户自己输入名字 
	fp=fopen(newname,"w");
	if(fp==NULL)
	{
		printf("cannot open the file!\n"); 
		exit(1);
	}
	else
	{
		fprintf(fp,"%s",arr);
		for(c=0;c<f;c++)
		{
			fprintf(fp,"%d %d %d-%d-%d %d:%d:%d\n",grade1[c].id,grade1[c].problem_id,grade1[c].year,grade1[c].month,grade1[c].day,grade1[c].hour,grade1[c].min,grade1[c].sec);
		}
	}
	fclose(fp);
	fp=fopen(filename2,"w+");//计算成绩积分排名。 
	if(fp==NULL)
	{
		printf("cannot open the file!\n"); 
		exit(1);
	}
	else
	{
		int brr[1000],crr[501][1001],drr[1000]={0},err[1000]={0},g,k=1,h;
		double large,s;
		for(i=0;i<501;i++)//对此二维数组进行清零(它的作用是储存每个人的各题所得积分） 
		{
			for(j=0;j<1001;j++) crr[i][j]=0;
		}
		brr[0]=grade1[0].problem_id;//得到第一个题目id 
		for(i=1;i<f;i++)//收集题目的序号 存于一个数组中 
		{
			for(j=0;j<k;j++)
			{
				if(grade1[i].problem_id==brr[j]) break;
			}
			if(j==k)
			{
				brr[j]=grade1[i].problem_id;
				k++;
			}
		}
		for(i=0,g=0;i<k;i++,g++) //统计每题所做的记录 
		{
			for(j=0,c=0;j<f;j++)
			{
				if(brr[i]==grade1[j].problem_id)
				{
					gra[c].id=grade1[j].id;
					gra[c].year=grade1[j].year;
					gra[c].month=grade1[j].month;
					gra[c].day=grade1[j].day;
					gra[c].hour=grade1[j].hour;
					gra[c].min=grade1[j].min;
					gra[c].sec=grade1[j].sec;
					c++;
				}
			}
			qsort(gra,c,sizeof(gra[0]),cmmp);//对做题的人进行时间排序 
		    for(h=0;h<c;h++)//给出对应积分 
			{
				if(h<=11) crr[gra[h].id][g]=32;
				else if(h>11&&h<=23) crr[gra[h].id][g]=16;
				else if(h>23&&h<=47) crr[gra[h].id][g]=8;
				else if(h>47&&h<=95) crr[gra[h].id][g]=4;
				else if(h>95&&h<=191) crr[gra[h].id][g]=2;
				else if(h>191) crr[gra[h].id][g]=1;
			}
		}
		for(i=1;i<y+1;i++)//把每个人的积分进行累加 
		{
			for(j=0;j<g;j++) drr[i]+=crr[i][j];
			err[i]=drr[i];
		}
		qsort(drr,y+1,sizeof(drr[1]),cmp);
		large=drr[y];//找出最高积分 
		for(i=1;i<y+1;i++)//进行成绩运算 
		{
			s=int((100+log(1+(err[i]-large)/large)*10)+0.5);
			stud[i].integral=err[i];
			stud[i].id=i;
			stud[i].grade=s;
		}
		qsort(stud,y+1,sizeof(stud[1]),sort_cmp);//进行排名 
		fprintf(fp,"排名       ID         积分       成绩\n");
		for(i=y,j=1;i>=1;i--,j++)//最后打印成绩单 
		{
			fprintf(fp,"%-10d %-10d %-10d %-10d\n",j,stud[i].id,stud[i].integral,stud[i].grade);
		}
	}	
	fclose(fp);
	return 0;
} 
