/*

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 2^31 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

*/

#include <iostream>
#include <string>

class Solution {
public:
    std::string digits[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};


    std::string int2english(int num) {
        if (num >= 1000000000) {
            return int2english(num / 1000000000) + " Billion" + int2english(num % 1000000000);
        }

        if (num >= 1000000) {
            return int2english(num / 1000000) + " Million" + int2english(num % 1000000);
        }
        if (num >= 1000) {
            return int2english(num / 1000) + " Thousand" + int2english(num % 1000);
        }
        if (num >= 100) {
            return int2english(num / 100) + " Hundred" + int2english(num % 100);
        }

        if (num >= 20) {
            return " " + tens[num / 10] + int2english(num % 10);
        }

        if (num > 0) {
            return " " + digits[num];
        }

        return "";

    }

    std::string numberToWords(int num) {
        if (num == 0) {
            return digits[0];
        }

        std::string ans = int2english(num);
        ans = ans.substr(1, ans.length() - 1);
        return ans;
    }

};

int main()
{
    std::cout << numberToWords(1000);

}
