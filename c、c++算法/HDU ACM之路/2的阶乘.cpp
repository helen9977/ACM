#include <stdio.h>
int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int s=0;
		int y=0;
		scanf("%d",&n);
		for(int i=2;i<=n;i+=2)
		{
			int m=i;
			while(m%2==0)
			{
				y=m/2;
				s++;
				m=y;
			}
		}
		printf("%d\n",s);
	}
	return 0;

}