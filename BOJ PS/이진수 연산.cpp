//
//  이진수 연산.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/28.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a, b;
    cin>>a>>b;
    vector<bool> aV, bV;
    
    for(int i=0; i<a.size(); i++){
        aV.push_back(a[i]-'0');
        bV.push_back(b[i]-'0');
    }

    for(int i=0; i<a.size(); i++){
        if(aV[i] && bV[i])cout<<1;
        else cout<<0;
    }
    cout<<"\n";
    for(int i=0; i<a.size(); i++){
        if(aV[i] || bV[i])cout<<1;
        else cout<<0;
    }
    cout<<"\n";
    for(int i=0; i<a.size(); i++){
        if(aV[i] != bV[i])cout<<1;
        else cout<<0;
    }
    cout<<"\n";
    for(int i=0; i<a.size(); i++){
        cout<<!aV[i];
    }
    cout<<"\n";
    for(int i=0; i<a.size(); i++){
        cout<<!bV[i];
    }
    return 0;
}
