/*
You are given an array of integer arr[] where each number represents a vote to a candidate.
Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array.

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.

Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: o candidate occur more than n/3 times.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> findMajority(vector<int> &arr)
{

    int n = arr.size();

    int el1 = -1, el2 = -1, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr[i])
            cnt1++;
        else if (el2 == arr[i])
            cnt2++;
        else if (cnt1 == 0)
        {
            el1 = arr[i];
            cnt1++;
        }
        else if (cnt2 == 0)
        {
            el2 = arr[i];
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ans = {};
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
            cnt1++;
        else if (arr[i] == el2)
            cnt2++;
    }

    if (cnt1 > n / 3)
        ans.push_back(el1);
    if (cnt2 > n / 3 && el1 != el2)
    {
        ans.push_back(el2);
    }

    if (ans.size() == 2 && ans[0] > ans[1])
    {
        swap(ans[0], ans[1]);
    }

    return ans;
}

int main(){
    vector<int> arr1 = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};
    vector<int> arr2 = {1, 2, 3, 4, 5};

    vector<int> ans1 = findMajority(arr1);
    vector<int> ans2 = findMajority(arr2);

    for(int val : ans2){
        cout << val << " ";
    }

    cout << endl;
    return 0;
}
