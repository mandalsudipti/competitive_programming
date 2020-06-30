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
        string S;
        cin>>S;
        int cnt = 0 , val = 0 ;
        for(int i=0;i<n;i++)
        {
            S[i]=='(' ? val++ : val--;
            if(val<0)
            {
                cnt++;
                val=0;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}