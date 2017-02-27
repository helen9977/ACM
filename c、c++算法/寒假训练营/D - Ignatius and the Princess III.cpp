#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int dp[121][121];
	int N;
	while(~scanf("%d",&N))
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<=N;i++)
			for(int j=1;j<=N;j++)
			{
				if(j>i)
					dp[i][j]=dp[i][i];
				else
					dp[i][j]=dp[i-j][j]+dp[i][j-1];
			}

		printf("%d\n",dp[N][N]);
	}
		return 0;
}