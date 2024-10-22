#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& str) {
    std::string cleaned;

    
    for (char ch : str) {
        if (std::isalnum(ch)) {
            cleaned += std::tolower(ch);
        }
    }

    
    int left = 0;
    int right = cleaned.size() - 1;

    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    std::string input = "racecar";
    bool output = isPalindrome(input);
    std::cout << std::boolalpha << output << std::endl;  
    return 0;
}
