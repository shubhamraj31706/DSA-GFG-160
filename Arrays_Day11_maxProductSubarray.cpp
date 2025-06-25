/*
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.

Input: arr[] = [2, 3, 4]
Output: 24
Explanation: For an array with all positive elements, the result is product of all elements.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxPro = INT_MIN;

    // for(int i=0; i<n; i++){  //first approach but TC => O(n^2)
    //     int product = arr[i];
    //     for(int j=i+1; j<n; j++){
    //         product*=arr[j];
    //         maxPro = max(maxPro, product);
    //     }

    // }
    // return maxPro;

    int proLR = 1;
    int proRL = 1;

    for (int i = 0; i < n; i++)
    { // better approach TC => O(n)
        if (proLR == 0)
            proLR = 1;
        if (proRL == 0)
            proRL = 1;

        proLR *= arr[i];
        int j = n - i - 1;
        proRL *= arr[j];
        maxPro = max({maxPro, proLR, proRL});
    }
    return maxPro;
}

int main(){
    vector<int> arr1 = {-2, 6, -3, -10, 0, 2};
    vector<int> arr2 = {-1, -3, -10, 0, 6};
    vector<int> arr3 = {2, 3, 4};

    cout << maxProduct(arr1) << endl;
    cout << maxProduct(arr2) << endl;
    cout << maxProduct(arr3) << endl;

    return 0;
}