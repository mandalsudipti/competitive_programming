#include<bits/stdc++.h>
using namespace std;

bool sort_by_sec(const pair<long long int, long long int>&a , const pair<long long int , long long int>&b )
{
    return a.second > b.second ;
}

int main()
{
    int no_of_song , choose ;
    cin>>no_of_song>>choose;
    
    vector<pair<long long int,long long int>>song(no_of_song);
    long long int length , beauty;
    
    for(int i=0;i<no_of_song;i++)
    {
       cin>>length>>beauty;
       song[i] = make_pair(length,beauty);
    }
    
    sort(song.begin(),song.end(),sort_by_sec);
    priority_queue<long long int>Q;
    Q.push((-1)*song[0].first);
    long long int prefix_sum = song[0].first ;
    
    for(int i=1;i<no_of_song;i++)
    {
        if(Q.size()==choose)
        {
            prefix_sum+=Q.top();
            Q.pop();
        }
        Q.push((-1)*song[i].first);
        song[i].first+=prefix_sum;
        prefix_sum=song[i].first;
    }
    
    long long int max_sum = 0 ;
    for(int i=0;i<no_of_song;i++)
    {
        max_sum = max(max_sum , song[i].first*song[i].second);
    }
    cout<<max_sum<<endl;
    return 0;
}
