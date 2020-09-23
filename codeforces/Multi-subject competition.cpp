#include<bits/stdc++.h>
using namespace std;

bool compare(const vector<long long int>&A , const vector<long long int>&B)
{
   return A.size()>B.size() ; 
}

int main()
{
    int candidate , total_subject ;
    cin>>candidate>>total_subject;
    
    int sub , skill ;
    vector<vector<long long int>>skill_in_subject(total_subject+1);
    for(int i=0;i<candidate;i++)
    {
        cin>>sub>>skill;
        skill_in_subject[sub].push_back(skill);
    }
    
    for(int i=1;i<skill_in_subject.size();i++)
        sort(skill_in_subject[i].begin(),skill_in_subject[i].end(),greater<long long int>());
        
    long long int max_len = 0 ;
    for(int i=1;i<skill_in_subject.size();i++)
    {
        for(int j=1;j<skill_in_subject[i].size();j++)
            skill_in_subject[i][j]+=skill_in_subject[i][j-1];
            
        max_len = max(max_len,(long long int)(skill_in_subject[i].size()));
    }
    
    sort(skill_in_subject.begin(),skill_in_subject.end(),compare);
    
    long long int max_sum = 0 , cur_sum = 0 ;
    
    for(int i=0;i<max_len;i++)
    {
        cur_sum = 0 ;
        
        for(int j=0;j<skill_in_subject.size();j++)
        {
            if(i<skill_in_subject[j].size() && skill_in_subject[j][i]>=0)
                cur_sum+=skill_in_subject[j][i];
            else if(i>=skill_in_subject[j].size())
                break;
        }
        
        max_sum = max(max_sum,cur_sum);
    }
    
    cout<<max_sum<<endl;
    
    return 0;
}


