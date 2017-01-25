#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,t;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		for(int i=1;i<=t;i++)
		{
			if (i==1)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}