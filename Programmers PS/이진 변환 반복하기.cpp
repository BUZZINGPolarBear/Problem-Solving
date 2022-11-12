//
//  이진 변환 반복하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/11/10.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer = {0, 0};
    
    while(s!="1"){
        answer[0] += 1;
        string temp = "";
        int length=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                s = s.substr(0, i) + s.substr(i+1);
                i--;
                answer[1] += 1;
            }
        }
        
        length = s.size();
        s="";
        while(length){
            if(length % 2 == 1) s = "1" + s;
            else s = "0" + s;
            length /= 2;
        }
    }
    return answer;
}

int main(){
    vector<int> ans = solution("1111111");
    cout<<ans[0] <<" "<<ans[1];
    return 0;
}
