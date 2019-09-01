/*
* https://leetcode.com/problems/regular-expression-matching/
*/

#include <bits/stdc++.h>

using namespace std;

// See the commented code after the main function to commented logic behind some lines of code.
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        bool only_star = true;
        int only_star_before = INT_MAX;
        for(int i = 0; i < p.length(); ++i) {
            if(i == p.length() - 1 && p[i] != '*') {
                only_star = false;
                only_star_before = i + 1;
            }
            if(i < p.length() - 1 && (p[i] != '*' && p[i + 1] != '*')) {
                only_star_before = i + 1; // i + 1 and not i because 1-indexing in 'dp' and 0-indexing in 's' and 'p'
                only_star = false;
                break;
            }
        }
        for(int i = 0; i <= s.length(); ++i) {
            for(int j = 0; j <= p.length(); ++j) {
                if(i == 0) {
                    if(j == 0 || j < only_star_before) dp[i][j] = true;
                }
                else if(j == 0) {
                    // continue, since, the 0th column already has the format {T, F, F, F, ...}       
                }
                else {
                    // 'i - 1' has been put inside '()' when indexing 's' or 'p' to denote that 'dp' tries to index into 's' or 'p' via 1-indexing whereas 's' and 'p' both originally follow 0-indexing.
                    if(s[(i - 1)] == p[(j - 1)] || p[(j - 1)] == '.') dp[i][j] = dp[i - 1][j - 1];
                    else if(p[(j - 1)] == '*') {
                        dp[i][j] = dp[i][j - 2]; // || (s[i] == p[i - 1] || p[i - 1] == '.') ? dp[i - 1][j] : false;
                        if(s[(i - 1)] == p[(j - 1) - 1] || p[(j - 1) - 1] == '.') dp[i][j] = dp[i][j] || dp[i - 1][j];
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

/*

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        int only_star_before = INT_MAX;
        for(int i = 0; i < p.length(); ++i) {
            if(i == p.length() - 1 && p[i] != '*') {
                only_star_before = i + 1;
                break;
            }
            if(i < p.length() - 1 && (p[i] != '*' && p[i + 1] != '*')) {
                only_star_before = i + 1; // i + 1 and not i because 1-indexing in 'dp' and 0-indexing in 's' and 'p'
                break;
            }
        }
        for(int i = 0; i <= s.length(); ++i) {
            for(int j = 0; j <= p.length(); ++j) {
                if(i == 0) {
                    if(j == 0 || j < only_star_before) dp[i][j] = true;
                }
                else if(j == 0) {
                    // continue, since, the 0th column already has the format {T, F, F, F, ...}       
                }
                else {
                    // 'i - 1' has been put inside '()' when indexing 's' or 'p' to denote that 'dp' tries to index into 's' or 'p' via 1-indexing whereas 's' and 'p' both originally follow 0-indexing.
                    if(s[(i - 1)] == p[(j - 1)] || p[(j - 1)] == '.') dp[i][j] = dp[i - 1][j - 1];
                    else if(p[(j - 1)] == '*') {
                        dp[i][j] = dp[i][j - 2]; // || (s[i] == p[i - 1] || p[i - 1] == '.') ? dp[i - 1][j] : false;
                        if(s[(i - 1)] == p[(j - 1) - 1] || p[(j - 1) - 1] == '.') dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                    // else, do nothing, because 'dp' was already initialized with all 'false' values.
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

*/