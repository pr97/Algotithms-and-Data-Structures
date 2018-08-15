#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string A, string B, string C);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    int an = A.length();
    int bn = B.length();
    int cn = C.length();
    if(an + bn != cn)
    	return false;
    bool dp[an + 1][bn + 1];
    for(int j = 0; j <= bn; ++j){
    	if(j == 0)
    		dp[0][j] = true;
    	else{
    		if(C.at(j - 1) == B.at(j - 1)){
    			if(dp[0][j - 1])
    				dp[0][j] = true;
    			else
    				dp[0][j] = false;
    		}
    		else
	    		dp[0][j] = false;
    	}
    }
    for(int i = 0; i <= an; ++i){
    	if(i == 0)
    		dp[i][0] = true;
    	else{
    		if(C.at(i - 1) == A.at(i - 1)){
    			if(dp[i - 1][0])
    				dp[i][0] = true;
    			else
    				dp[i][0] = false;
    		}
    		else
	    		dp[i][0] = false;
    	}
    }
    for(int i = 1; i <= an; ++i){
    	for(int j = 1; j <= bn; ++j){
    		if(C.at(i + j - 1) == A.at(i - 1) && C.at(i + j - 1) != B.at(j - 1)){
    			dp[i][j] = dp[i - 1][j];
    		}
    		else if(C.at(i + j - 1) == B.at(j - 1) && C.at(i + j - 1) != A.at(i - 1)){
    			dp[i][j] = dp[i][j - 1];
    		}
    		else if(C.at(i + j - 1) == B.at(j - 1) && C.at(i + j - 1) == A.at(i - 1)){
    			dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
    		}
    		else{
    			dp[i][j] = false;
    		}
    	}
    }
    return dp[an][bn];
}