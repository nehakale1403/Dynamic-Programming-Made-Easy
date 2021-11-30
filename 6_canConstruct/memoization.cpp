//time complexity: O(n^m *m)
//space complexity: O(m*m)

#include<bits/stdc++.h>
using namespace std;

string minusPrefix(string source, int len){

    string retString = "";
    for(int i=len; i<source.length(); i++){
        retString = retString + source[i];
    }

    return retString;
}

bool canConstruct(string target,string wordBank[], int n, map<string, bool> &memo){

    if(memo.find(target) != memo.end()) return memo[target];

    if(target == "") return true;

    for(int i=0; i<n; i++){

        //it checks if the given string is the substring of the target string, 
        //if yes then it returns the starting index else returns -1
        int pos = target.find(wordBank[i]);

        if(pos == 0){
            string newTarget = minusPrefix(target, wordBank[i].length());

            if(canConstruct(newTarget, wordBank, n, memo)){
                memo[target] = true;
                return true;
            }
        }
    }
    memo[target] = false;
    return false;
}

int main(){
    int n;
    cin>>n;

    string wordBank[n];
    for(int i=0; i<n; i++){
        cin>>wordBank[i];
    }

    string target;
    cin>>target;

    map<string, bool> memo;

    if(canConstruct(target, wordBank, n, memo))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}