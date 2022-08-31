//
//  결혼식.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/08/26.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
long long visited[10005] = {0, 1, 0, };

int solution(vector<pair <int, int> > v, int n){
    int answer = 0;
    sort(v.begin(), v.end());
    queue<pair<int, int> > q;
    
    if(v[0].first != 1) return 0;
    else{
        for(auto i : v)
        {
            if(visited[i.second] == 0) visited[i.second] = visited[i.first] + 1;
            else continue;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(visited[i]<4) answer++;
        }
        
    }
    
    return answer-2;
}

int main(){
    int n, m;
    vector<pair <int, int> > v;
    
    cin>>n>>m;
    
    while(m--){
        int temp1, temp2;
        cin>>temp1 >> temp2;
        v.push_back({temp1, temp2});
    }
    
    cout<<solution(v, n);
    
    return 0;
}
