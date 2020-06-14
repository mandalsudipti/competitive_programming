#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , lemonade ;
    cin>>n>>lemonade;
    
    long long int arr[n] , cost = 0 , bit = -1 ;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    while(lemonade!=0)
    {
        bit++;
        if( lemonade & 1ll)
        {
            long long int tmp = 0 ;
            for(long long int i=min(n-1,bit);i>=0;i--)
            {
                long long int x = (arr[i]<<(bit-i)) ;
                if(x>=arr[i] && tmp == 0)
                    tmp = x ;
                else if(x>= arr[i])
                    tmp = min(tmp , x);
                if(tmp < 0 )
                    cout<<bit<<" "<<i<<endl;
            }
            long long int idx=-1 ;
            for(long long int i=bit+1;i<n;i++)
            {
                if(arr[i]<tmp+cost)
                {
                    idx = i ;
                    tmp = arr[i] - cost ;
                }
            }
            if(idx==-1)
            {
                lemonade = lemonade>>1ll;
                cost+=tmp;
            }
            else
            {
                lemonade = lemonade>>(idx-bit) ;
                bit = idx - 1 ;
                cost = arr[idx];
            }
        }
        else
            lemonade = lemonade>>1ll;
    }
    cout<<cost;
    
    return 0;
}