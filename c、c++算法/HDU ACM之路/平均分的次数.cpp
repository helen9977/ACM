#include <stdio.h>
int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int sum=0;
		int y=0;
		while(n!=1)
		{
			y=n/2;
			sum+=y;
			n=y;
		}
		printf("%d\n", sum);
	}
}