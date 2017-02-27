#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>


using namespace std;

int boy[100005], girl[100005];
int v1[100005], v2[100005];

int main(){
	int t, n, m, k, x, y;
	long long sum;
	scanf ("%d", &t);
	while (t --){
		sum = 0;
		memset(boy, 0, sizeof(boy));
		memset(girl, 0, sizeof(girl));
		memset(v1, 0, sizeof(v1));
		memset(v2, 0, sizeof(v2));
		scanf ("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= k; i ++){
			scanf ("%d%d", &x, &y);
			boy[i] = x;
			girl[i] = y;
			v1[x] ++;
			v2[y] ++;
		}
		for (int i = 1; i <= k; i ++){
			sum += (v1[boy[i]] - 1) * (v2[girl[i]] - 1);
		}
		sum *= 2;
		printf ("%I64d\n", sum);
	}
	return 0;
}