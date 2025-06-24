/*
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.

Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    int n = arr.size();

    // int maxSum=INT_MIN;     //my approach but TC => O(n^2)
    // for(int i=0; i<n; i++){
    //     int sum=arr[i];
    //     for(int j=i+1; j<n; j++){
    //         sum+=arr[j];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // return maxSum;

    int sum = 0; // kadane's algorithm TC => O(n)
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(sum, maxSum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main(){
    vector<int> arr1 = {2, 3, -8, 7, -1, 2, 3};
    vector<int> arr2 = {-2, -4};
    vector<int> arr3 = {5, 4, 1, 7, 8};

    cout << maxSubarraySum(arr1) << endl;
    cout << maxSubarraySum(arr2) << endl;
    cout << maxSubarraySum(arr3) << endl;

    return 0;
}