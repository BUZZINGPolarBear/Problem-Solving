//
//  지능형 기차.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/23.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int ans = -100;
    int now = 0;
    
    for(int i=0; i<4; i++){
        int in, out;
        cin>>out>>in;
        now -= out;
        now += in;
        
        ans = max(ans, now);
    }
    
    cout<<ans;
    return 0;
}
