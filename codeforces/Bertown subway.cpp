#include<bits/stdc++.h>
using namespace std;

int main()
{
    int node;
    cin>>node;
    
    vector<int>arr(node+1);
    set<int>unvisited;
    for(int i=1;i<=node;i++)
    {
        cin>>arr[i];
        unvisited.insert(i);
    }
    
    vector<long long int>component;
    while(unvisited.size()>0)
    {
        long long int cnt = 1;
        int start = (*unvisited.begin());
        unvisited.erase(unvisited.begin());
        while(unvisited.find(arr[start])!=unvisited.end())
        {
            cnt++;
            unvisited.erase(unvisited.find(arr[start]));
            start = arr[start];
        }
        component.push_back(cnt);
    }
    
    sort(component.begin(),component.end(),greater<long long int>());
    
    long long int ans = 0 ;
    if(component.size()>=2)
    {
        ans = (component[0] + component[1])*(component[0] + component[1]);
        for(int i=2;i<component.size();i++)
            ans+=(component[i]*component[i]);
    }
    else
        ans = component[0]*component[0];
        
    cout<<ans<<endl;
    
    return 0;
}
