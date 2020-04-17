#include<bits/stdc++.h>
using namespace std;
const int SIZE = 500;

void set_light(int time_period,int start,char initial_state,int is_on[])
{
    int val = initial_state -48;
    
    for(int i=1;i<=start;i++)
    {
        is_on[i]+=val;
    }
    val = val^1 ;
    for(int i=start+1;i+2*time_period-1<SIZE;i+=2*time_period)
    {
        for(int j=i;j<min(i+time_period,SIZE);j++)
        {
            is_on[j]+=val;
            if(j+time_period<SIZE)
                is_on[j+time_period]+=(val^1);
        }
    }
}

int main()
{
    int n ;
    cin>>n;
    string initial_state ;
    cin>>initial_state;
    
    int is_on[SIZE];
    memset(is_on,0,sizeof(is_on));
    
    int time_period , start ;
    for(int i=0;i<n;i++)
    {
        cin>>time_period>>start;
        set_light(time_period,start,initial_state[i],is_on);
    }
    int maximum =0 ;
    for(int i=0;i<SIZE;i++)
    {
        if(is_on[i]>maximum)
            maximum=is_on[i];
    }
    cout<<maximum;
    return 0;
}