#include<bits/stdc++.h>
using namespace std;

void factorization(vector<int>&factor , int k)
{
    for(int i=1;i<=sqrt(k);i++)
    {
        if(k%i==0)
        {
            if(k/i==i)
                factor.push_back(i);
            else
            {
                factor.push_back(i);
                factor.push_back(k/i);
            }
        }
    }
}

int get_length(vector<int>&freq , int base_length)
{
   int x = 1 , cnt = 0 ;
   bool possible = true;
   while(possible)
   {
       cnt = 0 ;
       for(int i=0;i<26;i++)
            cnt+=freq[i]/x;
            
        if(cnt>=base_length) 
            x++;
        else
            possible = false ;
   }
   x--;
   return base_length*x ;
}

void solve()
{
    int n , k ;
    cin>>n>>k;
    vector<int>factor;
    factorization(factor,k);
    
    string S;
    cin>>S;
    vector<int>freq(26,0);
    for(int i=0;i<n;i++)
        freq[S[i]-'a']++;
    int max_length = freq[0];
    for(int i=1;i<26;i++)
        max_length = max(max_length ,freq[i]) ;
    for(int i=0;i<factor.size();i++)
    {
        max_length = max(max_length , get_length(freq , factor[i]));
    }
    cout<<max_length<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}