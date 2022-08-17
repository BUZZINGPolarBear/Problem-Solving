//
//  약수의 개수와 덧셈.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/17.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left; i<=right; i++){
        int count = 1;
        for(int j=2; j<=i; j++){
            if(i%j==0) count++;
        }
        
        if(count%2==0)
        {
            cout<<"+ "<< i<<endl;
            answer += i;
        }
        else
        {
            cout<<"- "<< i<<endl;
            answer -= i;
        }
    }
    return answer;
}

int main(){
    cout<<solution(1, 1);
    return 0;
}
