//
//  후보 추천하기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//추천받은 횟수, 시간, 사람
vector<pair<int, pair<int, int> > > album;
vector<int> recommand;
int n;
int m;
void input(){
    
    cin>>n;
    cin>>m;
    
    for(int i=0; i<m; i++){
        int temp;
        cin>>temp;
        recommand.push_back(temp);
    }
}

void print_ablum(int idx){
    sort(album.begin(), album.end());
    cout<<"\n---------  "<<idx<<" -------------\n";
    for(int i=0; i<album.size(); i++) cout<<"{"<<album[i].first <<", "<<album[i].second.first <<", " <<album[i].second.second<<"} ";
}
void recommand_student(){
    int time = 0;
    
    for(int i=0; i<m; i++){
        bool is_found = false;
        for(int k=0; k<album.size(); k++){
            if(album[k].second.second == recommand[i]){
                album[k].first += 1;
                is_found = true;
            }
        }
        
        if(is_found == false){
            if(album.size() < n) album.push_back({1, {time++, recommand[i]}});
            else if(album.size() == n){
                sort(album.begin(), album.end());
                album.erase(album.begin());
                album.push_back({1, {time++, recommand[i]}});
            }
        }
//        print_ablum(i);
   }
}

void print_ans(){
    vector<int> ans;
    for(int i=0; i<album.size(); i++){
        ans.push_back(album[i].second.second);
    }
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

void solve(){
    input();
    recommand_student();
    print_ans();
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
