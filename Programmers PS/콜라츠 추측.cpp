//
//  콜라츠 추측.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    if(num == 1) return 1;
    long long temp = num;
    for(int i=1; i<=500; i++){
        if(temp %2 ==0){
            temp /= 2;
        }
        else{
            temp *= 3;
            temp ++;
        }
        
        if(temp == 1) return i;
    }
    return -1;
}

int main(){
    cout<<solution(1);
    
    return 0;
}
