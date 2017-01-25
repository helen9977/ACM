#include <stdio.h>

int leapyear(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)
		return 1;
	else 
		return 0;
 } 
 
 int month(int m)
 {
 	int sm=0;
 	switch(m)
 	{
 		case 11: sm+=30;
 		case 12: sm+=31;
 		case 1: sm+=31;
 		case 2: sm+=28;
 		case 3: sm+=31;
 		case 4: sm+=30;
 		case 5: sm+=31;
 		case 6: sm+=30;
 		case 7: sm+=31;
 		case 8: sm+=31;
 		case 9: sm+=30;
 		case 10: sm+=0;
 	 }
	 	return sm;
 }
 
 int day(int d)
 {
 	int sd;
 	sd=28-d;
 	return sd;
  } 
  
  int year(int y)
  {
  	int sy; 
  	if (leapyear(y)==1)
  	sy=366;
  	else
  	sy=365;
  	return sy;
  }
  
  int main()
  {
  	int y,m,d;
  	int i;
  	int T;
  	int sumy=0,summ=0,sumd=0,sum=0;
  	scanf("%d",&T);
  	for(i=0;i<T;i++)
  	{
  		sumy=0,summ=0,sumd=0,sum=0;
  		scanf("%d%d%d",&y,&m,&d);
  		if(m>10)
  		{
		  for(int j=0;j<2017-y-1;j++)
		  	{
		  		y++;
				sumy+=year(y);
		  		
		  	}
		  
		}
		else if(m==10)
		{
		for(int j=0;j<2017-y;j++)
		  	{
				y++;
				sumy+=year(y);
		  		
		  	}
		
		}
		else if (m<=2)
		{
	  		for(int j=0;j<2017-y;j++)
	  		{
	  			sumy+=year(y);
	  			y++;
			}
		}
	/*	else if (m==2)
		{
			if (d<=28)
			{ 
				for(int j=0;j<2017-y;j++)
		  		{
		  			sumy+=year(y);
		  			y++;
				}
			} 
			else
			{
				for(int j=0;j<2017-y;j++)
			  	{
					y++;
					sumy+=year(y);
			  		
			  	}
			}
		}	
		*/	
		summ=month(m);
		sumd=day(d);
		sum=sumy+summ+sumd;
		
		printf("%d\n",sum);
	}
	
	return 0;
	
  }
  
