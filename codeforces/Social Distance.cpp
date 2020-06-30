#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , k , i=0 , cnt=0;
        cin>>n>>k;
        int last_one = -(k+1) ;
        string S;
        cin>>S;
        while(i<n)
        {
            if(S[i]=='0' && last_one+k+1<=i)
            {
                bool possible = true;
                for(int j=i+1;j<min(n,i+k+1);j++)
                {
                    if(S[j]=='1')
                    {
                        possible=false;
                        last_one=j;
                    }
                }
                if(possible)
                {
                    cnt++;
                    last_one=i;
                }
                i=last_one+k+1;
            }
            else if(S[i]=='1')
            {
                last_one=i;
                i=(i+k+1);
            }
            
        }
        cout<<cnt<<endl;
    }
    return 0;
}