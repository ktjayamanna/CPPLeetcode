#include <iostream>
#include <unordered_map>
#include <string>

int fib(int n){
    if (n <= 2){
        return 1;
    }
    else {
        return fib(n-2) + fib(n-1);
    }
}


unsigned int fib_memo(int n, std::unordered_map<std::string, unsigned int>& memo){
    if (n<=2){
        return 1;
    }
    else {
        if (memo.find(std::to_string(n)) == memo.end()){
            memo[std::to_string(n)] = fib_memo(n-1, memo) + fib_memo(n-2, memo);
        }
        return memo[std::to_string(n)];

        
    }

}

int main(){
    // std::cout << fib(6) << std::endl;
    // fib(8);
    int index;
    std:: cout << "What is your desired fib. number you want to know?" << std::endl;
    std::cin >> index;
    std::unordered_map<std::string, unsigned int> memo;
    std::cout << fib_memo(index, memo);
    return 0;

}