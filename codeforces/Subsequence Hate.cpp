#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        int cnt_zero_upto[S.length()] ;
        vector<int>partition(S.length()+1,0);
        for(int i=0;i<S.length();i++)
        {
            if(i==0)
            {
                S[i]=='0'?cnt_zero_upto[0]=1:cnt_zero_upto[0]=0;
                continue;
            }
            S[i]=='0'?cnt_zero_upto[i]=cnt_zero_upto[i-1]+1:cnt_zero_upto[i]=cnt_zero_upto[i-1];
        }
        for(int i=0;i<=S.length();i++)
        {
            int x = cnt_zero_upto[S.length()-1];
            if(i==0)
            {
                partition[0] = min(x,(int)S.length()-x);
                continue;
            }
            int left_zero = i - cnt_zero_upto[i-1] , left_one = cnt_zero_upto[i-1];
            int right_zero = (S.length()-i) - (x- cnt_zero_upto[i-1]) ;
            int right_one = x - cnt_zero_upto[i-1] ;
            
            partition[i] = min(left_one+right_zero , left_zero+right_one);
        }
        
        int min_change = S.length()+5;
        for(int i=0;i<partition.size();i++)
        {
            min_change = min(min_change , partition[i]);
        }
        cout<<min_change<<endl;
    }
    return 0;
}