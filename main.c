#include <stdlib.h>
#include "temp_functions.h"
#include <stdio.h>

int main(void)

{
struct sensor* info = malloc(SIZE*sizeof(struct sensor));
int number=AddInfo(info);
	print(info,number);
	printf("\nSort by t\n");
	SortByT(info,number);
	print(info,number);
	printf("\nSort by date\n");
	SortByDate(info,number);
	print(info,number);
	printf("\nAverage temperature per month - ATM\n");
	AverMonthTemp(info, number);
	printf("\nMinimum temperature per month - MinTM\n");
	MinTempPerMonth (info, number);
	printf("\nMaximum temperature per month - MaxTM\n");
	MaxTempPerMonth (info, number);
	printf("\nAverage temperature per year - ATY\n");
	AverYearTemp (info, number);
	printf("\nMinimum temperature per year - MinTY\n");
	MinYearTemp (info, number);
	printf("\nMaximum temperature per year - MaxTY\n");
	MaxYearTemp (info, number);
	free(info);
	return 0;
}
