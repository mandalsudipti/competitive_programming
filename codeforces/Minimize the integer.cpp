#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string S;
        cin>>S;
        vector<int>odd;
        vector<int>even;
        for(int i=0;i<S.length();i++)
        {
            if((S[i]-48)%2==0)
                even.push_back(S[i]-48);
            else
                odd.push_back(S[i]-48);
        }
        int i = 0 , j=0;
        while(i<even.size() && j<odd.size())
        {
            if(even[i]<odd[j])
            {
                cout<<even[i];
                i++;
            }
            else
            {
                cout<<odd[j];
                j++;
            }
        }
        while(i<even.size())
        {
            cout<<even[i];
            i++;
        }
        while(j<odd.size())
        {
            cout<<odd[j];
            j++;
        }
        cout<<endl;
    }
    return 0;
}