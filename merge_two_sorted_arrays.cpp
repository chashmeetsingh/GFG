// Problem:
// Given two sorted arrays P[] and Q[] in non-decreasing order with size X and Y. The task is to merge the two sorted arrays into one sorted array (in non-decreasing order).

// Note: Expected time complexity is O((X+Y) log(X+Y)). DO NOT use extra space.

// Input:
// First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

// Output:
// For each test case, print (X + Y) space separated integer representing the merged array.

// Constraints:
// 1 <= T <= 100
// 1 <= X, Y <= 5*104
// 0 <= Pi, Qi <= 109

// Example:
// Input:
// 1
// 4 5
// 1 3 5 7
// 0 2 6 8 9

// Output:
// 0 1 2 3 5 6 7 8 9


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

int main() {
    int t, x, y, num;
    vector<int> p, q;
    cin>>t;

    for(int i = 0; i < t; i++) {
        cin>>x>>y;
        p.clear();
        q.clear();

        for(int j = 0; j < x; j++) {
            cin>>num;
            p.push_back(num);
        }

        for(int j = 0; j < y; j++) {
            cin>>num;
            q.push_back(num);
        }
        
        int m = 0, n = 0;
        while(m < x and n < y) {
            if (p[m] < q[n]) {
                cout<<p[m]<<" ";
                m++;
            } else {
                cout<<q[n]<<" ";
                n++;
            }
        }

        while(m < x) {
            cout<<p[m]<<" ";
            m++;
        }
        while(n < y) {
            cout<<q[n]<<" ";
            n++;
        }
        cout<<endl;
    }

    return 0;
}