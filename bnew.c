#include<stdio.h>
long long arr[1000001], num[1000001];
long long singleno[10];
int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);

    
    for(long long i=0;i<1000001;i++) arr[i]=1;

    for(long long i=2;i*i<=1000000;i++)
    {
        if(arr[i]==1)
        {
            for(long long j=i*i;j<=1000000;j+=i) arr[j]=0;
        }
    }

    long long len=b-a+1;
    
    for(long long i=0;i<len;i++) num[i]=1;
    
    for(long long i=2;i<=1000000;i++)
    {
        if(arr[i]==1)
        {
            for(long long j=((a-1)/i +1)*i ;j<=b;j+=i)
            {
                if(j != i)
                {
                    num[j - a]=0;
                }
            }
        }
    }

    for(long long i=0;i<len;i++)
    {
        if(num[i]==1) 
        {
            long long temp = a + i;
            while(temp)
            {
                singleno[temp % 10]++;
                temp /= 10;
            }
        }
    }
    

    long long max = 0;
    long long ans = 0;
    for(long long i=0;i<10;i++)
    {
        if(max<singleno[i])
        {
            max=singleno[i];
            ans=i;
        }
    }

    printf("%lld %lld",ans,max);
    
}