#include <stdio.h>
#include <math.h>
int T,m;

int isPrime(int n)
{
    if(n < 2) return 0;
    if(n == 2) return 1;

    for(int i = 2; i*i <= n; i ++)
        if(n%i == 0) return 0;

    return 1;
}
int issq(int n)
{
	int i=sqrt(n);
	if(i*i==n)
		return 1;
	else
		return 0;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&m);
		if(issq(m)&&isPrime(sqrt(m)))
		{
			printf("%d\n",m);
		}
		else
		{
			int i=m;
			int j=0;
			int flag=0;
			while(flag==0)
			{
				j++;
				i=m-j;
				if( i>=0&&(issq(i)==1) && (isPrime(sqrt(i))==1) )
					{
						printf("%d\n",i);
						flag=1;
						break;
					}
				else
				{
					i=m+j;
					if(i>=0&&(issq(i)==1) && (isPrime(sqrt(i))==1) )
					{
						printf("%d\n",i);
						flag=1;
						break;
					}
					
				}
			}
		}
	}	
	return 0;
}