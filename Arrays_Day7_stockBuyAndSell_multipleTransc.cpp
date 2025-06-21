/*
The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day. 
Find the maximum profit that you can get.

Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.

Examples:

Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210. 
Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.

Input: prices[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2. Maximum Profit = 2.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> &arr)
{
    // code here
    int n = arr.size();
    // int maxProfit = 0;   //my approach but have some errors but passing few test cases
    // int currVal = arr[0];
    // int ans = 0;
    // int idx = 0;

    // for(int idx = 1; idx < n; idx++){
    //     while(arr[idx] > currVal && idx < n){
    //         maxProfit = max(maxProfit, arr[idx] - currVal);
    //         currVal = min(currVal, arr[idx]);
    //         idx++;
    //     }
    //     currVal = arr[idx];
    //     ans+=maxProfit;

    // }

    // return ans;

    int ans = 0;   //very good approach
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            ans += arr[i] - arr[i - 1];
        }
    }
    return ans;
}

int main(){
    vector<int> arr1 = {100, 180, 260, 310, 40, 535, 695};
    vector<int> arr2 = {4, 2, 2, 2, 4};

    cout << maximumProfit(arr1) << endl;
    cout << maximumProfit(arr2) << endl;

    return 0;
}
