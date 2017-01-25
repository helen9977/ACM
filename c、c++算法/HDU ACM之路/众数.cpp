#include <stdio.h>
#include <algorithm>
using namespace std; 

int main()
{
	int T,n,s=0,maxz,max1;
	int a[1001],book[1001];
	scanf("%d",&T);
	for(int i=0;i<=1000;i++)
		book[i]=0;
	for(int i=0;i<T;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			book[a[j]]++;
		}
		maxz=book[0];
		max1=0; 
		for(int k=0;k<1001;k++)
		{
			if(book[k]>maxz)
				{
					maxz=book[k];
					max1=k;
				}
			
		}
		printf("%d",max1);
		for(int k=0;k<1001;k++)
		{
			if(book[k]==maxz && k!=max1)
			printf(" %d",k);
			
		}
	}
	return 0;
}
