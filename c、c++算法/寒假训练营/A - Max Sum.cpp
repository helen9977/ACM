#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int dp,sum;
	int s,e,k;
	int a;
	int t,n;
	int m;
	scanf("%d",&t);
	for(m=1;m<=t;m++)
	{
		
		scanf("%d",&n);
		scanf("%d",&a);
		sum=dp=a;
		s=e=k=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a);
			if(dp+a<a)
			{
				dp=a;
				k=i;
			}
			else
			{
				dp=dp+a;
			}
			if(dp>sum)
			{
				sum=dp;
				s=k;
				e=i;
			}

		}
		printf("Case %d:\n%d %d %d\n",m,sum,s+1,e+1);
		if(m-t)
			printf("\n");

	}
	return 0;
}