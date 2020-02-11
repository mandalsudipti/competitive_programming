#include<bits/stdc++.h>
using namespace std;

int zero_bit(int num)
{
    int  idx_one=-1 ,idx_zero=-1, cnt=-1;
    while(num!=0)
    {
        cnt++;
        if(num&1)
            idx_one=cnt;
        else
            idx_zero=cnt;
        num = (num>>1);
    }
    if(idx_zero==-1)
        return -1;
    else
        return idx_zero ;
}

int main()
{
    int x , cnt=0;
    cin>>x;
    vector<int>ans;
    while(true)
    {
        int a = zero_bit(x);
        
        if(a!=-1)
        {
            cnt++;
            int op = (1<<(a+1))-1;
            ans.push_back(a+1);
            x=x^op ;
            if(zero_bit(x)!=-1)
            {
                x++;
                cnt++;
            }
            else
                break;
        }
        else
            break;
    }
    cout<<cnt<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
