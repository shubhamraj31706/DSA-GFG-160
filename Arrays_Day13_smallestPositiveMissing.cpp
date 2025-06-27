/*
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.

Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.

Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int missingNumber(vector<int> &arr)
{
    // Your code here
    // int n = arr.size();
    // sort(arr.begin(), arr.end());  //method 1 but TC => O(nlogn)
    // int ans = 1;
    // for(int i=0; i<n; i++){
    //     if(ans==arr[i]){
    //         ans++;
    //     }else if(arr[i]>ans){
    //         break;
    //     }
    // }
    // return ans;

    int n = arr.size(); // check which number is missing from 1 to n
    for (int i = 0; i < n; i++)
    {
        int el = arr[i];
        int pos = el - 1;

        if (el >= 1 && el <= n)
        {
            if (arr[pos] != el)
            {
                swap(arr[pos], arr[i]);
                i--;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
        {
            return i + 1;
        }
    }
    return n + 1;
}

int main()
{
    vector<int> arr1 = {2, -3, 4, 1, 1, 7};
    vector<int> arr2 = {5, 3, 2, 5, 1};
    vector<int> arr3 = {-8, 0, -1, -4, -3};

    cout << missingNumber(arr1) << endl;
    cout << missingNumber(arr2) << endl;
    cout << missingNumber(arr3) << endl;
    return 0;
}