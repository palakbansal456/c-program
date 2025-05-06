#include <iostream>
#include <string>
#include <algorithm>

class BigNumber {
public:
    std::string value;

    // Constructor
    BigNumber(std::string val) {
        value = val.empty() ? "0" : val;
        // Remove leading zeros
        value.erase(0, value.find_first_not_of('0'));
        if (value.empty()) {
            value = "0"; // handle case for empty string
        }
    }

    // Print the value of the BigNumber
    void print() {
        std::cout << value << std::endl;
    }

    // Add two large numbers
    BigNumber add(const BigNumber& other) {
        std::string num1 = value;
        std::string num2 = other.value;
        int len1 = num1.length();
        int len2 = num2.length();
        
        // Make both numbers equal in length by padding with leading zeros
        if (len1 < len2) num1.insert(0, len2 - len1, '0');
        if (len2 < len1) num2.insert(0, len1 - len2, '0');

        int carry = 0;
        std::string result;

        // Add digits from right to left
        for (int i = num1.length() - 1; i >= 0; i--) {
            int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }

        if (carry) result.push_back(carry + '0');

        std::reverse(result.begin(), result.end());
        return BigNumber(result);
    }

    // Subtract two large numbers (assuming num1 >= num2)
    BigNumber subtract(const BigNumber& other) {
        std::string num1 = value;
        std::string num2 = other.value;
        int len1 = num1.length();
        int len2 = num2.length();

        // Make both numbers equal in length by padding with leading zeros
        if (len1 < len2) num1.insert(0, len2 - len1, '0');
        if (len2 < len1) num2.insert(0, len1 - len2, '0');

        int borrow = 0;
        std::string result;

        // Subtract digits from right to left
        for (int i = num1.length() - 1; i >= 0; i--) {
            int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.push_back(diff + '0');
        }

        // Remove leading zeros if any
        std::reverse(result.begin(), result.end());
        result.erase(0, result.find_first_not_of('0'));

        return BigNumber(result.empty() ? "0" : result);
    }

    // Multiply two large numbers
    BigNumber multiply(const BigNumber& other) {
        std::string num1 = value;
        std::string num2 = other.value;
        int len1 = num1.length();
        int len2 = num2.length();
        
        // Result will be at most len1 + len2 digits long
        std::vector<int> result(len1 + len2, 0);

        // Multiply digits from right to left
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert the result to a string
        std::string resultStr;
        for (int i = 0; i < result.size(); i++) {
            if (!(resultStr.empty() && result[i] == 0)) {
                resultStr.push_back(result[i] + '0');
            }
        }

        return BigNumber(resultStr.empty() ? "0" : resultStr);
    }
};

// Main function to test the BigNumber class
int main() {
    BigNumber num1("123456789123456789");
    BigNumber num2("987654321987654321");

    std::cout << "Sum: ";
    BigNumber sum = num1.add(num2);
    sum.print();

    std::cout << "Difference: ";
    BigNumber diff = num1.subtract(num2);
    diff.print();

    std::cout << "Product: ";
    BigNumber product = num1.multiply(num2);
    product.print();

    return 0;
}
