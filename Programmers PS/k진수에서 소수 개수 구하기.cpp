//
//  k진수에서 소수 개수 구하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/10.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool eratos[1000010]={1, 1, };

int solution(int n, int k) {
    int answer = -1;

    for(int i=2; i<1000010; i++){
        if(eratos[i] == 1) continue;
        for(int j=i+i; j<1000010; j+=i){
            eratos[j] = 1;
        }
    }
    //eratos[i] == 0 이면 i는 소수
    
    string toNumber = 
    return answer;
}

int main(){
    cout<<solution(10, 10);
    return 0;
}

