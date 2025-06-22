/*
Given an array prices[] of length n, representing the prices of the stocks on different days.
The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed.
Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.

Input: prices[] = [7, 6, 4, 3, 1]
Output: 0
Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.

Input: prices[] = [1, 3, 6, 9, 11]
Output: 10
Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int currVal = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > currVal)
        {
            maxProfit = max(maxProfit, prices[i] - currVal);
        }
        currVal = min(currVal, prices[i]);
    }
    return maxProfit;
}

int main(){
    vector<int> prices1 = {7, 10, 1, 3, 6, 9, 2};
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> prices3 = {1, 3, 6, 9, 11};

    cout << maximumProfit(prices1) << endl;
    cout << maximumProfit(prices2) << endl;
    cout << maximumProfit(prices3) << endl;

    return 0;
}