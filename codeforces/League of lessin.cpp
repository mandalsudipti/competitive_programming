#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>freq(n+1);
    vector<vector<int>>triple(n-2,vector<int>(3,0));
    for(int i=0;i<n-2;i++)
    {
        cin>>triple[i][0]>>triple[i][1]>>triple[i][2];
        freq[triple[i][0]].push_back(i);
        freq[triple[i][1]].push_back(i);
        freq[triple[i][2]].push_back(i);
    }
    vector<int>permutation(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(freq[i].size()==1)
        {
            int idx;
            permutation[1]==0?idx=1:idx=n;
            permutation[idx]=i;
            int pair  = freq[i][0];
            int x , y ;
            x = triple[pair][0]==i?triple[pair][1]:triple[pair][0];
            y = triple[pair][0] + triple[pair][1] + triple[pair][2] - x - i ;
            if(idx==1)
            {
                freq[x].size()==2?permutation[2]=x: permutation[2]=y;
                permutation[3]=(x+y)- permutation[2];
            }
            else
            {
                freq[x].size()==2?permutation[n-1]=x:permutation[n-1]=y;
                permutation[n-2]=(x+y)- permutation[n-1];
            }
            for(int j=0;j<3;j++)
            {
                int num =  triple[pair][j];
                for(int k=0;k<freq[num].size();k++)
                {
                    if(freq[num][k]==pair)
                        freq[num][k]=-1;
                }
            }
        }
    }
    for(int i=2;i<=n-3;i++)
    {
        int num = permutation[i];
        for(int j=0;j<freq[num].size();j++)
        {
            int my_triple = freq[num][j];
            if(my_triple!=-1 && (triple[my_triple][0]==permutation[i+1]||triple[my_triple][1]==permutation[i+1]||triple[my_triple][2]==permutation[i+1]))
            {
                permutation[i+2]=triple[my_triple][0]+triple[my_triple][1]+triple[my_triple][2]-permutation[i]-permutation[i+1];
                for(int k=0;k<3;k++)
                {
                    int x = triple[my_triple][k];
                    for(int l=0;l<freq[x].size();l++)
                    {
                        if(freq[x][l]==my_triple)
                            freq[x][l]=-1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<permutation[i]<<" ";
        
    return 0;
}