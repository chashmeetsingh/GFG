// Problem:
// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

// Output:
// Print the maximum sum of the contiguous sub-array in a separate line for each test case.

// Constraints:
// 1 ≤ T ≤ 110
// 1 ≤ N ≤ 106
// -107 ≤ A[i] <= 107

// Example:
// Input
// 2
// 5
// 1 2 3 -2 5
// 4
// -1 -2 -3 -4
// Output
// 9
// -1

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int main() {
    int t, n, num;
    vector<int> v;
    cin>>t;

    for(int i = 0; i < t; i++) {
        cin>>n;
        v.clear();

        for(int j = 0; j < n; j++) {
            cin>>num;
            v.push_back(num);
        }

        int current_max = v[0], max_so_far = v[0];
        for(int j = 1; j < n; j++) {
            current_max = max(v[j], current_max + v[j]);
            max_so_far = max(current_max, max_so_far);
        }
        cout<<max_so_far<<endl;
    }

    return 0;
}