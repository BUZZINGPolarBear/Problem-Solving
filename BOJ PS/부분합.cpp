//
//  부분합.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/07.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, s;
    cin>>n>>s;
    
    vector<long long> v;
    
    v.push_back(0);
    for(int i=1; i<=n; i++){
        int temp;
        cin>>temp;
        
        v.push_back(temp+v[i-1]);
    }
    
    int left=1;
    int right=1;
    
    int length_ans = 100000010;
    
    while(left<=right && right <= n){
        int sum_between = v[right] - v[left-1];
        if( sum_between < s) right++;
        else{
            length_ans = min(length_ans, right-left+1);
            left+=1;
        }
    }
    if(length_ans==100000010) cout<<0;
    else cout<<length_ans;
    return 0;
    
}
