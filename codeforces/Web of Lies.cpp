#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int nodes , edges ;
    cin>>nodes>>edges ;
    
    int u , v , vulnerable = 0;
    vector<int>greater_node(nodes + 1 , 0);
    
    for(int i = 0 ; i < edges ; i++)
    {
        cin>>u>>v ;
        if(u > v)
            greater_node[v]++ ;
        else
            greater_node[u]++ ;
    }
    
    for(int i = 1 ; i <= nodes ; i++)
    {
        if(greater_node[i] > 0)
            vulnerable++ ;
    }
    
    int T ;
    cin>>T;
    
    while(T--)
    {
        int op_type , node1 , node2 ;
        cin>>op_type ;
        
        if(op_type == 1)
        {
            cin>>node1>>node2 ;
            if(node1 < node2)
            {
                greater_node[node1]++ ;
                if(greater_node[node1] == 1)
                    vulnerable++;
            }
            else
            {
                greater_node[node2]++ ;
                if(greater_node[node2] == 1)
                    vulnerable++;
            }
        }
        else if(op_type == 2)
        {
            cin>>node1>>node2 ;
            if(node1 < node2)
            {
                greater_node[node1]--;
                if(greater_node[node1] == 0)
                    vulnerable--;
            }
            else
            {
                greater_node[node2]-- ;
                if(greater_node[node2] == 0)
                    vulnerable--;
            }
        }
        else
        {
            cout<<(nodes -  vulnerable)<<endl;
        }
    }
    
    return 0 ;
}