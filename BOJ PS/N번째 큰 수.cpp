//
//  N번째 큰 수.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2022/12/14.
//

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            pq.push(temp);
            if (pq.size() > n) {
                pq.pop();
            }

        }
    }
    
    cout<<pq.top();
    return 0;
}
