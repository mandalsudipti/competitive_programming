#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m;
    cin>>n>>m;
    vector<bool>available(n,true);
    vector<int> idx ;
    vector<string> str(n);
    int i , j , cnt=0;
    for(i=0;i<n;i++)
        cin>>str[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(available[i]==true && available[j]==true)
            {
                string tmp = str[j];
                reverse(tmp.begin(),tmp.end());
                if(str[i]== tmp )
                {
                    idx.insert(idx.begin()+cnt,i);
                    idx.insert(idx.begin()+cnt+1,j);
                    available[j]= false ;
                    available[i]=false;
                    cnt++;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(available[i]==true)
        {
            string tmp = str[i];
            reverse(tmp.begin(),tmp.end());
            if(str[i]==tmp)
            {
                idx.insert(idx.begin()+cnt,i);
                break;
            }
        }
    }
    string ans="";
    for(i=0;i<idx.size();i++)
        ans=ans+str[idx[i]];
    cout<<ans.length()<<endl;
    cout<<ans;
    
    return 0;
}
