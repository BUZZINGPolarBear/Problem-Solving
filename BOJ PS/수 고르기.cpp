//
//  수 고르기.cpp
//  Problem_Solving
//
//  Created by joonhwi on 2023/01/27.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m;
int ans = 0;

void input(){
    cin>>n>>m;
    v.resize(n);
    
    for(int i=0; i<n; i++) cin>>v[i];
    
    sort(v.begin(), v.end());
    ans = 2000000000+100;
}

void find_ans(){
    for(int i=0; i<n; i++){
        int anchor = v[i];
        int left = i;
        int right = n;
        
        while(left <= right){
            //중앙 위치 인덱스를 mid에 저장합니다.
            int mid = (left + right) / 2;
            //비교할 숫자와 차이를 저장합니다.
            int dif = v[mid] - anchor;
            
            if(m == dif){
                //정답과 숫자의 차이가 일치하면 종료
                ans = dif;
                break;
            }
            
            if(dif < m){
                //차이가 m보다 작으면 left를 mid보다 크게해줘서 숫자를 늘린다.
                left = mid+1;
            }
            else{
                //차이가 m보다 큰 경우(같은 경우는 첫번째 if에서 처리했음)
                //답의 가능성이 있으므로 ans에 min값 저장
                ans = min(ans, dif);
                right = mid-1;
            }
        }
    }
}

void solve(){
    input();
    find_ans();
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}
