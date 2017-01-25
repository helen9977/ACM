#include <stdio.h>
int n,k;

int jc(int i)
{
	if (i==0)
		return 1;
	else
		return i*jc(i-1);
}

int main()
{
	//printf("%d\n",jc(5));

	while(~scanf("%d%d",&n,&k))
	{
		int a,b,c;
		a=jc(n);
		b=jc(k);
		c=jc(n-k);
		printf("%d\n",a/(b*c));
	}
	return 0;
}