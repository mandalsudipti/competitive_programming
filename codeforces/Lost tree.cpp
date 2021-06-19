#include<bits/stdc++.h>
using namespace std;

void get_edge(vector<int>& nodes , set<vector<int>>& edge , int n)
{
    int distance ;
    for(int i = 0 ; i < nodes.size() ; i++)
    {
        cout<<"? "<<nodes[i]<<endl;
        fflush(stdout);
        for(int j = 1 ; j <= n ; j++)
        {
            cin>>distance ;
            if(distance == 1)
                edge.insert({ min(nodes[i],j) , max(nodes[i],j) });
        }
        fflush(stdout);
    }
    
}

int main()
{
    int node ;
    cin>>node;

    cout<<"? "<<"1"<<endl;
    fflush(stdout);

    vector<int>distance(node+1) , even , odd;
    set<vector<int>>edge ;

    for(int i = 1 ; i <= node ; i++)
    {
        cin>>distance[i] ;
        if(i == 1)
            continue;
        if(distance[i]%2)
            odd.push_back(i);
        else
            even.push_back(i);
        if(distance[i] == 1)
            edge.insert({1,i});
    }

    if(even.size() <= odd.size())
        get_edge(even , edge , node);
    else
        get_edge(odd , edge , node);

    cout<<"!"<<endl;
    for(vector<int>arr : edge)
        cout<<arr[0]<<" "<<arr[1]<<endl;

    fflush(stdout);
    return 0 ;
}