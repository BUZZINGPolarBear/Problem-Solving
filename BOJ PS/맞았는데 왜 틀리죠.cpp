    //
    //  맞았는데 왜 틀리죠.cpp
    //  Problem_Solving
    //
    //  Created by joonhwi on 2022/11/06.
    //

    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        
        bool testCaseFlag = 1, sampleCaseFlag=1;
        int s1, s2;
        cin>>s1>>s2;
        
        for(int i=0; i<s1; i++){
            long long left, right;
            cin>>left>>right;
            
            if(left != right) {
                sampleCaseFlag = 0;
                break;
            }
        }
        
        for(int i=0; i<s2; i++){
            long long left, right;
            cin>>left>>right;
            
            if(left != right) {
                testCaseFlag = 0;
                break;
            }
        }
        
        if(sampleCaseFlag==1 && testCaseFlag==1){
            cout<<"Accepted";
            return 0;
        }
        else if(sampleCaseFlag ==0){
            cout<<"Wrong Answer";
            return 0;
        }
        else if(sampleCaseFlag==1 && testCaseFlag==0){
            cout<< "Why Wrong!!!";
            return 0;
        }
    }
