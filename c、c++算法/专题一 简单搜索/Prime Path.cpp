#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int a,b,N,book[10000];

struct node
{
    int v;
    int k;
};


bool isPrime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;

    for(int i = 2; i*i <= n; i ++)
        if(n%i == 0) return false;

    return true;
}

void BFS()
{   
    memset(book,0,sizeof(book));
    node c,d;
    c.v=a;
    c.k=0;
    queue<node>q; 
    q.push(c);
    while(!q.empty())
    {
        c=q.front();
        q.pop();
        if(c.v==b)
            {
                printf("%d\n",c.k);
                return ;
            }


        for(int i=1;i<=9;i++)//千位
        {
            int temp;
            temp=c.v%1000+i*1000;
            if(temp!=c.v && book[temp]==0 && isPrime(temp))
            {   
                d.v=temp;
                d.k=c.k+1;
                book[temp]=1;
                q.push(d);              
            }
        }

        for(int i=0;i<=9;i++)//百位
        {
            int temp;
            temp=(c.v/1000)*1000+i*100+(c.v%100/10)*10+c.v%10;
            if(temp!=c.v &&book[temp]==0 && isPrime(temp))
            {
                d.v=temp;
                d.k=c.k+1;
                book[temp]=1;
                q.push(d);
            }
        }
      
       
          for (int i=0;i<=9;i++)//十位
        {
            int temp;
            temp=(c.v/100)*100+i*10+c.v%10;
            if(temp!=c.v &&book[temp]==0 && isPrime(temp))
            {
                d.v=temp;
                d.k=c.k+1;
                book[temp]=1;
                q.push(d);
            }
        }
         
       

        for(int i=0;i<=9;i++)//个位
        {
            int temp;
            temp=(c.v/10)*10+i;
            if(temp!=c.v && book[temp]==0 && isPrime(temp))
            {   
                d.v=temp;
                d.k=c.k+1;
                book[temp]=1;
                q.push(d);              
            }
        }

      

     }
    printf("Impossible\n");
    return ;

}


int main ()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
             scanf("%d%d",&a,&b);
             if(a==b)
                printf("0\n");
            else
                BFS();
    }
    return 0;
}