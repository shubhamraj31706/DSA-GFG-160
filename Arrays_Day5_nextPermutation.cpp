/*
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. 
If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.

Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is [3, 4, 5, 1, 2].

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)

*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& arr){ //TC -> O(n) & SC -> O(1)
    //1st step : find the pivot
    int pivot = -1, n = arr.size();

    for(int i = n - 2; i>=0; i--){

        if(arr[i] < arr[i+1]){
            pivot = i;
            break;
        }

    }

    if(pivot==-1){
        reverse(arr.begin(), arr.end()); //in place changes
        return;
    }

    //2nd step : next larger element
    for(int i = n-1; i>pivot; i--){
        if(arr[i] > arr[pivot]){
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    //3rd step : reverse piv+1 to n-1
    int i = pivot+1, j = n-1;
    while(i<j){
        swap(arr[i++], arr[j--]);
    }

}

int main(){
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    nextPermutation(arr);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
