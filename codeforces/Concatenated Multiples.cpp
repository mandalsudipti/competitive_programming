#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n , k;
    cin>>n>>k;
    
    vector<long long int>arr(n) ;
    vector<int>rem(n);
    map<long long int,long long int>len[12] ;
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        rem[i]=arr[i]%k;
        int idx = floor(log10(arr[i])+1);
        len[idx][rem[i]]++;
    }
    
    long long int cnt = 0 ;
    for(int i=0;i<n;i++)
    {
        long long int tmp = arr[i] ;
        int idx = floor(log10(arr[i])+1);
        len[idx][rem[i]]--;
        for(int j=1;j<12;j++)
        {
            tmp = (tmp*10)%k ;
            if(len[j].size()==0)
                continue;
            long long int x = tmp;
        
            if(x!=0)
                x = k - x;
            cnt+=len[j][x] ;
        }
        len[idx][rem[i]]++;
    }
    
    cout<<cnt;
    
    return 0;
}





