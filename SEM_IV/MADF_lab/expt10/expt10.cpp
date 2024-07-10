#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
pair<int, string> longestCommonSubsequence(const string& str1, const string& str2, int len1, int len2) {
    int LCS[len1 + 1][len2 + 1];
    // Initializing
    for (int i = 0; i <= len1; i++)
        LCS[i][0] = 0; // Empty str2
    for (int j = 0; j <= len2; j++)
        LCS[0][j] = 0; // Empty str1
    // Filling the matrix row-wise
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            // If current characters match
            if (str1[i - 1] == str2[j - 1]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    // Construct the longest common subsequence string
    string lcsString = "";
    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcsString = str1[i - 1] + lcsString;
            i--;
            j--;
        } else if (LCS[i - 1][j] > LCS[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
// Return the length of the longest common subsequence and the subsequence string
    return {LCS[len1][len2], lcsString};
}
int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    auto result = longestCommonSubsequence(str1, str2, len1, len2);
    cout << "Length of longest common subsequence: " << result.first << endl;
    cout << "Longest common subsequence: " << result.second << endl;
    return 0;
}

