#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A) {
    vector<int> A_plus_1, res;
    int plus_1_digit, carry = 0;
    for(auto itr = A.rbegin(); itr != A.rend(); ++itr) {
        if(itr == A.rbegin())
            plus_1_digit = *itr + 1 + carry;
        else
            plus_1_digit = *itr + carry;
        A_plus_1.push_back(plus_1_digit % 10);
        carry = plus_1_digit / 10;
    }
    A_plus_1.push_back(carry);
    bool flag = false;
    for(auto itr = A_plus_1.rbegin(); itr != A_plus_1.rend(); ++itr) {
        if(*itr != 0) flag = true;
        if(flag) res.push_back(*itr);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, in;
    cin >> n;
    vector<int> A;
    for(int i = 0; i < n; ++i) {
        cin >> in;
        A.push_back(in);
    }
    vector<int> res = plusOne(A);
    for(auto itr = res.begin(); itr != res.end(); ++itr) {
        cout << *itr << " ";
    }
    return 0;
}
