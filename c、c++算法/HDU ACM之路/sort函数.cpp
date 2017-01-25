#include <iostream>
#include <algorithm>
using namespace std;
int cow[1000000];


int main()
{
    int n = 0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>cow[i];
    }

   sort(cow,cow+n);

    cout<<cow[n/2];
    return 0;
}