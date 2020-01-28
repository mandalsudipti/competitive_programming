#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,i,diff=0,diff1=-1,diff2=-1;
        cin>>N;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        for(i=0;i<N;i++)
        {
            if(s1[i]!=s2[i])
            {
                diff++;
                if(diff1==-1)
                    diff1=i;
                else if(diff2==-1)
                    diff2=i;
            }
        }
        if(diff==0)
            cout<<"Yes"<<endl;
        else if(diff>2 || diff==1)
            cout<<"No"<<endl;
        else
        {
            if((s1[diff1]==s1[diff2])&&(s2[diff1]==s2[diff2]))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        
    }
    return 0;
}