//time complexity : O(m*n*m)
//space complexity: O(m*m)

#include<bits/stdc++.h>
using namespace std;

vector<int> bestSum(int targetSum, int arr[], int n, map<int, vector<int>> &memo){

    cout<<"Calling for "<<targetSum<<endl;

    if(memo.find(targetSum) != memo.end()){
        return memo[targetSum];
    }

    vector<int> ret, shortestComb;
    if(targetSum == 0){
        vector<int> v(1);
        v.pop_back();
        return v;
    }

    if(targetSum < 0){
        vector<int> v;
        return v;
    }

    for(int i=0; i<n; i++){
        int remainder = targetSum - arr[i];
        ret = bestSum(remainder, arr, n, memo);
        if(ret.capacity() != 0){
            ret.push_back(arr[i]);

            // Checking if this new combination size is less than already smallest combination.
            if(shortestComb.size() > ret.size() || shortestComb.capacity() == 0){
                shortestComb = ret;
            }
        }
    }
    // Returning this shortest combination to upper called function node in tree
    memo[targetSum] = shortestComb;
    return shortestComb;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int targetSum;
    cin>>targetSum;

    map<int, vector<int>> memo;

    vector<int> result = bestSum(targetSum, arr, n, memo);

    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
}

// 5
// 12 3 4 2 8
// 100