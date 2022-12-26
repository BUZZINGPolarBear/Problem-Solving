//
//  지능형 기차 2.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/26.
//

#include <iostream>
using namespace std;

int main(){
    int now=0;
    int ans = -100000000;
    
    for(int i=0; i<10; i++){
        int in, out;
        cin>>out>>in;
        
        now -= out;
        now += in;
        
        ans = max(ans, now);
    }
    cout<<ans;
    return 0;
}
