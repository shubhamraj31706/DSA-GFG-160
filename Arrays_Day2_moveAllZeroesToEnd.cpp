/*
You are given an array arr[] of non-negative integers.
Your task is to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.

Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.

Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.

Expected Complexities ->
    Time Complexity: O(n)
    Auxiliary Space: O(1)


*/

#include<iostream>
#include<vector>
using namespace std;



void moveZeroesToEnd(vector<int>& arr){
    int n = arr.size();
    int count=0;

    for(int i = 0; i<n ; i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count]);
            count++;
        }
    }

    for(int i = 0; i<arr.size() ; i++){
        cout << arr[i] << " ";
    }

}

int main(){
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    moveZeroesToEnd(arr);
    return 0;
}
