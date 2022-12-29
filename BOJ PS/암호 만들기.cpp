//
//  암호 만들기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int l, c;
    cin>>l>>c;
    
    vector<char> v(c);
    vector<int> mask(c);
    stack<string> q;
    
    for(int i=0; i<c; i++){
        
        cin>>v[i];
        if(i<c-l) mask[i] = 0;
        else mask[i] = 1;
    }
    sort(v.begin(), v.end());
    
    do{
        string temp="";
        for(int i=0; i<c; i++){
            if(mask[i] == 1)temp += v[i];
        }
        q.push(temp);
    }while(next_permutation(mask.begin(), mask.end()));
    
    while(!q.empty()){
        string temp = q.top();
        int cnt_aeiou=0, cnt_else=0;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]=='a' || temp[i]=='e' || temp[i]=='i' || temp[i]=='o' || temp[i]=='u') cnt_aeiou++;
            else cnt_else++;
        }
        if(cnt_aeiou >= 1 && cnt_else >= 2) cout<<q.top()<<"\n";
        q.pop();
    }
    return 0;
}
