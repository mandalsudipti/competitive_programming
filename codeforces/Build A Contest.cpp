#include<bits/stdc++.h>
using namespace std;
void remove_one(int freq[],int num, int *distinct)
{
    for(int i=1;i<=num;i++)
    {
        freq[i]--;
        if(freq[i]==0)
            (*distinct)--;
    }
}

int main()
{
    int num ,  len ;
    cin>>num>>len;
    int freq[num+1],distinct=0;
    memset(freq,0,sizeof(freq));
    int val;
    for(int i=0;i<len;i++)
    {
        cin>>val;
        freq[val]++;
        if(freq[val]==1)
            distinct++;
        if(distinct==num)
        {
            cout<<"1";
            remove_one(freq,num,&distinct);
        }
        else
            cout<<"0";
    }
    return 0;
}

