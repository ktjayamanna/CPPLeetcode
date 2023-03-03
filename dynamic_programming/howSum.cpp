#include <cstddef>
#include <iostream>
#include <string>
#include <vector>


std::vector<int> howSum(int sum,std::vector<int> arr){
    if(sum < 0){return nullptr;}
    if(sum == 0){return std::vector<int>();}
    else {
        for(int i=0; i<arr.size();i++){
            std::vector<int> result = howSum(sum - arr[i], arr);
            if(!result.empty()){
                result.push_back(arr[i]);
                return result;
            }
        }
        return nullptr;
    }
}

int main(){
    std::vector<int> arr = {1, 2, 3};
    std::vector<int> result  = howSum(4,  arr);
    for(int idx = 0; idx<result.size(); idx++){std::cout <<(result[idx]);}

}