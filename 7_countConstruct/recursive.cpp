//time complexity: O(n *m *m)
//space complexity: O(m*m)

#include<bits/stdc++.h>
using namespace std;

string minusString(string source, int len){

    string temp = "";

    for(int i=len; i<source.length(); i++)
        temp += source[i];

    return temp;
}

int countConstruct(int n, string wordBank[], string target){

    int count = 0;

    if(target == "") return 1;

    for(int i=0; i<n; i++){

        int pos = target.find(wordBank[i]);
        if(pos == 0){
            string new_target = minusString(target, wordBank[i].length());
        
            count += countConstruct(n, wordBank, new_target);
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    string wordBank[n];
    for(int i=0; i<n; i++) cin>>wordBank[i];

    string target;
    cin>>target;

    cout<<countConstruct(n, wordBank, target);
}