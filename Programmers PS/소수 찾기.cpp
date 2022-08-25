//
//  소수 찾기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
bool field[10000005] = {0,};

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=2; i<sqrt(n); i++)
    {
        if(field[i] == false){
            for(int j = i*i; j<=n; j += i){
                field[j] = 1;
            }
        }
        
    }
    
    for(int i=2; i<=n; i++) if(!field[i]) answer++;
    
    return answer;
}

int main(){
    cout<<solution(10);
    return 0;
}


