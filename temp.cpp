#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int clothes;
    cin>>clothes;

    int arr[clothes][2];
    for(int i=0; i<clothes; i++){
        int x, y;
        cin>>x>>y;
        arr[i][0] = x;
        arr[i][1] = y;
    }

    int width[clothes] = {0};
    for(int i=0; i<clothes; i++){
        width[i] = abs(arr[i][1] - arr[i][0]);
        cout<<width[i]<<endl;
    }

    int startpt[clothes];
    for(int i=0; i<clothes; i++){
        startpt[i] = arr[i][0];
    }

    int numberofvisibleclothes=0, numberofclother=0;

    for(int i=0; i<clothes-1; i++){
        int x = startpt[i];
        int c = startpt[i+1];
        if(x == c){
            int wide = width[i];
            int wideagain=width[i+1];
            if(wide<=wideagain){
                numberofvisibleclothes = numberofclother-1;
            }
        }else if(c == x+1){
            int wide1=width[i];
            int wideagain1=width[i+1];
            if(wide1>wideagain1){
                numberofvisibleclothes = numberofclother-1;
            }
        }
    }
    cout<<numberofvisibleclothes<<endl;
}   