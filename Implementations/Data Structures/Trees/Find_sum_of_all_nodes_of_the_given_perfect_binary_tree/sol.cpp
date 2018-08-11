#include <bits/stdc++.h>
using namespace std;
 
// function to find sum of all of the nodes
// of given perfect binary tree
int sumNodes(int l)
{
    // no of leaf nodes
    int leafNodeCount = pow(2, l - 1);
 
    // list of vector to store nodes of
    // all of the levels
    vector<int> vec[l];
 
    // store the nodes of last level
    // i.e., the leaf nodes
    for (int i = 1; i <= leafNodeCount; i++)
        vec[l - 1].push_back(i);
 
    // store nodes of rest of the level
    // by moving in bottom-up manner
    for (int i = l - 2; i >= 0; i--) {
        int k = 0;
 
        // loop to claculate values of parent nodes
        // from the children nodes of lower level
        while (k < vec[i + 1].size() - 1) {
 
            // store the value of parent node as
            // sum of children nodes
            vec[i].push_back(vec[i + 1][k] +
                             vec[i + 1][k + 1]);
            k += 2;
        }
    }
 
    int sum = 0;
 
    // traverse the list of vector
    // and calculate the sum
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < vec[i].size(); j++)
            sum += vec[i][j];
    }
 
    return sum;
}

int constant_time_solution(int l){
    return ((l * (l + 1)) / 2) * (log2(l) + 1); 
}

int constant_time_solution_where_l_is_level(int l){
    return ((pow(2, l - 1) * (pow(2, l - 1) + 1)) / 2) * (l); 
}

// Driver Code
int main()
{
    int l = 4;
 
    // cout << sumNodes(l);
    cout << constant_time_solution_where_l_is_level(l);
 
    return 0;
}