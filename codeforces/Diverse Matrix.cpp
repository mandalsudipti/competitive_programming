#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r , c;
    cin>>r>>c;
    if(r==1 && c==1)
    {
        cout<<"0";
        return 0;
    }
    vector<int>column;
    vector<int>row;
    if(r==1)
    {
        row.push_back(1);
        for(int i=2;i<=c+1;i++)
            column.push_back(i);
    }
    else 
    {
        for(int i=1;i<=c;i++)
            column.push_back(i);
        for(int i=c+1;i<=r+c;i++)
            row.push_back(i);
    }
    for(int i=0;i<r;i++)
    {
       for(int j=0;j<c;j++)
        cout<<row[i]*column[j]<<" ";
       cout<<endl;
    }
    return 0;
}
