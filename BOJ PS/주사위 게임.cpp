//
//  주사위 게임.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/02.
//

#include <iostream>
using namespace std;

int main(){
    int n;
    int a=100, b=100;
    cin>>n;
    
    while(n--){
        int a_temp, b_temp;
        cin>>a_temp>>b_temp;
        if(a_temp==b_temp) continue;
        a_temp < b_temp ? a -= b_temp : b-= a_temp;
    }
    
    cout<<a<<"\n"<<b;
    return 0;
}
