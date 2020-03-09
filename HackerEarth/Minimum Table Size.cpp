#include<bits/stdc++.h>
using namespace std;

long long int power(long long int x, long long int y) 
{ 
    long long int res = 1;  
  
    while (y > 0ll) { 
        if (y & 1ll) 
            res = res * x; 
  
        y = y >> 1ll; 
        x = x * x;  
    } 
    return res; 
} 

long long int get_power(long long int num , long long int P ,long long int x)
{
    bool rem = num%power(P,x);
    num = num / power(P,x);
    
    while(num>1)
    {
        num = num/P;
        x++;
        if(num%P!=0)
            rem=true;
    }
    if(rem)
        x++;
    return x;
}

int main()
{
   long long int N , P;
    cin>>N>>P;
    long long int arr[N];
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr,arr+N);
    long long int cost=0 ,x=1;
    for(int i=0;i<N;i++)
    {
        if(arr[i]<=power(P,x))
        {
            cost+=power(P,x);
            //cout<<x<<endl;
        }
        else
        {
            x= get_power(arr[i],P,x);
            //cout<<x<<endl;
            cost+=power(P,x);
        }
    }
    cout<<cost;
    return 0;
}