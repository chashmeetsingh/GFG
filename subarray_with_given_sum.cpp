// Problem: Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

// Input: 
// The first line of input contains an integer T denoting the number of test cases. 
// Then T test cases follow. Each test case consists of two lines. 
// The first line of each test case is N and S, where N is the size of array and S is the sum. 
// The second line of each test case contains N space separated integers denoting the array elements.

// Output:
// For each testcase, in a new line, print the starting and ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 107
// 1 <= Ai <= 1010

// Example:
// Input:
// 2
// 5 12
// 1 2 3 7 5
// 10 15
// 1 2 3 4 5 6 7 8 9 10
// Output:
// 2 4
// 1 5


#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialise variables
    int t, n, s, num, start, end, local_sum, flag;
    vector<int> array;

    // Get number of test cases
    cin>>t;

    // Loop through the number of test cases
    for(int i = 0; i < t; i++) {
        cin>>n>>s;
        // Clear the previously used array
        array.clear();
        for(int j = 0; j < n; j++) {
            cin>>num;
            array.push_back(num);
        }
        
        // Initially no sub array found
        flag = 0;

        // Start a sliding window for all possibilities
        for(start = 0; start < n; start++) {
            end = start;
            local_sum = 0;
            // Keep increasing the sliding window size till 
            // either the sum increases the wanted value
            // or array runs out of elements
            while(local_sum < s and end < n) {
                local_sum += array[end];
                end++;
            }
            // If subarray found break the loop
            if (local_sum == s) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout<<"-1"<<endl;
        } else {
            cout<<start + 1<<" "<<end<<endl;
        }
    }
    return 0;
}