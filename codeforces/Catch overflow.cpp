#include<bits/stdc++.h>
using namespace std;
const long long int maximum = (1ll<<32)-1 , RANGE = maximum * 10000 ;
int main()
{
    int l;
    cin>>l;
    long long int sum=0 , product=1;
    vector<int>loop(100000,0);
    int idx=-1;
    string S;
    bool overflow=false;
    while(l--)
    {
        cin>>S;
        //getline(cin,S);
        //cout<<S<<endl;
        if(S=="add" && !overflow)
        {
            sum+=product;
            if(sum>maximum)
                overflow=true;
        }
        else if(S=="end")
        {
            product=product/loop[idx];
            idx--;
        }
        else
        {
            int num=0 , mul=1;
            string T;
            cin>>T;
            //int num=stoi(T);
            for(int i=T.length()-1;i>=0;i--)
            {
                num+=(T[i]-48)*mul;
                mul*=10;
            }
            if( (product*num)>RANGE)
                loop[++idx]=1;
            else
            {
               loop[++idx]=num;
               product=product*num;
            }
        }
    }
    if(overflow)
        cout<<"OVERFLOW!!!";
    else
        cout<<sum;
    return 0;
}


