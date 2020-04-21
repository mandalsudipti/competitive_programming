#include<bits/stdc++.h>
using namespace std;

const int size=150005;
int main()
{
    int n ;
    cin>>n;
    int val;
    vector<int>freq(size,0);
    for(int i=0;i<n;i++)
    {
        cin>>val;
        freq[val]++;
    }
    int team_size=0;
    for(int i=1;i<size;i++)
    {
        if(freq[i]>=1 && i>1 && freq[i-1]==0)
        {
            freq[i-1]++;
            freq[i]--;
        }
        if(freq[i]>=2)
        {
            freq[i+1]++;
            freq[i]--;
        }
    }
    for(int i=1;i<size;i++)
    {
        if(freq[i]!=0)
        {
            team_size++;
            //cout<<i;
        }
    }
    cout<<team_size;
    return  0;
}


