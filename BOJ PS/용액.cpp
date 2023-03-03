//
//  용액.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/03/01.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, temp;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int left = 0;
    int right = n-1;
    int ans = 987654321;
    int ans_left, ans_right;
    int round = 0;
    while(left < right){
        int sum = v[left] + v[right];
        int dif = abs(sum - 0);
//        cout<<"\n Round : "<<round++<<" Left: "<<left<<", Right: "<<right<<", SUM: "<<sum;
        
        if(dif < ans){
//            cout<<v[left]<<" "<<v[right];
            ans_left = v[left];
            ans_right = v[right];
            
            if(dif == 0) break;
        }
        
        if(sum < 0) left++;
        else right--;
    }
//    cout<<"\n";
    cout<<ans_left<<" "<<ans_right;
    
    return 0;
}
