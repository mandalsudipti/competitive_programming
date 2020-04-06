#include<bits/stdc++.h>
using namespace std;

const int TOTAL_ALPHABET=26;

struct DSU
{
    int parent[TOTAL_ALPHABET];
    int component = TOTAL_ALPHABET;
    
    DSU(){}
    
    DSU(int n)
    {
        for(int i=0;i<n;i++)
            parent[i]=i;
    }
    
    int get_parent(int node)
    {
        while(parent[node]!=node)
            node=parent[parent[node]];
            
        return node;
    }
    
    void unite(int node1 , int node2)
    {
        node1 = get_parent(node1);
        node2 = get_parent(node2);
        
        if(parent[node1]==parent[node2])
            return;
        parent[node1]=parent[node2];
        component--;
    }
};


int main()
{
    int n;
    cin>>n;
    bool letter_used[26];
    memset(letter_used,false,sizeof(letter_used));
    struct DSU dsu(26);
    while(n--)
    {
        string S;
        cin>>S;
        vector<bool>cur_letter(26,false);
        for(int i=0;i<S.length();i++)
        {
            cur_letter[S[i]-'a']=true;
            letter_used[S[i]-'a']=true;
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(cur_letter[i]==true && cur_letter[j]==true && dsu.get_parent(i)!=dsu.get_parent(j))
                    dsu.unite(i,j);
            }
        }
    }
    int unused_letter=0;
    for(int i=0;i<26;i++)
    {
        if(letter_used[i]==false)
            unused_letter++;
    }
    cout<<dsu.component - unused_letter ;
    return 0;
}
