#include <bits/stdc++.h>
using namespace std;

string numberToWords(int num) {
    // base case
    if (num == 0) return "Zero";

    vector<pair<int, string>> mapping = {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"},
        {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"},
        {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"},
        {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
        {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"},
        {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
    };

    string result = "";

    for (auto& p : mapping) {
        if (num >= p.first) {
            // For numbers greater than or equal to 100, recursively call numberToWords
            // for the higher order part of the number.
            string higherPart = (p.first >= 100) ? numberToWords(num / p.first) + " " : "";

            // Append the current part of the number.
            string currentPart = p.second;

            // Append the remaining part of the number.
            string remainingPart = (num % p.first != 0) ? " " + numberToWords(num % p.first) : "";

            // Combine the parts and return.
            return higherPart + currentPart + remainingPart;
        }
    }

    return "";
}

int main() {
    // Convert a non-negative integer num to its English words representation.
    int num = 123;

    string ans = numberToWords(num);
    cout << ans;

    return 0;
}
