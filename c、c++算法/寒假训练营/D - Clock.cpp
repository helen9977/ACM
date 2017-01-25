#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
	int h,m,s;
	int d=1;
	int s1,s2,m1,m2,h1,h2;
	while(~ scanf("%d:%d:%d",&h,&m,&s))
	{
		
		int an;
		scanf("%d",&an);
		an=an*120;
		s1=3600*h+m*60+s;
		h1=s1%43200;
		m1=(s1*12)%43200;
		int num=0;
		while(1)
		{
			h1=(h1+1)%43200;
			m1=(m1+12)%43200;
			num++;
			if(abs(abs(h1-m1)-an)<=10)
				break;
		}
		s2=(num+s)%60;
		m2=((num+s)/60+m)%60;
		h2=((((num+s)/60+m)/60)+h)%12;
		printf("Case #%d: %02d:%02d:%02d\n",d,h2,m2,s2 );
		d++;
	}
	return 0;
}