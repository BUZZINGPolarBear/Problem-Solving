//
//  로또.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int k;
bool check[20] = {0, };
int arr[20] = {0, };
int field[20];

void back_tracking(int idx, int cnt){
    if(cnt==6){
        for(int i=0; i<6; i++){
            cout<<field[arr[i]]<<" ";
        }
        cout<<"\n";
        
        return;
    }
    
    for(int i=idx; i<k; i++){
        if(check[i] == false){
            check[i] = true;
            arr[cnt] = i;
            back_tracking(i+1, cnt+1);
            check[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    using namespace std;
    while(1){
        cin>>k;
        if(k==0) break;
        for(int i=0; i<20; i++){
            field[i] = 0;
            check[i] = 0;
            arr[i] = 0;
        }
        
        for(int i=0; i<k; i++) cin>>field[i];
        
        back_tracking(0, 0);
        cout<<endl;
    }
   
    return 0;
}
