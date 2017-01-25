#include <stdio.h>
int main()
{
	int book[11],i,j,t,n;//the number from 0 to 10;桶代表对应得分
	for (i=0;i<11;i++)//初始化每个桶里都没有次数
	{
		book[i]=0;
	}
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&t);
		book[t]++;// record the times;
	}
	for (i=0;i<10;i++)//对10个桶进行检查 
		for(j=1;j<=book[i];j++)
			printf("%d\t",i );//出现几次就将‘桶的编号’打印几次
	return 0;

}
