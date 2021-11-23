//time complexity O(n)
//space complexity O()

#include<bits/stdc++.h>
using namespace std;

long long fib(int n, map<long long, long long> &memo){

    if(memo.find(n) != memo.end()) 
        return memo[n];

    if(n == 1 || n == 2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main(){
    int n;
    cin>>n;

    map<long long, long long> memo;   
    cout<<fib(n, memo);
}