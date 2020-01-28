#include<bits/stdc++.h>
using namespace std;
#define SIZE 2*200003
struct node 
{
    int maximum , freq ;
    node(){}
    node (int a , int b)
    {
        maximum=a;
        freq=b;
    }
};

node tree[SIZE];
int arr[100000];

node merge(node &lc , node &rc)
{
    node tmp;
    if(lc.maximum==rc.maximum)
    {
        tmp.maximum=lc.maximum;
        tmp.freq=lc.freq + rc.freq;
    }
    else if (lc.maximum>rc.maximum)
    {
        tmp.maximum=lc.maximum;
        tmp.freq=lc.freq;
    }
    else
    {
        tmp.maximum=rc.maximum;
        tmp.freq=rc.freq;
    }
    return tmp;
}
void build_tree(int idx , int left , int right)
{
    if(left==right)
    {
        tree[idx]=node(arr[left],1);
        //cout<<"leaf node->"<<idx<<endl;
        return;
    }
    int mid = (left+right)/2;
    build_tree(2*idx,left,mid);
    build_tree(2*idx+1,mid+1,right);
    tree[idx]=merge(tree[2*idx],tree[2*idx+1]);
}
node query(int idx , int left , int right , int q_left , int q_right)
{
    if(right<q_left || left>q_right|| right<left)
    {
        return node(-1,-1);
    }
    if(q_left<=left && q_right>=right)
    {
        return tree[idx];
    }
    int mid =(left+right)/2;
    node l_ans = query(2*idx,left,mid,q_left,q_right);
    node r_ans =query(2*idx+1,mid+1,right,q_left,q_right);
    return merge(l_ans,r_ans);
}

int main()
{
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    build_tree(1,1,n);
    //for(i=1;i<=15;i++)
        //cout<<i<<"-> "<<tree[i].maximum<<" "<<tree[i].freq<<endl;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        node ans = query(1,1,n,l,r);
        cout<<ans.freq<<endl;
    }
    return 0;
}

