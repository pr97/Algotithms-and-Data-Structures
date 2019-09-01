/*
* https://leetcode.com/problems/wildcard-matching/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        int valid_empty_match_before = INT_MAX;
        for(int i = 0; i < p.length(); ++i) {
            if(p[i] != '*') {
                valid_empty_match_before = i + 1;
                break;
            }
        }
        for(int i = 0; i <= s.length(); ++i) {
            for(int j = 0; j <= p.length(); ++j) {
                if(i == 0) {
                    if(j == 0 || j < valid_empty_match_before) dp[i][j] = true;
                }
                else if(j == 0) {
                    // continue, since, the 0th column already has the format {T, F, F, F, ...}       
                }
                else {
                    // 'i - 1' has been put inside '()' when indexing 's' or 'p' to denote that 'dp' tries to index into 's' or 'p' via 1-indexing whereas 's' and 'p' both originally follow 0-indexing.
                    if(s[(i - 1)] == p[(j - 1)] || p[(j - 1)] == '?') dp[i][j] = dp[i - 1][j - 1];
                    else if(p[(j - 1)] == '*') {
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    }
                    // else, do nothing, because 'dp' was already initialized with all 'false' values.
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};
// Driver Code
int main() {
    Solution sol;
    // cout << sol.isMatch("mississippi", "mis*is*p*");
    cout << sol.isMatch("aaa", "a*a");
    return 0;
}