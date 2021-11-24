//time complexity : O(2^(m+n))
//space complexity: O(m+n)

#include<bits/stdc++.h>
using namespace std;

int gridTraveller(int m, int n){

    if(m == 1 && n == 1)
        return 1;
    if(m <= 0 || n <= 0)
        return 0;
    
    return gridTraveller(m-1, n) + gridTraveller(m, n-1);
}

int main(){
    int m, n;
    cin>>m>>n;

    cout<<gridTraveller(m, n);
}