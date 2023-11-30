#include <stdint.h>
#define SIZE 30

struct sensor {
	uint8_t day;
	uint8_t month;
	uint16_t year;
	uint8_t minute;
	uint8_t hour;
	int8_t t;
};
void changeIJ(struct sensor* info,int i,int j);

//упорядочивающую его по неубыванию температуры
void SortByT(struct sensor* info,int n);

long long int DateToInt(struct sensor* info);

//упорядочивающую его по дате
void SortByDate(struct sensor* info,int n);

void AddRecord(struct sensor* info,int number,uint16_t year,uint8_t month,uint8_t day,uint8_t hour,uint8_t minute,int8_t t);

int AddInfo(struct sensor* info);

void print(struct sensor* info,int number);

void AverMonthTemp (struct sensor* info, int n);

void MinTempPerMonth (struct sensor* info, int n);

void MaxTempPerMonth (struct sensor* info, int n);

void AverYearTemp (struct sensor* info, int n);

void MinYearTemp (struct sensor* info, int n);

void MaxYearTemp (struct sensor* info, int n);
