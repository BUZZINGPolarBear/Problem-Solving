//
//  부등호.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/04.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check[15];
int arr[15];
int k;
long long max_num = -987654321;
long long  min_num = 9876543210;
string max_str;
string min_str;
vector<char> left_or_right(20);
void back_tracking(int cnt){
    if(cnt == k+1){
        int flag = 1;
        for(int i=0; i<k; i++){
            if(left_or_right[i] == '<'){
                if(arr[i] > arr[i+1]) flag = 0;
            }
            else{
                if(arr[i] < arr[i+1]) flag = 0;
            }
        }
        
        if(flag){
            string temp;
            for(int i=0; i<k+1; i++) temp += to_string(arr[i]);
//            if(temp[0]=='0') temp = temp.substr(1);
//            cout<<temp<<endl;
            if(max_num < stoll(temp)) {
                max_str = temp;
                max_num = stoll(temp);
            }
            if(min_num > stoll(temp)) {
                min_str = temp;
                min_num = stoll(temp);
            }
        }
        return;
    }
    
    for(int i=0; i<10; i++){
        if(check[i] == false){
            check[i] = true;
            arr[cnt] = i;
            back_tracking(cnt+1);
            check[i] = false;
        }
    }
}
int main(){
    cin>>k;
    
    for(int i=0; i<k; i++){
        cin>>left_or_right[i];
    }
    back_tracking(0);
    
    cout<<max_str<<endl<<min_str;
    return 0;
}
