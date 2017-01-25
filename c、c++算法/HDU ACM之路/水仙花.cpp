#include <stdio.h>
#include <math.h>
int main ()
{
	int i,a,n,b,sum;
	scanf("%d",&n);
	int m,k;
	m=pow(10,n-1);
	k=pow(10,n);
	for(i=m;i<k;i++)
	{
		a=i;
		sum=0; 
		while(a)
		{
			b=a%10;
			sum+=pow(b,n);
			a=a/10;
		}
		if(sum==i)
			printf("%d\n", i);
	}
	return 0;
}


