#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
    cin>>n;
    vector<int>arr(n+1);
    vector<int>pos(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pos[arr[i]] = i ;
    }
    
    vector<char>winner(n+1,'*');
    
    
    for(int i=n;i>=1;i--)
    {
        int p = pos[i]  ;
        bool found = false;
        for(int j=p+i;j<=n;j+=i)
        {
            if(winner[j]=='B')
            {
                found = true ;
                break;
            }
        }
        
        for(int j=p-i;j>=1;j-=i)
        {
            if(winner[j]=='B')
            {
                found = true;
                break;
            }
        }
        
        if(found)
            winner[p] = 'A';
        else
            winner[p] = 'B';
    }
    
    for(int i=1;i<=n;i++)
        cout<<winner[i];
        
    return 0;
}
