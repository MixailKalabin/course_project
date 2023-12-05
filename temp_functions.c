#include <stdio.h>
#include "temp_functions.h"
#include <string.h>
#include <stdlib.h>


void changeIJ(struct sensor* info,int i,int j)

{
struct sensor temp;
	temp=info[i];
	info[i]=info[j];
	info[j]=temp;
}

//упорядочивающую его по неубыванию температуры
void SortByT(struct sensor* info,int n)
{
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(info[i].t>=info[j].t)
				changeIJ(info,i,j);
}


long long int DateToInt(struct sensor* info)
{
	return (long long) info->year << 32 | info->month << 24 | info->day << 16 | info->hour << 8 | info->minute;
}
//упорядочивающую его по дате
void SortByDate(struct sensor* info,int n)
{
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(DateToInt(info+i)>= DateToInt(info+j))
				changeIJ(info,i,j);
}

void AddRecord(struct sensor* info,int number, uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t t)
{
	info[number].year = year;
	info[number].month = month;
	info[number].day = day;
	info[number].hour = hour;
	info[number].minute = minute;
	info[number].t = t;
}


int AddInfo(struct sensor* info, char name[])
{
	FILE *open;
	//char name[] ="temperature_big.csv";
	open = fopen(name, "r");
	if(open==NULL)
		return 1;
	int counter = 0;
	int Y, M, D, H, m, T ,n_scan;
	while((n_scan = fscanf(open, "%d;%d;%d;%d;%d;%d", &Y, &M, &D, &H, &m, &T)) > 0)
	{
		if (n_scan < 6)
		{
			char s[20], c;
			n_scan = fscanf(open, "%[^\n]%c", s, &c);
			printf("Wrong format in line %s\n", s);
		}
		else
		{
			printf("%d; %d; %d; %d; %d; t = %d\n",Y,M,D,H,m,T);
			AddRecord(info,counter++,Y,M,D,H,m,T);
		}
	}
	fclose(open);
	return counter;
}



void print(struct sensor* info,int number)
{
	printf("===================================\n\n");
	for(int i=0;i<number;i++)
		printf("%04d-%02d-%02d-%02d-%02d t=%3d\n",
			info[i].year,
			info[i].month,
			info[i].day,
			info[i].hour,
			info[i].minute,
			info[i].t
		);
}

void AverMonthTemp (struct sensor* info, int n)

{
	int k;
	printf("===================================\n");
	printf ("Choose month number: ");
	scanf ("%d", &k);
	float sum = 0;
	int count = 0;
	float aver = 0;
	for (int i=0; i<=n; i++)
	{
		if (info[i].month == k)
		{
			count++;
			sum = sum + info[i].t;
		}
	}
	aver = sum/count;
	printf("Average temperature per %d month = %.2f\n", k, aver);
}

void MinTempPerMonth (struct sensor* info, int n)

{
	int k;
	printf("===================================\n");
	printf ("Choose month number: ");
	scanf ("%d", &k);
	int Min = info[0].t;
	for(int i=0;i<n;i++)
		if (info[i].month == k && info[i].t <= Min)
			Min = info[i].t;
	printf("Minimum t per %d month = %d\n", k,  Min);
}


void MaxTempPerMonth (struct sensor* info, int n)
{
	int k;
	printf("===================================\n");
	printf ("Choose month number: ");
	scanf ("%d", &k);
	int Max = info[0].t;
	for(int i=0;i<n;i++)
		if (info[i].month == k && info[i].t > Max)
			Max = info[i].t;
	printf("Maximum t per %d month = %d\n", k, Max);
}


void AverYearTemp (struct sensor* info, int n)

{
	printf("===================================\n\n");
	float sum = 0;
	int count = 0;
	float aver = 0;
	for (int i=0; i<=n; i++)
	{
		count++;
		sum = sum + info[i].t;
	}
	aver = sum/count;
	printf("Average temperature per %d year = %.2f\n", info->year, aver);
}

void MinYearTemp (struct sensor* info, int n)

{
	printf("===================================\n\n");
	int Min = info[0].t;
	for (int i=1; i<n; i++)
	{
		if(Min > info[i].t)
			Min = info[i].t;
	}
	printf("Minimum t per year = %d\n", Min);
}

void MaxYearTemp (struct sensor* info, int n)
{
	printf("===================================\n\n");
	int Max=info[0].t;
	for (int i=0; i<n; i++)
		if(Max < info[i].t)
			Max = info[i].t;
	printf("Maximum t per year = %d\n", Max);
}





