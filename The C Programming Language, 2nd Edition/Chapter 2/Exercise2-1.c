#include <stdio.h>
#include <limits.h>
#include <float.h>

main()
{
	
	printf("Data Type\t\tMax\t\tMin\n");
	printf("signed int\t\t%d\t%d\n", INT_MAX, INT_MIN);
	printf("signed long\t\t%d\t%d\n", LONG_MAX, LONG_MIN);
	printf("signed char\t\t%d\t\t%d\n", SCHAR_MAX, SCHAR_MIN);
	printf("signed short\t\t%d\t\t%d\n", SHRT_MAX, SHRT_MIN);
	printf("unsigned char\t\t%d\t\t%d\n", UCHAR_MAX, 0);
	printf("unsigned int\t\t%d\t\t%d\n", UINT_MAX, 0);
	printf("unsigned long\t\t%d\t\t%d\n", ULONG_MAX, 0);
	printf("unsigned short\t\t%d\t\t%d\n", USHRT_MAX, 0);
	printf("float\t\t%f\t\t%f\n", FLT_MAX, FLT_MIN);
	printf("double\t\t%f\t\t%f\n", DBL_MAX, DBL_MIN);
}