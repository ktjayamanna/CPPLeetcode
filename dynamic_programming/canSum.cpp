#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool canSum(int sum, std::vector<int> &arrIn, std::unordered_map<int, bool> &memo){
    //base cases
    if(sum<0){return false;}
    else if(sum==0){return true;}
    else if (memo.count(sum)){return  memo[sum];}
    
    bool level_status = false;
    for (int i = 0; i < arrIn.size(); i++){
        level_status = level_status || canSum(sum - arrIn[i], arrIn, memo);
    }
    memo[sum] = level_status;
    return level_status;

}

int main(){
    std::vector<int> arrIn = {7,14};
    std::unordered_map<int, bool> memo;
    bool result = canSum(300, arrIn, memo);
    std::cout << result << std::endl;
}