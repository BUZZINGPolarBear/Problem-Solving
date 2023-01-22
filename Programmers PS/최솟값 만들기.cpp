#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    cout<<answer;
    if(A[0] < B[0]){
        answer += A[0] * B[B.size()-1];
        A.erase(A.begin());
        B.erase(B.end()-1);
    }
    else {
        answer += B[0] * A[A.size()-1];
        B.erase(B.begin());
        A.erase(A.end()-1);
    }
    
    
    return answer;
}

int main(){
    cout<<solution({1, 4, 2}, {5, 4, 4});
}
