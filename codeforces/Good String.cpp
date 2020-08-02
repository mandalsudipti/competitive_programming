#include<bits/stdc++.h>
using namespace std;
string S;

int get_len(int a , int b , string S)
{
    int idx = 0 , cnt = 0;
    for(int i=0;i<S.length();i++)
    {
        if(idx==0 && S[i]==a+48)
        {
            cnt++;
            idx=1;
        }
        else if(idx==1 && S[i]==b+48)
        {
            cnt++;
            idx=0;
        }
    }
    //cout<<a<<" "<<b<<" "<<cnt<<endl;
    if(cnt%2==1)
        cnt--;
        
    return cnt;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>S;
        vector<int>freq(10,0);
        for(int i=0;i<S.length();i++)
            freq[S[i]-48]++;
            
        int max_len = 0;
        for(int i=0;i<10;i++)
            max_len = max(max_len,freq[i]);
            
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(i==j)
                    continue;
                int x = get_len(i,j,S);
                max_len = max(max_len , x);
            }
        }
        cout<<S.length()- max_len<<endl;
    }
    return 0;
}
