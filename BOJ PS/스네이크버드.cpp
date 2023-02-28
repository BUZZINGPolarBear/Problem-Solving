//
//  스네이크버드.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, l;
    vector<int> v;
    
    cin>>n>>l;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++){
        if(v[i] <= l) l++;
        else break;
    }
    
    cout<<l;
}
