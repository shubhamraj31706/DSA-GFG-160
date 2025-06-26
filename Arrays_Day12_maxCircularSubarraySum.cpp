#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxCircularSubarraySum(vector<int> &arr)
{
    // int n = arr.size();         //i tried this approach but failed
    // int minSubSum = INT_MAX;
    // int Currsum = 0;

    // for(int i=0; i<n; i++){
    //     Currsum+=arr[i];
    //     minSubSum = min(Currsum, minSubSum);
    //     if(Currsum>0){
    //         Currsum=0;
    //     }
    // }
    // int sum = 0;
    // for(int i=0; i<n; i++){
    //     sum+=arr[i];
    // }

    // return sum - minSubSum;

    int n = arr.size();    //corrected approach
    int arraySum = 0;
    int maxSum = 0;
    int minSum = 0;
    int maxSubSum = INT_MIN;
    int minSubSum = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        arraySum += arr[i];
        maxSum += arr[i];
        maxSubSum = max(maxSubSum, maxSum);
        if (maxSum < 0)
            maxSum = 0;

        minSum += arr[i];
        minSubSum = min(minSubSum, minSum);
        if (minSum > 0)
            minSum = 0;
    }
    if (arraySum == minSubSum)
        return maxSubSum;
    return max(maxSubSum, arraySum - minSubSum);
}

int main()
{
    vector<int> arr1 = {8, -8, 9, -9, 10, -11, 12};
    vector<int> arr2 = {10, -3, -4, 7, 6, 5, -4, -1};
    vector<int> arr3 = {-1, 40, -14, 7, 6, 5, -4, -1};

    cout << maxCircularSubarraySum(arr1) << endl;
    cout << maxCircularSubarraySum(arr2) << endl;
    cout << maxCircularSubarraySum(arr3) << endl;
    return 0;
}