#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n , val ;
        vector<int>correct_place;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>val;
            if(val==i)
                correct_place.push_back(val);
        }
        if(correct_place.size()==n)
            cout<<"0"<<endl;
        else if(correct_place.size()==0)
            cout<<"1"<<endl;
        else
        {
            int cnt = 0 ;
            for(int i=1;i<correct_place.size();i++)
            {
                if(correct_place[i]- correct_place[i-1]!=1)
                    cnt++;
            }
            if((correct_place[0]==1 && correct_place.back()==n) && cnt<=1)
                cout<<"1"<<endl;
            else if((correct_place[0]==1 || correct_place.back()==n) && cnt==0)
                cout<<"1"<<endl;
            else
                cout<<"2"<<endl;
        }
    }
    return 0;
}


