#include <stdio.h>
int a[100001];
int main()
{
	int n;
	int s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int p=i+1;
		if(a[p]==0)
		{
			a[p]=1;
		
			s=(n+1)/p;
			for(int j=2;j<=s;j++)
			{
				if(a[p*j]==0)
				{
					a[p*j]=2;
				}
			}
		}
	}
	if(n>=3)
		printf("2\n");
	else
		printf("1\n");
	for(int i=2;i<=n+1;i++)
        printf("%d ",a[i]);
    return 0;

}