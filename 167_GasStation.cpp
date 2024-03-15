#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // kitna petrol kam pad gya
    int deficit = 0;
    // kitna petrol bacha hua h
    int balance = 0;
    // circuit kaha se start krrhe ho
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance += gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // * Gas Station

    // ! There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
    // !You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
    // !Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};

    int ans = canCompleteCircuit(gas, cost);

    cout << ans << endl;

    return 0;
}