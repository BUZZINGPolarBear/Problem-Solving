//
//  벌집.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/02/25.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int between = 1;
    int acc_sum = 6;
    int ans = 1;
    cin>>n;
    
    if(n == 0) cout<<0;
    else{
        while(1){
            if(between >= n) break;
            between += acc_sum;
            acc_sum += 6;
            ans+=1;
//            cout<< between<<endl;
        }
        cout << ans;
    }
    
    return 0;
}
