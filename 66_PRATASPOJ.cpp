#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> ranks,int nP, int mid)
{
    int currPrata = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        int R = ranks[i], j = 1;
        int timeTaken = 0;

        while (true)
        {
            if (timeTaken + j*R <= mid)
            {
                ++currPrata;
                timeTaken += j*R;
                ++j;
            }
            else{
                break;
            }
        }
        if(currPrata >= nP){
            return true;
        }
    }
    return false;
} 

int main()
{

    // * PRATA SPOJ Problem

    int nP = 10; // No. of prata
    int nC = 4;  // no. of cooks

    // Ranks -> [1,8]

    vector<int> ranks{1, 2, 3, 4};

    int ans = -1; // to find sawblade's height

    int start = 0;
    int highestRank = *max_element(ranks.begin(), ranks.end()); // max.rank of cook

    int end = highestRank * (nP * (nP + 1) / 2);

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossibleSolution(ranks,nP,mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}