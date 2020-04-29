#include<bits/stdc++.h>
using namespace std;

const char RGB[3]={'R','G','B'};
void compare(string S , string K1 , string K2 , string K3 , vector<int>&cur)
{
    int k = K1.length() ;
    for(int i=0;i<k;i++)
    {
        if(S[i]!=K1[i])
            cur[0]++;
        if(S[i]!=K2[i])
            cur[1]++;
        if(S[i]!=K3[i])
            cur[2]++;
    }
}

void solve()
{
    int n , k;
    cin>>n>>k;
    string S;
    cin>>S;
    
    string K1="" , K2="" , K3="" ;
    int i1=-1 , i2 =0 , i3 =1;
    for(int i=0;i<k;i++)
    {
        K1+=RGB[(++i1)%3];
        K2+=RGB[(++i2)%3];
        K3+=RGB[(++i3)%3];
    }
    
    vector<vector<int>>change;
    for(int i=0;i+k-1<n;i++)
    {
        if(i==0)
        {
            vector<int>cur(3,0);
            compare(S,K1,K2,K3,cur);
            change.push_back(cur);
            continue;
        }
        vector<int>cur(3);
        int x = change.size()-1;
        cur[0]=change[x][2] - (S[i-1]!='B') + (S[i+k-1]!=K1[k-1]) ;
        cur[1] = change[x][0] - (S[i-1]!='R') + (S[i+k-1]!=K2[k-1]);
        cur[2] = change[x][1] - (S[i-1]!='G') + (S[i+k-1]!=K3[k-1]);
        change.push_back(cur);
    }
    int minimum = min(change[0][0], min(change[0][1],change[0][2]) );
    for(int i=1;i<change.size();i++)
    {
        int x = min(change[i][0], min(change[i][1],change[i][2]) );
        minimum = min(minimum,x);
    }
    cout<<minimum<<endl;
}

int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        solve();
    }
    return 0;
}