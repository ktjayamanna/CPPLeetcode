#include<limits>
#include <iostream>
#include <string>
#include <vector>


std::vector<int> howSum(int sum,std::vector<int> arr){
    int negative_infinity = std::numeric_limits<int>::lowest(); 
    if(sum < 0){return std::vector<int> {negative_infinity};}
    if(sum == 0){return std::vector<int>();}
    else {
        for(int i=0; i<arr.size();i++){
            std::vector<int> result = howSum(sum - arr[i], arr);
            if((!result.empty() && result[0] != negative_infinity) || result.empty()){
                result.push_back(arr[i]);
                return result;
            }
        }
        return std::vector<int> {negative_infinity};
    }
}

int main() {
    std::vector<int> arr = {2, 3};
    std::vector<int> result = howSum(7, arr);
    for(int idx = 0; idx < result.size(); idx++) {
        std::cout << result[idx] << " ";  // add space after each number
    }
    std::cout << std::endl;  // add newline at the end
    return 0;
}