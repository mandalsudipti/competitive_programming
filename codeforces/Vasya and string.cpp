#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k ;
    cin>>n>>k;
    string S;
    cin>>S;
    
    if(k==0)
    {
        int len = 1 ,  start = 0 ,  end = 0 ;
        for(int i=1;i<n;i++)
        {
            if(S[i]==S[start])
                end++;
            if(S[i]!=S[start] || i==n-1)
            {
                len = max(len , end-start+1);
                start = end = i ;
            }
        }
        cout<<len;
        return 0;
    }
    
    vector<int>len_a(n,0);
    vector<int>k_a(n,n+10);
    vector<int>len_b(n,0);
    vector<int>k_b(n,n+10);
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            len_a[i] = len_b[i] = 1 ;
            if(S[i]=='a')
            {
                k_a[i] = 0 ;
                k_b[i] = 1;
            }
            else{
                k_b[i] = 0 ;
                k_a[i] = 1 ;
            }
            continue;
        }
        
        if(S[i]=='a')
        {
            k_a[i] = k_a[i-1];
            k_b[i] = k_b[i-1]+1;
        }
        else
        {
            k_b[i] = k_b[i-1];
            k_a[i] = k_a[i-1]+1;
        }
        
        if(k_a[i]>k)
        {
            int idx = lower_bound(k_a.begin(),k_a.end(),k_a[i]-k) - k_a.begin() ;
            if(idx>=0 && idx<k_a.size())
                len_a[i]= i -idx ;
        }
        else
        {
            len_a[i] = len_a[i-1]+1;
        }
        if(k_b[i]>k)
        {
            int idx = lower_bound(k_b.begin(),k_b.end(),k_b[i]-k) - k_b.begin() ;
            if(idx>=0 && idx<k_b.size())
                len_b[i] = i - idx ;
        }
        else
        {
            len_b[i] = len_b[i-1] + 1 ;
        }
        
    }
    
    int max_len = 0 ;
    for(int i=0;i<n;i++)
        max_len = max(max_len , max(len_a[i],len_b[i]));
        
    cout<<max_len<<endl;
    
    return 0 ;
    
}







