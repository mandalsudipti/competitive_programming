#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        long long int n , k ;
        cin>>n>>k;
        long long int tmp = n , sum = 0;
        vector<int>digit;
        
        while(tmp!=0)
        {
            digit.push_back(tmp%10);
            sum+=(tmp%10);
            tmp = tmp/10;
        }
        
        if(sum<=k)
        {
            cout<<"0"<<endl;
            continue;
        }
        else 
        {
            vector<int>ans;
            for(int i=0;i<=digit.size();i++)
            {
                if(sum<k || i==digit.size())
                {
                    if(ans.size()==digit.size())
                        ans.push_back(1);
                    else
                    {
                        int j  = i ;
                        while(j<digit.size() && digit[j]==9)
                        {
                            ans.push_back(0);
                            j++;
                        }
                        if(j>=digit.size())
                            ans.push_back(1);
                        else
                            ans.push_back(digit[j]+1);
                        for(int k=j+1;k<digit.size();k++)
                            ans.push_back(digit[k]);
                    }
                    long long int new_num = 0 ;
                    for(int i=0;i<ans.size();i++)
                        new_num+=ans[i]*pow(10,i);
                    cout<<abs(n-new_num)<<endl;
                    break;
                }
                else
                {
                    ans.push_back(0);
                    sum-=digit[i];
                }
            }
        }
    }
    
    return 0;
}

