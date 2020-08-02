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
        vector<int>num(n,9);
        for(int i=num.size()-1;i>=0;i--)
        {
            if(n>=4)
            {
                num[i] = 8 ;
                n-=4;
            }
            else if(n<4 && n>0)
            {
                num[i] = 8 ;
                n = 0 ;
            }
        }
        for(int i=0;i<num.size();i++)
            cout<<num[i];
        cout<<endl;
    }
    return 0;
}


