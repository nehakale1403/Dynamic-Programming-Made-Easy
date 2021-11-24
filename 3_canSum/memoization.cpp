#include<bits/stdc++.h>
using namespace std;

bool canSum(int targetSum, int arr[], int n, map<int, bool> &memo){

    if(memo.find(targetSum) != memo.end()){
        return memo[targetSum];
    }

    if(targetSum == 0)
        return true;

        
    if(targetSum < 0)
        return false;

        
    for(int i=0; i<n; i++){
        
        if(canSum(targetSum-arr[i], arr, n, memo) == true){ 
            memo[targetSum] = true;
            return true; 
        }
    }

    memo[targetSum] = false;
    return false;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int targetSum;
    cin>>targetSum;

    map<int, bool> memo;

    if(canSum(targetSum, arr, n, memo))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}