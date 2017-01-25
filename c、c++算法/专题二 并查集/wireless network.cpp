    #include <stdio.h>
    #include <math.h>
    #include <iostream>
    #include <string.h>

    using namespace std;
    int N,d;
    int f[1010];
    int path[1010][1010];
    int a,b;
    //int book[1010];
    struct node 
    {
    	int x,y;
    }co[1010];

  /*  int distance(int x1,int y1,int x2,int y2)
    {
        int d1,d2;
        d1=(x1-x2)*(x1-x2);
        d2=(y1-y2)*(y1-y2);
        int x=sqrt(d1+d2);
        return x;
    }应该是 DOUBLE = = 
    */

    int find(int x)
    {
    	if(f[x]==x)
    		return x;
    	else
    	{
    		f[x]=find(f[x]);
    		return f[x];
    	}
    }

    void Union(int x,int y)
    {
    	y=find(y);
    	f[y]=x;
        return ;
    }


    int main()
    {
        memset(f,0,sizeof(f));
        //memset(book,0,sizeof(book));
        memset(path,0,sizeof(path));
        string c;

        cin>>N>>d;
        for(int i=1;i<=N;i++)
        {
            cin>>co[i].x>>co[i].y;
        }
        for(int i=1;i<N;++i)
            for(int j=i+1;j<=N;++j)
                if(sqrt( (co[i].x-co[j].x) * (co[i].x-co[j].x) + (co[i].y-co[j].y) * (co[i].y-co[j].y) ) <= d)
                {
                    path[i][j]=1;
                    path[j][i]=1;
                }
    
        while(cin>>c)
        {
             if(  c=="O")
                {
                    cin>>a;
                    f[a]=a;
                    for(int i=1;i<=N;++i)
                    {
                        if(path[a][i] && f[i] )
                        Union(a,i);
                    }
                }
            else
                {
                    cin>>a>>b;
                    if( find(a) == find(b) )
                        cout<<"SUCCESS"<<endl;
                    else
                        cout<<"FAIL"<<endl;
                }
        }
        /*
        int i=1;
        while(gets(op))
        {
            int a,b;


            
            if(i==1)
            {
                switch(op[0])
                {
                    case '0':
                        a=op[1]-'0';
                    case 'S':
                        printf("FAIL\n");
                }
                i++;
            }
            else
            {
                switch(op[0])
                {
                    case '0':
                    {   b=op[1]-'0';
                        Union(a,b);
                        a=b;
                    }
                    case 'S':
                    {
                        if((distance( co[op[1]-'0'].x , co[op[1]-'0'].y, co[op[2]-'0'].x, co[op[2]-'0'].y))<= d)
                        {
                            cout<<"SUCCESS"<<endl;
                        }
                        else
                        {  
                            if(find(op[1]-'0')==find(op[2]-'0'))
                            {
                                int n,m;
                                n=d+sqrt((co[op[1]-'0'].x)*(co[op[1]-'0'].x) + (co[op[1]-'0'].y)*(co[op[1]-'0'].y) );
                                m=d+sqrt((co[op[2]-'0'].x)*(co[op[2]-'0'].x) + (co[op[2]-'0'].y)*(co[op[2]-'0'].y) );
                                if(find(n)==find(m)&&distance(n,0,m,0)<=d)
                                    cout<<"SUCCESS"<<endl;
                                else cout<<"FAIL"<<endl;
                            }
                            else
                                cout<<"FAIL"<<endl;
                        }
                    }

                }
         
            }
            
        }
        */

        return 0;
    }