#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

int main()
{
	int v, a, b, day, go; day = 1;
	scanf("%d %d %d", &a, &b, &v);
	go = a - b;
	day += (v-a) / go;
	
	if ((v - a) % go != 0)
		day++;

	printf("%d\n", day);
}