#include <stdio.h>
int s,d,sum;


int main ()
{
	while(~scanf("%d%d",&s,&d))
	{
		if(4*s<d)
			sum=10*s-2*d;
		else if(3*s<2*d)
			sum=8*s-4*d;
		else if(2*s<3*d)
			sum=6*s-6*d;
		else if(s<4*d)
			sum=3*s-9*d;
		else 
			sum=0;
		if(sum<=0)
			printf("Deficit\n");
		else
			printf("%d\n",sum );

	}
	return 0;
}