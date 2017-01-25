#include <cstdio>
#include <cstring>
#include <iostream>
#define maxv 10
using namespace std;
int a[maxv][maxv];
int book[maxv][maxv];
int main ()
{
    memset(book,0,sizeof(book));
    int n;
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    i=-1;j=0;
    int num=n*n;
    while(num--)
    {
        while(i+1<n&&!book[i+1][j])
        {   
            i++;
            cout<<a[i][j]<<endl;
            book[i][j]=1;
        }
        
        while(j+1<n&&!book[i][j+1])
        {
            j++;
            cout<<a[i][j]<<endl; 
            book[i][j]=1;
           
        }
        while(i-1>=0&&!book[i-1][j])
        {
            i--;
            cout<<a[i][j]<<endl;
            book[i][j]=1;
            
        }
        while(j-1>=0&&!book[i][j-1])
        {
            j--;
            cout <<a[i][j]<<endl;
            book[i][j]=1;
           
         
        }

    }
    return 0;
}

