#include <stdio.h>
int a[101],n;

void quicksort (int left ,int right)
{
	int i,j,t,temp;
	if(left>right)
		return ;
	temp=a[left];//存放基数
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp && j>i)
			j--;
		while(a[i]<=temp && j>i)
			i++;
		if(i<j)//当两个哨兵没有相遇时，交换两个数在数组中的位置
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	//当两个哨兵相遇
	a[left]=a[i];//先找寻新的基点
	a[i]=temp;//将原来的基点归位

    //使用递归完成基点前后的排序
	quicksort(left,i-1);
	quicksort(i+1,right);
	return ;
}


int main ()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);//读入数据

	quicksort(1,n);//整理数据

	for(i=1;i<=n;i++)//输出数据
		printf("%d ",a[i] );

	return 0; 


}