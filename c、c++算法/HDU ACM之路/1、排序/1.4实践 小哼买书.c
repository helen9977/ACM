#include <stdio.h>
/*先去重 然后排序 桶排序*/
/*
int main ()
{
	int i,n,t,sum=0;
	int a[1001];
	scanf("%d",&n);
	for(i=0;i<1001;i++)
		a[i]=0;//初始化

	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a[t]=1;//表明这个数字出现过
	}
	for(i=0;i<1001;i++)
	{
		if(a[i]==1)//存在这个数字 计数
			sum++;			
	}
	printf("%d\n",sum );
	for(i=0;i<1001;i++)
	{
		if(a[i]==1)
			printf("%d ", i);
	}
	return 0;
}
*/
/*先排序 再去重*/
int a[101],n;

void quicksort(int left,int right)
{
	int i,j,temp,t;
	if(left>right)
		return;

	temp=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp && i<j)
			j--;
		while(a[i]<=temp && i<j)
			i++;

		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];
	a[i]=temp;

	quicksort(left,i-1);
	quicksort(i+1,right);
	return ;

}

int main()
{
	int i;

	scanf("%d",&n);

	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	quicksort(1,n);

	printf("%d ",a[1] );
	for(i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			printf("%d ",a[i] );
	}

	return 0;
}