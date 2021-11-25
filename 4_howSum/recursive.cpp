//time complexity : O(n^m)
//space complexity: O(m)

#include<bits/stdc++.h>
using namespace std;

vector<int> howSum(int targetSum, int arr[], int n, vector<int> &result){
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
        
        ret = howSum(targetSum - arr[i], arr, n, result);

        if(ret.size() != 0){
            result.push_back(arr[i]);
            return result;
        }
    }
    return result;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int targetSum;
    cin>>targetSum;

    vector<int> result;
    vector<int> ans = howSum(targetSum, arr, n, result);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}