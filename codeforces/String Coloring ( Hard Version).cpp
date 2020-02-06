#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , letter[26];
    string S;
    cin>>n>>S;
    int i,color[n]={0};
    for(i=0;i<26;i++)
        letter[i]=-1;
    for(i=0;i<S.length();i++)
    {
        int idx=S[i]-'a';
        if(idx<25)
        {
            for(int j=idx+1;j<26;j++)
            {
                if(letter[j]>=0 && letter[j]<i)
                {
                    color[i]=max(color[i],color[letter[j]]+1);
                }
            }
        }
        else
            color[i]=1;
        if(color[i]==0)
            color[i]=1;
        letter[idx]=i;
    }
    int max_color=color[0] ;
    for(i=1;i<n;i++)
    {
        if(color[i]>max_color)
            max_color=color[i];
    }
    cout<<max_color<<endl;
    for(i=0;i<n;i++)
        cout<<color[i]<<" ";
    return 0;
}
