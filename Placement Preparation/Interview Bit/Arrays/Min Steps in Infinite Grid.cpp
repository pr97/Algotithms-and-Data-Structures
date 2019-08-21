#include <bits/stdc++.h>

using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int min_dist = 0;
    for(int i = 0; i < A.size() - 1; ++i) {
        min_dist += (int)abs(A[i] - A[i + 1]) + (int)abs(B[i] - B[i + 1]) - min((int)abs(A[i] - A[i + 1]), (int)abs(B[i] - B[i + 1]));
    }
    return min_dist;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, in;
    cin >> n;
    vector<int> A, B;
    for(int i = 0; i < n; ++i) {
        cin >> in;
        A.push_back(in);
    }
    for(int i = 0; i < n; ++i) {
        cin >> in;
        B.push_back(in);
    }
    cout << coverPoints(A, B);
    return 0;
}
