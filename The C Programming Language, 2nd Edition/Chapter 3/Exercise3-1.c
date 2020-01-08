#include <stdio.h>

int binsearch(int x, int v[], int n);
int newbinsearch(int x, int v[], int n);

main()
{
	int v[] = { 6, 8, 10, 11, 15 };
	
	printf("%d\n", binsearch(11, v, 5));
	printf("%d\n", newbinsearch(11, v, 5));
}

int newbinsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while(low <= high && x != v[mid]) {
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	
	if(x == v[mid])
		return mid;
	else
		return -1;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}