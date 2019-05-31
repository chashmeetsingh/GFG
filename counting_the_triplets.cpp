// Problem:
// Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.

// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.

// Output:
// For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".

// Constraints:
// 1 <= T <= 100
// 3 <= N <= 105
// 1 <= A[i] <= 106

// Example:
// Input:
// 2
// 4
// 1 5 3 2
// 3
// 3 2 7
// Output:
// 2
// -1

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        sort(v.begin(), v.end());
        // for(auto j: v) {
        //     cout<<j<<" ";
        // } cout<<endl;

        int triplet_count = 0;
        for(int j = n - 1; j >= 0; j--) {
            int k = 0;
            int l = j - 1;
            while(k < l) {
                // cout<<"Current check "<<v[j]<<" "<<v[k]<<" "<<v[l]<<endl;
                if (v[j] == (v[k] + v[l])) {
                    triplet_count++;
                    k++;
                    // break;
                } else if (v[j] > (v[k] + v[l])) {
                    k++;
                } else {
                    l--;
                }
            }
        }

        if (triplet_count == 0) {
            cout<<-1<<endl;
        } else {
            cout<<triplet_count<<endl;
        }
    }

    return 0;
}