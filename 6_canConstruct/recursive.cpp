#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string target, vector<string> wordBank){
    if(target == ""){
        return true;
    }

    for(int i=0; i<wordBank.size(); i++){
        
    }
}

int main(){
    int n;
    cin>>n;

    vector<string> wordBank(n);
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        wordBank.push_back(s);
    }

    string target;
    cin>>target;
    canConstruct(target, wordBank);
}