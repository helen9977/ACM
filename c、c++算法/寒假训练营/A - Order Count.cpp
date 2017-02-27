#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//用于转置字符串
 
void Reverse(char* a)
{
int size1=strlen(a)-1;
int size2=(size1+1)/2;
char temp;
for (int i=0;i<size2;i++)
{
temp=a[i];
a[i]=a[size1-i];
a[size1-i]=temp;
}
return;
} 

char* Add(char* a,char* b)  
{  
    int maxlen = max(strlen(a),strlen(b));  
    //多申请两个字符，一个是结束符'\0'，一个是放到第一个字符，当两个数最高位相加后，如果有进位，保存到这里  
    char* p = new char[maxlen+2];   
    //声明两个指针分别指向a和b的末尾，不包含结束符  
    char* pA=a+strlen(a)-1;  
    char* pB=b+strlen(b)-1;  
    int m=0;  
    int n=0;  
    //进位  
    int c=0; 
    int i=0;
    for (i=0;i<maxlen;i++)  
    {  
        m = n = 0;  
        //因为当pA到达第一个字符时，即pA=a时，也要进行计算，所以这里用(pA-1)来判断  
        //因为字符'0'的Asic是48，所以1就是49，要转成数字，就要减去48  
        if ((pA+1) != a)  
        {  
            m = *pA - 48;  
            pA--;  
        }  
        if ((pB+1) != b)  
        {  
            n = *pB - 48;  
            pB--;  
        }  
        //为p指针的第i个字符赋值  
        *(p+i) = (m+n+c) % 10 + 48;
        //取得进位  
        c = (m+n+c) / 10;  
    }
//判断最后一位是否有进位
if (c>0)
{
*(p+i) = 48 + c;
*(p+i+1) = '\0';
}
else
*(p+i) = '\0';
//转置字符串
Reverse(p);
    return p;  
}

char* Mult(char* a,char* b)
{
int sizea =strlen(a);
int sizeb =strlen(b);
char* p = new char[sizea+sizeb+1]; 
//两数相乘所得的积的位数最大为两个数位数只和，多申请一位放'\0'
char* pA=a+sizea-1;  
        char* pB=b+sizeb-1;  
        int m=0;  
        int n=0;  
        //进位  
        int c=0;
//存放该位置原有的数
int s=0;
//记数
int i=0;
int j=0;
//具体实现过程详见说明文件
for (i=0;i<sizea;i++)
{
        m = *(pA-i) - 48;  
c=0;
for (j=0;j<sizeb;j++)
{
n = *(pB-j) - 48; 
//判断该位置原来是否为0
if((*(p+i+j)>='0')&&(*(p+i+j)<='9'))
s = *(p+i+j) - 48;
else
s = 0;
*(p+i+j) = (m*n+c+s) % 10 + 48;
c = (m*n+c+s) / 10; 
}
*(p+i+j) = 48 + c;
}
if (c>0) 
*(p+i+j) = '\0';
else
*(p+i+j-1) = '\0';
Reverse(p);
return p;
} 

char* jc(int num)
{
char* pt="1";
char* str="1"; 
//调用num次Mult()
for (int i=2;i<=num;i++)
{
str=Add(str,"1");
pt=Mult(pt,str);
}
return pt;
}


int main ()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        char sum=1;
        scanf("%d",&N);
        Add(sum,jc(N));
        char an=0;
        for(int i=1;i<N-1;i++)
        {
            an+=C(N,i)*jc(N-i);

        }
        sum+=an;
        if(N==1)
            printf("1\n");
        else
            printf("%I64d\n",sum);
    }
    return 0;
}
