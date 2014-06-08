#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct{
	char sign;
	int time;
	float amt;
	char descr[100];
}trans;

int main()
{
	int i;
	char amount[20];
	int bdec, adec; 
	char str[1025];
	char cal[24];
	char *str1 = NULL;
	char *start = NULL;
	char *end = NULL;
	trans array[15];	
	struct tm *info;
	char wk[4];
	char mon[4];
	int dy, yr;
	FILE *fp = NULL;
	const char *week[7]= {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; 
	const char *month[12]= {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; 

	fp = fopen("test.tfile", "r+");
//	printf("*  File Pointer is %p\n", fp);

	printf("+-----------------+--------------------------+----------------+----------------+\n");
	printf("|       Date      | Description              |         Amount |        Balance |\n");
	printf("+-----------------+--------------------------+----------------+----------------+\n");
	for(i = 0; i < 10; i++)
{
	fgets( str, 1024, fp);
	//printf("*  String is %s, %d\n", str, strlen(str));

	sscanf(str, "%c %d %f", &array[i].sign, &array[i].time, &array[i].amt);
	//printf("*  String Pointer: %p\n", str);
	str1 = strchr(str, '\t');
	//printf("*  String Pointer: %p\n", str1);
	str1 = strchr(++str1, '\t');
	//printf("*  String Pointer: %p\n", str1);
	str1 = strchr(++str1, '\t');
	//printf("*  String Pointer: %p\n", str1);
	//printf("*  String Pointer: %s\n", ++str1);
	start = ++str1;

	str1 = strchr(++str1, '\n');
	//printf("*  String Pointer: %p\n", str1);

	end = str1;
//	printf("*  String size: %d\n", (int)(end - start));
//	printf("* Leading Space: %d\n", isspace(*start));
	while(isspace(*start))
	{
		start++;
	}

	strncpy(array[i].descr, start, (int)(end -start));
	strncpy(array[i].descr + (int)(end - start),"\0", 1);
	
//	printf("*  Sign is %c\n", array[i].sign);
//	printf("*  Time is %d\n", array[i].time);
//	printf("*  Amount is %.2f\n", array[i].amt);
//	printf("*  Description is %s\n", array[i].descr);

	time_t rawtime = array[i].time;

	/* Get GMT time */
	info = gmtime(&rawtime );
	str1 = ctime(&rawtime);
	strncpy(cal, str1, 24);
	strncpy(cal+24,"\0", 1);
	sscanf(cal, "%3s %3s %d %*d%*c%*d%*c%*d %d", wk, mon, &dy, &yr);
//	printf("| %s", wk);
	sprintf(cal, "%s %s %2d %4d", wk, mon, dy, yr);
	array[i].descr[24] = '\0';
	if (strcmp(&array[i].sign, "+"))
	{
		if(array[i].amt > 10000000)
			sprintf(amount, "(\?,\?\?\?,\?\?\?.\?\?)");	
		else
			sprintf(amount, "(%12.2f)", array[i].amt);	
	}
	else
	{
		if(array[i].amt > 10000000)
			sprintf(amount, " ?,???,???.?? ");	
		else
			sprintf(amount, " %12.2f ", array[i].amt);	
	}
	
	printf("| %s | %24s | %s | %s |\n", cal, array[i].descr, amount, amount);
//	printf("| %s %s %2d %4d | \n", week[info->tm_wday], month[info->tm_mon], info->tm_mday, info->tm_year + 1900);
//	printf(" %c | %d | %10.2f | %s |\n", array[i].sign, array[i].time, array[i].amt, array[i].descr);
}
	printf("+-----------------+--------------------------+----------------+----------------+\n");

	return 0;
}

