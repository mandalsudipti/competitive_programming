#include<bits/stdc++.h>
using namespace std;

const int range = 1e7+5;
int is_prime[range];
vector<long long int>multiple(range,0);
vector<long long int>freq(range,0);

void find_prime()
{
    for(int i=2;i<range;i++)
    {
        multiple[i] = multiple[i-1] ;
        if(is_prime[i])
        {
            multiple[i]+= freq[i] ;
            for(int j=2*i;j<range;j+=i)
            {
                is_prime[j] = false ;
                multiple[i]+=freq[j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int val; 
        cin>>val;
        freq[val]++;
    }
    memset(is_prime,1,sizeof(is_prime));
    find_prime();
    
    int query;
    cin>>query;
    
    while(query--)
    {
        int left , right ;
        cin>>left>>right ;
        left = min(left,range-1);
        right = min(right,range-1);
        long long int ans = multiple[right] - multiple[left-1] ;
        cout<<ans<<"\n";
    }
    
    return 0;
        
}





