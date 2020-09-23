#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n ;
        string S;
        cin>>n>>S;
        
        vector<int>A;
        vector<int>B;
        for(int i=0;i<S.length();i+=2)
        {
            A.push_back(S[i]-'0');
            if(i+1<S.length())
                B.push_back(S[i+1]-'0');
        }
        
        if(A.size()>B.size())
        {
            bool flag = false;
            for(int i=0;i<A.size();i++)
            {
                if(A[i]%2)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout<<"1"<<endl;
            else
                cout<<"2"<<endl;
        }
        else
        {
            bool flag = false;
            for(int i=0;i<B.size();i++)
            {
                if(B[i]%2==0)
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout<<"2"<<endl;
            else
                cout<<"1"<<endl;
            
        }
    }
    
    return 0;
}
