//
//  점프와 순간이동.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/02.
//

#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int field[11] = {0, 1, 1, 2, 1, 2, 2};

int solution(int n)
{
    int ans = 0, temp = n;
    vector<int> v;
    
    while(temp>=2){
        if(temp%2 == 0){
            v.push_back(temp/2);
            temp /= 2;
        }
        else{
            v.push_back(temp-1);
            temp -= 1;
        }
    }
    
    sort(v.begin(), v.end());
    
    for(auto i: v) cout<<i<<" ";
    cout<<"\n";
    
    for(int i=0; i<v.size(); i++){
        if(v[i] %2 == 1) ans += 1;
    }
    
    if(n%2==1) ans +=1;
    
    return ans;
}

int main(){
    cout<<solution(7);
    
    return 0;
}
