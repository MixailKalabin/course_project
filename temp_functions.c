#include <stdio.h>
#include "temp_functions.h"
#include <string.h>


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

int AddInfo(struct sensor* info)
{
 int counter=0;
 AddRecord(info,counter++,2021,8,16,13,10,9);
 AddRecord(info,counter++,2021,12,2,22,30,-9);
 AddRecord(info,counter++,2021,12,2,22,30,-21);
 AddRecord(info,counter++,2021,12,2,22,30,-30);
 AddRecord(info,counter++,2021,12,2,22,30,-15);
 AddRecord(info,counter++,2021,12,2,22,30,-4);
 AddRecord(info,counter++,2021,1,7,8,10,6);
 AddRecord(info,counter++,2021,1,7,8,17,8);
 AddRecord(info,counter++,2021,1,7,8,27,9); 
 AddRecord(info,counter++,2021,10,5,12,55,1);
 AddRecord(info,counter++,2021,9,5,17,10,3);
 AddRecord(info,counter++,2021,9,5,20,45,2);
 AddRecord(info,counter++,2021,9,4,15,11,4);
 AddRecord(info,counter++,2021,10,4,12,23,1);
 AddRecord(info,counter++,2021,9,4,6,34,3);
 AddRecord(info,counter++,2021,8,3,11,6,5);
 AddRecord(info,counter++,2021,9,3,1,8,4);
 AddRecord(info,counter++,2021,9,3,8,14,1);
 AddRecord(info,counter++,2021,9,3,8,14,1);
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
	printf("ATM = %f.\n", aver);
}

void MinTempPerMonth (struct sensor* info, int n)

{
	int k;
	printf("===================================\n");
	printf ("Choose month number: ");
	scanf ("%d", &k);
	int Min;
	for (int i=0; i<=n; i++)
	{
		if (info[i].month == k)
			if(info[i].t < info[i+1].t)
				Min = info[i].t;
	}
	printf("Minimum t per month = %d\n", Min);
}


void MaxTempPerMonth (struct sensor* info, int n)
{
	int k;
	printf("===================================\n");
	printf ("Choose month number: ");
	scanf ("%d", &k);
	int Max;
	for (int i=0; i<=n; i++)
	{
		if (info[i].month == k)
			if(info[i].t > info[i+1].t)
				Max = info[i].t;
	}
	printf("Maximum t per month = %d\n", Max);
}

void AverYearTemp (struct sensor* info, int n)

{
	int k = info->year;
	printf("===================================\n\n");
	float sum = 0;
	int count = 0;
	float aver = 0;
	for (int i=0; i<=n; i++)
	{
		if (k)
		{
			count++;
			sum = sum + info[i].t;
		}
	}
	aver = sum/count;
	printf("Average temperature per %d year = %.2f\n", info->year, aver);
}

void MinYearTemp (struct sensor* info, int n)

{
	int k = info->year;
	printf("===================================\n\n");
	int Min;
	for (int i=0; i<=n; i++)
	{
		if (k)
			if(info[i].t < info[i+1].t)
				Min = info[i].t;
	}
	printf("Minimum t per %d year = %d\n", info->year, Min);
}

void MaxYearTemp (struct sensor* info, int n)
{
	//int k = info->year;
	printf("===================================\n\n");
	int Max;
	for (int i=0; i<n-2; i++)
	{
		if (info->year)
			if(info[i].t >= info[i+1].t)
			{
				Max = info[i].t;
				printf("%d\n", Max);
			}
	}
	printf("Maximum t per %d year = %d\n", info->year, Max);
}





