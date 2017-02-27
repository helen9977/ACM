#include <cstdio>
int a[100010]={0};
int main(){
    int n;
    scanf("%d",&n);
    n++;
    int jj;
    for(int i=2;i<=n;i++){
        if(a[i]==0){
            a[i]=1;
            jj=n/i;
            for(int j=2;j<=jj;j++){
                if(a[]==0){
                    a[i*j]=2;
                }
            }
        }
    }
    printf("%d\n",n>3?2:1);
    for(int i=2;i<=n;i++){
        printf("%d ",a[i]);
    }
    scanf("%d",&n);
    return 0;
}
