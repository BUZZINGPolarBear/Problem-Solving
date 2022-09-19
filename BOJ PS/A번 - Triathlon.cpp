//
//  A번 - Triathlon.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/17.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    int ans = -100;
    
    while(n--){
        int a, b, c;
        cin>> a >> b>> c;
        
        int score = (b+c) * a;
        
        if( a == b+c) score *= 2;
        
        if(score > ans) ans = score;
    }
    
    cout<<ans;
    
    return 0;
}
