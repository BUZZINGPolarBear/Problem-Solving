//
//  신규아이디 추천.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/09.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0; i<new_id.length(); i++)
    {
        if(new_id[i]>='A' && new_id[i]<='Z') answer += tolower(new_id[i]);
        else answer += new_id[i];
    }
    cout<<answer<<endl<<"++++++++++++\n";
    for(int i=0; i<answer.length(); i++){
        if(answer[i]!= '-' && answer[i]!= '.' && answer[i]!= '_')
        {
            if(answer[i]>='a' && answer[i]<='z') continue;
            if(answer[i]>='0' && answer[i]<='9') continue;
            
            answer = answer.substr(0, i) + answer.substr(i+1);
            i--;
        }
    }
    cout<<answer<<endl<<"++++++++++++\n";
    for(int i=0; i<answer.length()-1; i++){
        if(answer[i]=='.' && answer[i+1]=='.')
        {
            answer = answer.substr(0, i) + answer.substr(i+1);
            i--;
        }
    }
    while(answer[0]=='.') answer = answer.substr(1);
    while(answer[answer.length()]=='.') answer = answer.substr(0, answer.length()-1);
    cout<<answer<<endl<<"++++++++++++\n";
    
    if(answer.length()==0) answer="a";
    if(answer.length()>15) {
        answer = answer.substr(0, 15);
        cout<<answer<<endl<<"++++++++++++\n";
    }
    if(answer[answer.length()-1]=='.')
    {
        cout<<"Detected\n";
        answer = answer.substr(0, answer.length()-1);
    }
    
    cout<<answer<<endl<<"++++++++++++\n";
    
    while(answer.length()<3){
        answer += answer[answer.length()-1];
    }
    
    cout<<answer;
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solution("z-+.^.");
    
    return 0;
}
