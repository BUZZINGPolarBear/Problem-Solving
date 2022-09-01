//
//  부족한 금액 계산하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/31.
//

#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    int answer = -1;
    int temp_price = 0;
    for(int i=1; i<=count; i++){
        temp_price += price * i;
    }
    
    if(temp_price >= money) return temp_price-money;
    else return 0;
    return answer;
}
