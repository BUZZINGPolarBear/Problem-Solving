//
//  연산자 끼워넣기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    vector<int> v, operators;
    long long max = -1000000010;
    long long min = 1000000010;

    
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    
    for(int i=0; i<4; i++){
        int temp;
        cin>>temp;
        if(i==0 && temp != 0){
            //덧셈
            while(temp--) operators.push_back(1);
        }
        else if(i==1 && temp != 0){
            //뺄셈
            while(temp--) operators.push_back(2);
        }
        else if(i==2 && temp != 0){
            //곱셈
            while(temp--) operators.push_back(3);
        }
        else if(i==3 && temp != 0){
            //나눗셈
            while(temp--) operators.push_back(4);
        }
    }
    
    do{
        long long ans=v[0];
        for(int i=0; i<n-1; i++){
            int temp =0;
            if(operators[i] == 1){
                ans += v[i+1];
            }
            else if(operators[i] == 2){
                ans -= v[i+1];
            }
            else if(operators[i] == 3){
                ans *= v[i+1];
            }
            else if(operators[i] == 4){
                ans /= v[i+1];
            }
        }
        
        if(ans > max) max = ans;
        if(ans < min) min = ans;
    }while(next_permutation(operators.begin(), operators.end()));
    cout<<max<<"\n"<<min;
    return 0;
}
