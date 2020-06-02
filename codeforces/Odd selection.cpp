#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , x ;
        cin>>n>>x;
        int even  = 0 , odd = 0 ,val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            (val%2)==0?even++:odd++;
        }
        if(odd>=1)
        {
            odd --;
            x--;
            int cnt = (odd/2);
            if(x%2==0 && cnt>=x/2)
                cout<<"YES"<<endl;
            else
            {
                x-=min(x/2,cnt)*2;
                if(even>=x)
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
            }
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
