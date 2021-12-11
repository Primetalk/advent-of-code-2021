#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    long long n = 10;
    int numberOfMoves = 100;
    long long answer = 0;
    int input[n][n];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            input[i][j] = s[j] - '0';
        }   
    }
    for(int ip = 1; ip <= numberOfMoves; ++ip) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                input[i][j]++;
            }   
        }
        while(true) {
            bool isNeeded = false;
            bool flashed[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(input[i][j] >= 10) {
                        isNeeded = true;
                        input[i][j] = INT32_MIN;
                        if (i > 0) input[i - 1][j]++;
                        if (i > 0 && j > 0) input[i - 1][j - 1]++;
                        if (j > 0) input[i][j - 1]++;
                        if (j > 0 && i < n - 1) input[i + 1][j - 1]++;
                        if (i < n - 1) input[i + 1][j]++;
                        if (i < n - 1 && j < n - 1) input[i + 1][j + 1]++;
                        if (j < n - 1) input[i][j + 1]++;
                        if (i > 0 && j < n - 1) input[i - 1][j + 1]++;
                        answer++;
                    }
                }   
            }
            bool exist = true;
            if (!isNeeded) break;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                input[i][j] = max(0, input[i][j]);
            }   
        }
    }
    cout << answer;
    
}