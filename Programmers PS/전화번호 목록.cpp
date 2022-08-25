//
//  전화번호 목록.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())) return 0;
    }
    
   return 1;
}

int main(){
    cout<<solution({"119", "97674223", "1195524421"});
    return 0;
}
