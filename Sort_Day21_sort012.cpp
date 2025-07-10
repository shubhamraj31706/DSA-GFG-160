/*
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

You need to solve this problem without utilizing the built-in sort function.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.

Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.


Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr) {
    int n = arr.size();
    
    // int count1 = 0, count2 = 0, count0 = 0;  Method 1
    
    // for(int i=0; i<n; i++){
    //     if(arr[i] == 0) count0++;
    //     else if(arr[i] == 1) count1++;
    //     else count2++;
    // }
    
    // int idx=0;
    // for(int i=0; i<count0; i++){
    //     arr[idx] = 0;
    //     idx++;
    // }
    // for(int i=0; i<count1; i++){
    //     arr[idx] = 1;
    //     idx++;
    // }
    // for(int i=0; i<count2; i++){
    //     arr[idx] = 2;
    //     idx++;
    // }

    int low = 0, high = n -1, mid = 0; //Method 2 - Dutch National Flag Algo

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printVector(const vector<int>& arr) {
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {0, 1, 2, 0, 1, 2};
    vector<int> arr2 = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    cout << "Input: arr[] = [0, 1, 2, 0, 1, 2]" << endl;
    sort012(arr1);
    cout << "Output: ";
    printVector(arr1);
    cout << "Explanation: 0s 1s and 2s are segregated into ascending order.\n" << endl;

    cout << "Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]" << endl;
    sort012(arr2);
    cout << "Output: ";
    printVector(arr2);
    cout << "Explanation: 0s 1s and 2s are segregated into ascending order." << endl;

    return 0;
}
