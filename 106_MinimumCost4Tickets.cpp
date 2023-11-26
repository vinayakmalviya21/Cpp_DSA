#include <bits/stdc++.h>
using namespace std;

int mincostTicketsHelper(vector<int> &days, vector<int> &costs, int i)
{
    if(i>=days.size()){
        return 0;
    }

    int costs1 = costs[0] + mincostTicketsHelper(days, costs, i+1);

    int passEndDay = days[i]+7-1;
    int j=i;
    while(j < days.size() && days[j] <= passEndDay){
        j++;
    }
    int costs7 = costs[1] + mincostTicketsHelper(days, costs, j);
    
    passEndDay = days[i]+30-1;
    j=i;
    while(j < days.size() && days[j] <= passEndDay){
        j++;
    }
    int costs30 = costs[2] + mincostTicketsHelper(days, costs, j);

    return min(costs1,min(costs7,costs30));
}

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int i=0;
    return mincostTicketsHelper(days, costs,i);
}

int main()
{

    // * Minimum Cost For Tickets
    // ! You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.
    // ! Train tickets are sold in three different ways:
    // ! a 1-day pass is sold for costs[0] dollars,
    // ! a 7-day pass is sold for costs[1] dollars, and
    // ! a 30-day pass is sold for costs[2] dollars.
    // ! The passes allow that many days of consecutive travel.

    vector<int> days{1, 4, 6, 7, 8, 20};
    vector<int> costs{2, 7, 15};

    cout<<mincostTickets(days, costs);
    return 0;
}