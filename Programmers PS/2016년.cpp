//
//  2016년.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/09/02.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dayField[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    string answer = "";
    int temp = 0;
        
    for(int i=1; i<a; i++) temp+=dayField[i];
    temp += b;
    
    switch (temp%7) {
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
            
    }
    return answer;
}
