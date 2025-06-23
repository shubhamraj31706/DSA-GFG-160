/*
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.

Input: k = 3, arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. 

Expected Complexities
    Time Complexity: O(n log n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include<algorithm>
#include<climits>
using namespace std;

int getMinDiff(vector<int> &arr, int k) //my approach but doesnt pass some test cases
{
    // code here
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int st = 0, end = n - 1;
    int mid = st + (end - st) / 2;
    for (int i = 0; i < n; i++)
    {
        if (mid < i)
        {
            arr[i] = arr[i] - k;
        }
        else
        {
            arr[i] = arr[i] + k;
        }
    }
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal - minVal;
}

int getMinDiff1(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];
        
        for(int i=1; i<n; i++){
            if(arr[i] - k < 0){
                continue;
            }
            int minVal = min(arr[0] + k, arr[i]-k);
            int maxVal = max(arr[i-1]+k, arr[n-1]-k);
            
            ans = min(ans,maxVal - minVal);
        }
        
        return ans;
    }
int main(){
    vector<int> arr1 = {1, 5, 8,4, 10};
    int k1 = 2;
    vector<int> arr2 = {3, 9, 12, 16, 20};
    int k2 = 3;

    cout << getMinDiff1(arr1, k1) << endl;
    cout << getMinDiff1(arr2, k2) << endl;
    return 0;
}