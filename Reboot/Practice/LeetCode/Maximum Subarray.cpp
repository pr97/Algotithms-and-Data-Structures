/*
* https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int _max = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(sum > _max) _max = sum;
            if(sum <= 0) sum = 0;
        }
        return _max;
    }
};

// Driver Code
int main() {
    Solution sol;
    // sol.maxSubArray(/*Input Vector goes here.*/)
    return 0;
}