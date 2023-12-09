#include <stdlib.h>
#include "temp_functions.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])

{
struct sensor* info = malloc(SIZE*sizeof(struct sensor));

	char name[255], c;
	int j = 0;
	//printf("argument count = %d\n", argc);
	for(int i=1; i<argc; i++)
	{
		printf("%d: %s\n", i, argv[i]);
	}
	if ((argc < 2) || ((argv[1][1] != 'h') && (argv[1][1] != 'f') && (argv[1][1] != 'm')))
	{
		printf("input character -h to get HELP\n");
		printf("input character -f and specify the file name\n");
		printf("input character -m and enter the month number\n");
	}
	if (((argc < 3) || (strlen(argv[1])>=2)) && (argv[1][1] == 'h'))
	{
		printf("input character -f and specify the file name\n");
		printf("input character -m and enter the month number\n");
	}
	if (((argc < 3) && (strlen(argv[1])>=2) && (argv[1][1] == 'f')))
	{
		printf("specify the file name\n");
		printf("input character -m, specify month number\n");
	}
	if (((argc > 2) && (strlen(argv[1])>=2) && (argv[1][1] == 'f') && (strlen(argv[2])>=5)))
	{
		while((c = getchar()) != '\n' && j<255)
			name[j++] = c;
	}
	printf("%s", name);
	/*
	if ((argc >2)&&(argv[1][1] == 'h')&&(strlen(argv[1])>2))
	{
		printf("input character -f and specify the file name\n");
		printf("input character -m and enter the month number\n");
	}
	else if ((argc >2)&&(argv[1][1] == 'f'))
		{
			printf("input character -f <filename>\n");
			
		}
	*/
	
	
	//ComandLine(struct sensor* info, char name[]);
int number=AddInfo(info, name);
	print(info,number);
	//printf("\nSort by t\n");
	SortByT(info,number);
	print(info,number);
	//printf("\nSort by date\n");
	SortByDate(info,number);
	print(info,number);
	//printf("\nAverage temperature per month - ATM\n");
	AverMonthTemp(info, number);
	//printf("\nMinimum temperature per month - MinTM\n");
	MinTempPerMonth (info, number);
	//printf("\nMaximum temperature per month - MaxTM\n");
	MaxTempPerMonth (info, number);
	//printf("\nAverage temperature per year - ATY\n");
	AverYearTemp (info, number);
	//printf("\nMinimum temperature per year - MinTY\n");
	MinYearTemp (info, number);
	//printf("\nMaximum temperature per year - MaxTY\n");
	MaxYearTemp (info, number);
	free(info);
	return 0;
}
