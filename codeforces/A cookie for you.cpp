#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int v , c , grp1 , grp2 ;
        cin>>v>>c>>grp1>>grp2;
        if(v<c)
        {
            long long int tmp = v ;
            v = c ;
            c = tmp;
        }
        if(v==c)
        {
            if(grp1==0 || grp2==0)
            {
                if(grp1==0 && grp2<=v)
                    cout<<"YES"<<endl;
                else if(grp2==0 && grp1<=(v+c))
                    cout<<"YES"<<endl;
                else
                    cout<<"NO"<<endl;
                continue;
            }
            else
            {
                grp2--;
                c--;
            }
        }
        if(grp2>=0 && grp2<=c)
        {
            if(grp1>=0 && grp1<=(v+c-grp2))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}





