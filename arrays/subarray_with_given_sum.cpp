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