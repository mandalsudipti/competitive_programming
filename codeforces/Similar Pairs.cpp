#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        cin>>n;
        int even = 0 , odd = 0 ;
        vector<int>even_freq(105,0);
        vector<int>odd_freq(105,0);
        int val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            if(val%2==0)
            {
                even++;
                even_freq[val]++;
            }
            else
            {
                odd++;
                odd_freq[val]++;
            }
        }
        bool possible = false ;
        if(even%2==0 && odd%2==0)
            possible=true;
        else if(even>odd)
        {
            for(int i=0;i<even_freq.size();i++)
            {
                if(even_freq[i]>0)
                {
                    int num = i ;
                    if((i-1)>=0 && (i+1)< odd_freq.size() && odd_freq[i-1]>0 || odd_freq[i+1]>0)
                    {
                        possible = true;
                        break;
                    }
                }
            }
        }
        else
        {
            for(int i=0;i<odd_freq.size();i++)
            {
                if(odd_freq[i]>0)
                {
                    int num = i ;
                    if((i-1)>=0 && (i+1)<even_freq.size() && even_freq[i-1]>0 || even_freq[i+1]> 0)
                    {
                        possible=true;
                        break;
                    }
                }
            }
        }
        if(possible)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}