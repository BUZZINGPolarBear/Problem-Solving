//
//  치킨 배달.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/06.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > chicken_pos;
vector<pair<int, int> > house_pos;
int field[55][55];

int n, m;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 987654321;
    int chicken_cnt=0;
    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            int temp;
            cin>>temp;
            if(temp==1) house_pos.push_back({i, j});
            else if(temp==2) {
                chicken_pos.push_back({i, j});
                chicken_cnt++;
            }
        }
    }
    
    for(int i=0; i<m; i++){
        vector<int> mask;
        
//        cout<<"\n--------"<<i<<"-------------\n";
        vector<int> save_house;
        
        for(int j=0; j<chicken_cnt; j++){
            if(j<chicken_cnt-m) mask.push_back(0);
            else mask.push_back(1);
        }
        do{
            int local_sum = 0;
            vector<pair<int, int> > copy_chicken_pos = chicken_pos;
            for(int j=0; j<chicken_cnt; j++){
                if(mask[j] == 0){
//                    cout<<"DELETE "<< j<<"th \n";
                    copy_chicken_pos[j] = {-1, -1};
                }
            }
            for(int k=0; k<house_pos.size(); k++){
                int min_sum = 987654321;
                for(int l=0; l<copy_chicken_pos.size(); l++){
                    if(copy_chicken_pos[l].first == -1) continue;
                    min_sum = min(min_sum, abs(house_pos[k].first - copy_chicken_pos[l].first) + abs(house_pos[k].second - copy_chicken_pos[l].second));
//                    cout<<"house position: {"<<house_pos[k].first<<", "<<house_pos[k].second<<"}\n->chicken position:{"<<copy_chicken_pos[l].first<<", "<<copy_chicken_pos[l].second<<"}\n";
                }
//                cout<<"min: "<<min_sum<<"\n**\n";
                if(min_sum != 987654321) local_sum += min_sum;
            }
//            cout<<"LOCAL ANS: "<<local_sum<<"\n";
            if(local_sum>0) ans = min(ans, local_sum);
        }while(next_permutation(mask.begin(), mask.end()));
        
    }
    
    cout<<ans;
    return 0;
}
