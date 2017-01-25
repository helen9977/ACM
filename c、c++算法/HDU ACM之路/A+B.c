
#include <stdio.h>
#include <iostream>
using namespace std;

int mul(int a,int b)
{

	int t;
	while(b)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}

int main ()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if (a==-1&&b==-1)
			break;
		if(mul(a,b)==1)
			cout<<"YES"<<endl;
		else
			cout<<"POOR Haha"<<endl;
	}

	return 0;
}