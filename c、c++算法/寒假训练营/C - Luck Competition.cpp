#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int x[100];
int main ()
{
	int n,t;
	scanf("%d",&n);
	while(n--)
	{
		int sum=0;
		memset(x,0,sizeof(x));
		scanf("%d",&t);
		for(int i=1;i<t;i++)
		{
			scanf("%d",&x[i]);
			sum+=x[i];
		}
		x[0]=2*sum/(3*t-2);
		printf("%d ",x[0]);
		int s=1;
		for(int i=1;i<t;i++)
		{
			
			if(x[i]==x[0])
			s++;
		}
		double p=1.0/s;
		printf("%.2f\n",p);
	}
	return 0;
}