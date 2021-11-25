//time complexity : O(n*m *m)
//space complexity: O(m*m)

#include<bits/stdc++.h>
using namespace std;

vector<int> howSum(int targetSum, int arr[], int n, map<int, vector<int>> &memo){

    if(memo.find(targetSum) != memo.end())
        return memo[targetSum];

    vector<int> ret;
    if(targetSum == 0){
        vector<int> v(1);
        return v;
    }

    if(targetSum <0){
        vector<int> v;
        return v;
    }

    for(int i=0; i<n; i++){
        
        ret = howSum(targetSum - arr[i], arr, n, memo);

        if(ret.size() != 0){
            ret.push_back(arr[i]);
            memo[targetSum] = ret;
            return memo[targetSum];
        }
    }
    vector<int> v;
    memo[targetSum] = v;
    return v;
}

int main(){
    int n;
    cin>>n;

    vector<int> result;
    map<int, vector<int>> memo;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int targetSum;
    cin>>targetSum;

    
    vector<int> ans = howSum(targetSum, arr, n, memo);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}