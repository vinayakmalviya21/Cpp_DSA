#include <iostream>
#include <stack>
#include <utility> // for pair
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st; // Stack to store pairs of (price, span)

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;

        // Pop elements from stack while the current price is greater than or equal to the top price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second; // Increment span by the popped element's span
            st.pop();
        }

        // Push the current price and its span onto the stack
        st.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    cout << stockSpanner.next(100) << endl; // Output: 1 (first day, so span is always 1)
    cout << stockSpanner.next(80) << endl;  // Output: 1 (price of 80 is lower than 100, so span is 1)
    cout << stockSpanner.next(60) << endl;  // Output: 1 (price of 60 is lower than 80, so span is 1)
    cout << stockSpanner.next(70) << endl;  // Output: 2 (price of 70 is higher than 60, so span is 2)
    cout << stockSpanner.next(60) << endl;  // Output: 1 (price of 60 is lower than 70, so span is 1)
    cout << stockSpanner.next(75) << endl;  // Output: 4 (price of 75 is higher than 60, so span is 4)

    return 0;
}
