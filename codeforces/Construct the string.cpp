#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int len , sub_len , letter ;
        cin>>len>>sub_len>>letter;
        int idx=0;
        for(int i=0;i<len;i++)
        {
            idx=idx%letter;
            char ch='a'+idx ;
            cout<<ch;
            idx++;
        }
        cout<<endl;
    }
}