#include <stdlib.h>
#include "temp_functions.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])

{
struct sensor* info = malloc(SIZE*sizeof(struct sensor));

	int rez=0;
	while ( (rez = getopt(argc,argv,"hf:m:")) != -1){
		switch (rez){
			case 'h': printf("found argument \"h\".\n"); break;
			case 'f': printf("found argument \"b = %s\".\n",optarg); break;
			case 'm': printf("found argument \"m = %s\".\n",optarg); break;
			case '?': printf("Error found !\n");break;
		};
	};


int number=AddInfo(info, "temperature_big.csv");
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
