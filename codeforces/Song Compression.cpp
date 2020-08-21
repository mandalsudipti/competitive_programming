#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n , m ;
    cin>>n>>m;
    vector<int>song_size(n);
    vector<int>compressed_size(n);
    
    long long int total_size = 0 ;
    for(int i=0;i<n;i++)
    {
        cin>>song_size[i]>>compressed_size[i];
        compressed_size[i] = song_size[i] - compressed_size[i] ;
        total_size+=song_size[i];
    }
    
    sort(compressed_size.begin(),compressed_size.end(),greater<long long int>());
    
    int cnt = 0 ;
    for(int i=0;i<n;i++)
    {
        if(total_size<=m)
            break;
        else
        {
            total_size-=compressed_size[i];
            cnt++;
        }
    }
    
    if(total_size<=m)
        cout<<cnt;
    else
        cout<<"-1";
        
    return 0;
}