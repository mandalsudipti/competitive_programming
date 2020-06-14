#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin>>S;
    int n= S.length();
    vector<int>freq_a(n,0);
    vector<int>freq_b(n,0);
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='a')
        {
            freq_a[i]=1;
            if(i-1>=0)
            {
                freq_a[i]+=freq_a[i-1];
                freq_b[i]=freq_b[i-1];
            }
        }
        else
        {
            freq_b[i]=1;
            if(i-1>=0)
            {
                freq_b[i]+=freq_b[i-1];
                freq_a[i]=freq_a[i-1];
            }
        }
    }
    int max_length = max(freq_a[n-1],freq_b[n-1]);
    for(int i=0;i<n;i++)
    {
        int right_a = freq_a[n-1]- freq_a[i];
        
        for(int j=i;j>=0;j--)
        {
            int a , b ;
            if(j==0)
            {
                b = freq_b[i];
                a = freq_a[i];
                if(b>a)
                    max_length = max(max_length , right_a + b);
            }
            else
            {
                b = freq_b[i] - freq_b[j-1] ;
                a = freq_a[i] - freq_a[j-1] ;
                if(b>a)
                    max_length = max(max_length , freq_a[j-1]+b+right_a);
            }
        }
    }
    cout<<max_length<<endl;
    
    return 0;
}

