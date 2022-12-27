//
//  튀김 소보루.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/27.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, s, m;
    vector<pair<int, int> > v;
    cin>>n>>s>>m;
    
    for(int i=1;i<=m;i++){
        int temp;
        cin>>temp;
        v.push_back({i, temp});
    }
    int time=0, add_temp=0;
    
    while(1){
        for(auto i:v){
            if(time % i.second==0){
                add_temp++;
                if(add_temp >= n-s)
                {
                    cout<<i.first;
                    return 0;
                }
            }
        }
        time++;
    }
}
