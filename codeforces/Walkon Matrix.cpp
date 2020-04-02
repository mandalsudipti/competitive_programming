#include<bits/stdc++.h>
using namespace std;

int left_set(int k)
{
    int pos=-1;
    while(k!=0)
    {
        pos++;
        k=k>>1;
    }
    //cout<<"left_most_set_bit "<<pos<<endl;
    return pos;
}

int get_all_one(int cnt)
{
   //cout<<"count-> "<<cnt<<endl;
   int ans=0;
   for(int i=0;i<=cnt;i++)
    ans+=(1<<i);
    //cout<<ans<<endl;
   return ans;
}

int get_complement(int k , int left_most_set_bit)
{
   int x = get_all_one(left_most_set_bit);
   return (x^k) ;
}

int main()
{
    int k ;
    cin>>k;
    if(k==0)
    {
        cout<<"1"<<" "<<"1"<<endl;
        cout<<"1";
        return 0;
    }
    int left_most_set_bit = left_set(k);
    int k_complement = get_complement(k,left_most_set_bit);
    int all_one = get_all_one(left_most_set_bit+1);
    int left_one = 1<<(left_most_set_bit+1);
    
    int matrix[3][3];
    matrix[0][0]=matrix[2][0]=matrix[2][1]=all_one;
    matrix[0][1]=matrix[1][1]=matrix[2][2]=k;
    matrix[0][2]=matrix[1][2]=k_complement;
    matrix[1][0]=left_one;
    
    cout<<"3"<<" "<<"3"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
