/*
You are given an array of integers arr[]. Your task is to reverse the given array.

Note: Modify the array in place.

Examples:

Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are 1 4 3 2 6 5.
After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is 5 6 2 3 4 1.

Input: arr = [4, 5, 2]
Output: [2, 5, 4]
Explanation: The elements of the array are 4 5 2. The reversed array will be 2 5 4.

Input: arr = [1]
Output: [1]
Explanation: The array has only single element, hence the reversed array is same as the original.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/


#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int>& arr){
    int n = arr.size();
    int st = 0, end = n - 1;

    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {1, 4, 3, 2, 6, 5};
    vector<int> arr2 = {4, 5, 2};
    vector<int> arr3 = {1};

    reverseArray(arr1);
    
    reverseArray(arr2);
    
    reverseArray(arr3);
    
    return 0;
}
