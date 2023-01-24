//
//  여왕벌.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/23.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int m, n;
int field[705*2];
vector<pair<int, pair<int, int> > > cmd;

void print_field(){
    for(int i = 0; i < m; i++)
        {
            cout << field[m-1-i] + 1 << " ";
            for(int j = m; j < 2*m-1; j++)
                cout << field[j] + 1 << " ";
            cout << '\n';
        }
}
void input(){
    cin>>m>>n;
    
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        
        cmd.push_back({a, {b, c}});
    }
}

void first_grow(int idx){
    int zero_grow = cmd[idx].first;
    int one_grow = cmd[idx].second.first;
    int two_grow = cmd[idx].second.second;
    
    for(int i=0; i<2*m-1; i++){
        if(zero_grow) zero_grow--;
        else if(one_grow) one_grow--, field[i]++;
        else two_grow--, field[i] += 2;
    }
  
}

void solve(){
    input();
    
    for(int i=0; i<n; i++){
        first_grow(i);
    }
    print_field();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
