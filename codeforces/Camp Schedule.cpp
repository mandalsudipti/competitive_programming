#include<bits/stdc++.h>
using namespace std;
void find_max_prefix(string T , vector<int>&max_prefix)
{
    max_prefix[0]=0;
    int i=1 , len = 0 ;
    while(i<T.length())
    {
        if(T[i]==T[len])
        {
            max_prefix[i]=(++len);
            i++;
        }
        else if(len!=0)
        {
            len = max_prefix[len-1];
        }
        else
        {
            max_prefix[i]=0;
            i++;
        }
    }
}

int main()
{
    string S , T ;
    cin>>S>>T;
    int S_one = 0 , S_zero = 0 , T_one = 0 , T_zero = 0 ;
    for(int i=0;i<S.length();i++)
        S[i]=='0'?S_zero++:S_one++;
        
    for(int i=0;i<T.length();i++)
        T[i]=='0'?T_zero++:T_one++;
    
    if(T_zero>S_zero || T_one>S_one)
    {
        cout<<S;
        return 0;
    }
    
    vector<int>max_prefix(T.length(),0);
    find_max_prefix(T,max_prefix);
    
    string add ;
    if(max_prefix.back()==0)
        add = T;
    else
    {
        for(int i=max_prefix.back();i<T.length();i++)
            add+=T[i];
    }
    int add_zero = 0 , add_one = 0 , cnt = 0 ;
    for(int i=0;i<add.length();i++)
        add[i]=='1'?add_one++:add_zero++;
    
    S_one-=T_one;
    S_zero-=T_zero;
    
    if(add_one==0)
        cnt = S_zero/add_zero;
    else if (add_zero==0)
        cnt = S_one/add_one;
    else
        cnt = min(S_one/add_one , S_zero/add_zero);
        
    for(int i=0;i<cnt;i++)
        T+=add;
    for(int i=0;i<(S_zero-(cnt*add_zero));i++)
        T+='0';
    for(int i=0;i<(S_one-(cnt*add_one));i++)
        T+='1';
        
    cout<<T<<endl;
    
    return 0;
}




