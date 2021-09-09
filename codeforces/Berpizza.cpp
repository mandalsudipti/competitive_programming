#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int query ;
    cin>>query ;
    
    
    vector<int>money_of_customer(query+1 , -1) ;
    int cur_cust = 0 , served_cust = 1 ;
    
    vector<bool>is_served(query + 1 , false) ;
    map<int,vector<int>,greater<int>>money ; // money - list of customer 
    
    int query_type , m ;
    while(query--)
    {
        cin>>query_type;
        
        if(query_type == 1)
        {
            cin>>m ;
            cur_cust++ ;
            
            money_of_customer[cur_cust] = m ;
            money[m].push_back(cur_cust) ;
        }
        else if(query_type == 2) // serve oldest customer
        {
            while(is_served[served_cust])
                served_cust++ ;
                
            is_served[served_cust] = true ;
            cout<<served_cust<<" ";
            
            int cur_money = money_of_customer[served_cust] ;
            money[cur_money].erase( find(money[cur_money].begin() , money[cur_money].end() , served_cust) );
            if(money[cur_money].size() == 0)
                money.erase(money.find(cur_money));
        }
        else // serve richest customer
        {
            int cur_money = (*money.begin()).first ;
            int cur_cust = money[cur_money][0] ;
            cout<<cur_cust<<" ";
            is_served[cur_cust] = true ;
            
            money[cur_money].erase(money[cur_money].begin());
            if(money[cur_money].size() == 0)
                money.erase(money.begin());
        }
    }
    
    return 0 ;
}
