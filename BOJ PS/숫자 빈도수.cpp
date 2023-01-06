//
//  숫자 빈도수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/07.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, d;
    int ans=0;
    
    cin>>n>>d;
    
    for(int i=1; i<=n; i++){
        string temp = to_string(i);
        
        for(int j=0; j<temp.size(); j++){
            if(temp[j]-'0'==d) ans++;
        }
    }
    
    cout<<ans;
    return 0;
}
