#include <iostream>
using namespace std;

class Solution {
public:
    string x1[3] = {"Thousand", "Million", "Billion"};
    string x2[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string x3[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string x4[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string util(int num) {
        string ans = "";
        if (num >= 100) {
            ans += x2[num / 100] + " Hundred ";
        }
        num %= 100;
        if (num >= 10 && num < 20) {
            ans += x3[num - 10] + " ";
        } else {
            if (num >= 20) {
                ans += x4[num / 10] + " ";
            }
            num %= 10;
            if (num > 0) {
                ans += x2[num] + " ";
            }
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string ans = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                ans = util(num % 1000) + (i > 0 ? x1[i - 1] + " " : "") + ans;
            }
            num /= 1000;
            i++;
        }
        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Test cases
    int num1 = 1234567891;
    int num2 = 1000;
    int num3 = 0;

    cout << "Number: " << num1 << " -> " << sol.numberToWords(num1) << endl;
    cout << "Number: " << num2 << " -> " << sol.numberToWords(num2) << endl;
    cout << "Number: " << num3 << " -> " << sol.numberToWords(num3) << endl;

    return 0;
}
