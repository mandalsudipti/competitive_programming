#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , query;
    cin>>n>>query;
    int val,row[n+1],col[n+1];
    vector<int>even_row;
    vector<int>odd_row;
    vector<int>even_col;
    vector<int>odd_col;
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        row[i]=val%2;
        val%2==0?even_row.push_back(i):odd_row.push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>val;
        col[i]=val%2;
        val%2==0?even_col.push_back(i):odd_col.push_back(i);
    }
    while(query--)
    {
        int r1 , c1 , r2 , c2 ;
        cin>>r1>>c1>>r2>>c2;
        int s=min(r1,r2) , t=max(r1,r2) ;
        r1=s;
        r2=t;
        s=min(c1,c2);
        t=max(c1,c2);
        c1=s;
        c2=t;
        bool possible=true;
        if(row[r1]!=row[r2])
            possible=false;
        else
        {
            if(row[r1]==0)
            {
                int x = upper_bound(odd_row.begin(),odd_row.end(),r1) - odd_row.begin();
                if(x<odd_row.size() && odd_row[x]<=r2)
                    possible=false;
                int y = upper_bound(odd_col.begin(),odd_col.end(),c1) - odd_col.begin();
                if(y<odd_col.size() && odd_col[y]<=c2)
                    possible=false;
            }
            else
            {
                int x = upper_bound(even_row.begin(),even_row.end(),r1) - even_row.begin();
                if(x<even_row.size() && even_row[x]<=r2)
                    possible=false;
                int y = upper_bound(even_col.begin(),even_col.end(),c1) - even_col.begin();
                if(y<even_col.size() && even_col[y]<=c2)
                    possible=false;
            }
        }
        if(possible)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}


