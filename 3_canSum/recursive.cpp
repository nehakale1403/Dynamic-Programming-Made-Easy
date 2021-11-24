//time complexity : O(n^m)
//space complexity: O(m)

#include<bits/stdc++.h>
using namespace std;

bool canSum(int targetSum, int arr[], int n){

    if(targetSum == 0)
        return true;
    if(targetSum < 0)
        return false;
    for(int i=0; i<n; i++){
        
        if(canSum(targetSum-arr[i], arr, n) == true){ 
            return true; //if any of the sub problems return true, then the answer is true
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int targetSum;
    cin>>targetSum;

    if(canSum(targetSum, arr, n))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}