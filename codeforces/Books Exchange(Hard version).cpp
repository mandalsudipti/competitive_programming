#include<bits/stdc++.h>
using namespace std;

int main()
{
    int query;
    cin>>query;
    while(query--)
    {
        int n ,val ,i , key=1;
        cin>>n;
        int ans[n+1];
        map<int,int> path;
        for(i=1;i<=n;i++)
        {
            cin>>val;
            path[i]=val;
        }
        while(path.size()!=0)
        {
            vector<int> element ;
            int tmp,x, key=path.begin()->first;
            x=key;
            while(path[key]!= x)
            {
                element.push_back(key);
                tmp=key;
                key = path[key];
                path.erase(tmp);
            }
            if(path[key]==x)
            {
                element.push_back(key);
                path.erase(key);
            }
            for(i=0;i<element.size();i++)
            {
                ans[element[i]]=element.size();
            }
        }
        
        for(i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
