#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int mod=1e9+7;
    int T , k ,i;
    cin>>T>>k;
   long long int arr[100001] , total[100001];
   for(i=1;i<=100000;i++)
   {
        if(i<k)
            arr[i]=1;
        else if(i==k)
            arr[i]=2;
        else
            arr[i]=(arr[i-1]+arr[i-k])%mod;
   }
   
   total[1]=arr[1];
   for(i=2;i<=100000;i++)
        total[i]=(total[i-1]+arr[i])%mod;
        
   while(T--)
   {
       long long int left , right , ways=0;
       cin>>left>>right;
       if(left>1)
            cout<<(total[right]-total[left-1]+mod)%mod<<endl;
        else
            cout<<total[right]<<endl;
   }
   return 0;
}
