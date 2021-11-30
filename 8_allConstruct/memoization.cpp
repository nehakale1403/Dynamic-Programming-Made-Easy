//time complexity: O(n ^m *m)
//space complexity: O(m*m)

#include<bits/stdc++.h>
using namespace std;

string minusString(string source, int len){

    string temp = "";

    for(int i=len; i<source.length(); i++)
        temp += source[i];

    return temp;
}

vector<vector<string>> allConstruct(int n, string wordBank[], string target, map<string,vector<vector<string>>> &memo){

    if(memo.find(target) != memo.end())
        return memo[target];
    vector<vector<vector<string>>> ans;

    if(target == ""){
        vector<vector<string>> v(1);
        v.pop_back();
        return v;
    }

    for(int i=0; i<n; i++){
        int pos = target.find(wordBank[i]);
        if(pos == 0){
            string new_target = minusString(target, wordBank[i].length());

            vector<vector<string>> suffixWays = allConstruct(n, wordBank, new_target, memo);
            if(suffixWays.capacity() != 0){
                if(suffixWays.size() == 0){
                    vector<string> push;
                    push.push_back(wordBank[i]);
                    suffixWays.push_back(push);
                }else{
                    for(int j=0; j<suffixWays.size(); j++){
                        suffixWays[j].push_back(wordBank[i]);
                    }
                }
                ans.push_back(suffixWays);
            }
        }
    }

    vector<vector<string>> ret;

    if(ans.size() != 0)
    {
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++)
                ret.push_back(ans[i][j]);
        }
    }
    memo[target] = ret;
    return ret;
}   

int main(){
    int n;
    cin>>n;

    string wordBank[n];
    for(int i=0; i<n; i++) cin>>wordBank[i];

    string target;
    cin>>target;

    map<string,vector<vector<string>>> memo;
    vector<vector<string>> result = allConstruct(n, wordBank,target, memo);
	
	if(result.size()==0)
	    cout<<"Not possible"<<endl;
	else
	{
        cout<<"Possible Combinations are "<<endl;
	    for(int i=0;i<result.size();i++)
	    {
	        for(int j=result[i].size()-1;j>=0;j--)
	        {
	            cout<<result[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
}