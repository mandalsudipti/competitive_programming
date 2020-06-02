#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , cnt=0;
    string S;
    cin>>n>>S;
    
    map<char,int>color;
    color['R']=0;
    color['G']=1;
    color['B']=2;
    
    char arr[]={'R','G','B'};
    
    for(int i=1;i<n;i++)
    {
        if(S[i]==S[i-1])
        {
            int idx;
            cnt++;
            if(i+1<n && S[i+1]!=S[i-1])
                idx = (3 - color[S[i-1]] - color[S[i+1]]);
            else
                idx = (color[S[i-1]]+1)%3;
            S[i]=arr[idx];
        }
    }
    cout<<cnt<<endl;
    cout<<S;
    
    return 0;
}