/*
* https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string smod = "$";
        for(int i = 0; i < s.length(); ++i) {
        	smod += string("#");
        	smod += s[i];
        }
        smod += string("#@");
        vector<int> p(smod.length(), 0);
        int c = 0, r = 0, mirr;
        int __max = INT_MIN, __maxc;
        for(int i = 1; i < p.size() - 1; ++i) {
        	mirr = 2 * c - i;
        	if(i < r) p[i] = min(r - i, p[mirr]);
        	while(smod[i + (p[i] + 1)] == smod[i - (p[i] + 1)]) ++p[i];
        	if(i + p[i] > r) {
        		c = i;
        		r = i + p[i];
        	}
        	if(p[i] > __max) {
        		__max = p[i];
        		__maxc = i;
        	}
        }
        int orig_start_index = (__maxc - p[__maxc]) / 2; // i - p[i] always lands on a '#'. The starting symbol of the palindrome centred at i will be the symbol after the '#' at i - p[i], which translates to the index (i - p[i]) / 2 in the original array.
        return s.substr(orig_start_index, p[__maxc]);
    }
};

// Driver code
int main(int argc, char const *argv[])
{
	Solution sol;
	cout << sol.longestPalindrome("a");
	return 0;
}