#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007 ;

long long int power(long long int x, long long int y) 
{ 
    long long int res = 1; // Initialize result 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x)%mod; 
  
        y = y >> 1;  
        x = (x * x)%mod; 
    } 
    return res%mod; 
} 
int main()
{
    int n , query ;
    cin>>n>>query;
    
    string S;
    cin>>S;
    vector<int>cnt_zero(n);
    vector<int>cnt_one(n);
    
    for(int i=0;i<n;i++)
    {
        if(i==0)
            S[i]=='0' ? cnt_zero[0]++ : cnt_one[0]++;
        else
        {
            cnt_one[i] = cnt_one[i-1] + (S[i]=='1') ;
            cnt_zero[i] = cnt_zero[i-1] + (S[i]=='0');
        }
        //cout<<cnt_zero[i]<<" "<<cnt_one[i]<<endl;
    }
    while(query--)
    {
        int l , r ;
        cin>>l>>r;
        l--;
        r--;
        long long int zero = cnt_zero[r] - (l>0 ? cnt_zero[l-1] : 0) ;
        long long int one = cnt_one[r] - (l>0 ? cnt_one[l-1] : 0) ;
        
        long long int ans = (power(2ll,one) - 1 )*power(2ll,zero);
        cout<<ans%mod<<endl;
    }
    
    return 0;
}
