#include <bits/stdc++.h>
using namespace std;

vector<int>prevSmallerElement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    // Left to right traversal for next smaller element
    for(int i = 0;i<v.size();i++){
        // Processing the current element
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        // Top element will be the answer -> Smaller element found
        ans[i] = s.top();
        // Push that index
        s.push(i);
    }
    return ans;
}

vector<int>nextSmallerElement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    // Right to left traversal for prev smaller element
    for(int i = v.size() -1 ;i>=0;i--){
        // Processing the current element
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        // Top element will be the answer -> Smaller element found
        ans[i] = s.top();
        // Push that index
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    // Previous smaller element array
    vector<int>prev = prevSmallerElement(heights);
    // Next smaller element array
    vector<int>next = nextSmallerElement(heights);
    // Find the max area
    int size = heights.size();
    int maxArea = INT_MIN;
    for(int i = 0;i<heights.size();i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;
        int area = length*width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Constructing the vector of vectors of integers
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(v[0]);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // updating current row with previous values
                if (v[i][j]) {
                    v[i][j] += v[i - 1][j];
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }
        return area;
}

int main()
{
    // * Maximal rectangle in binary matrix
    // ! Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << "Maximal rectangle area: " << maximalRectangle(matrix) << endl;
    return 0;

    return 0;
}