#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x;
        cin>>n>>x;
        int  val ;
        set<int>arr;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            arr.insert(val);
        }
        auto i = arr.begin();
        if(x<(*i)-1)
        {
            cout<<x<<endl;
        }
        else
        {
            x=x-(*i)+1;
            //cout<<x<<endl;
            int ans = (*i);
            int pre = (*i);
            for(auto itr=arr.begin();itr!=arr.end();++itr)
            {
                if(*itr==pre+1)
                {
                     ans=(*itr);
                     pre=(*itr);
                }
                else if (*itr>pre+1)
                {
                    if(x==0)
                        break;
                    else if(x<(*itr-pre-1))
                    {
                        //cout<<*itr<<" "<<pre<<"second\n";
                        ans+=x;
                        pre=(*itr);
                        x=0;
                        break;
                        //cout<<x<<endl;
                    }
                    else 
                    {
                        //cout<<"third\n";
                        ans=(*itr);
                        x=x-(*itr-pre-1);
                        pre=(*itr);
                        //cout<<x<<endl;
                    }
                }
            }
            ans+=x;
            cout<<ans<<endl;
        }
    }
    return 0;
}