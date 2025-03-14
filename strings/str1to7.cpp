#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

/* 📝 1️⃣ REMOVE OUTERMOST PARENTHESES
   - Remove outermost `()` from valid parentheses string.
   - Time Complexity: O(N)
   - Space Complexity: O(N) (for output string)
*/
string removeOuterParentheses(string s) {
    string result = "";
    int count = 0;

    for (char ch : s) {
        if (ch == '(' && count++ > 0) result += ch; // Add inner '('
        if (ch == ')' && count-- > 1) result += ch; // Add inner ')'
    }

    return result;
}

/*
📌 DRY RUN (Input: "(()())(())")
Step 1: Remove outermost `()` from each group.
Output: "()()()"
*/

/* 📝 2️⃣ REVERSE WORDS IN A STRING
   - Reverse words in a given sentence.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
string reverseWords(string s) {
    stringstream ss(s);
    string word, result = "";

    while (ss >> word) {
        result = word + (result.empty() ? "" : " ") + result; // Reverse order
    }

    return result;
}

/*
📌 DRY RUN (Input: "hello world")
Step 1: Extract words.
Step 2: Reverse order.
Output: "world hello"
*/

/* 📝 3️⃣ CHECK IF STRING IS PALINDROME
   - Check if a string reads the same forward and backward.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }

    return true;
}

/*
📌 DRY RUN (Input: "racecar")
Output: true
*/

/* 📝 4️⃣ LARGEST ODD NUMBER IN A STRING
   - Find the largest odd number possible from the string.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
string largestOddNumber(string num) {
    for (int i = num.length() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 == 1) return num.substr(0, i + 1);
    }

    return "";
}

/*
📌 DRY RUN (Input: "123456")
Output: "12345"
*/

/* 📝 5️⃣ LONGEST COMMON PREFIX
   - Find the longest common prefix in an array of words.
   - Time Complexity: O(N*M) (N=words, M=length of prefix)
   - Space Complexity: O(1)
*/
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    string prefix = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) { // Check if prefix exists
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) return "";
        }
    }

    return prefix;
}

/*
📌 DRY RUN (Input: ["flower","flow","flight"])
Output: "fl"
*/

/* 📝 6️⃣ ISOMORPHIC STRINGS
   - Check if two strings can be mapped one-to-one.
   - Time Complexity: O(N)
   - Space Complexity: O(1) (constant size map)
*/
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) return false;

    unordered_map<char, char> mapST, mapTS;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];

        if ((mapST.count(c1) && mapST[c1] != c2) || 
            (mapTS.count(c2) && mapTS[c2] != c1)) {
            return false;
        }

        mapST[c1] = c2;
        mapTS[c2] = c1;
    }

    return true;
}

/*
📌 DRY RUN (Input: "egg", "add")
Output: true
*/

/* 📝 7️⃣ CHECK IF ONE STRING IS A ROTATION OF ANOTHER
   - Check if s2 is a rotated version of s1.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
bool isRotation(string s1, string s2) {
    return (s1.length() == s2.length()) && (s1 + s1).find(s2) != string::npos;
}

/*
📌 DRY RUN (Input: "abcde", "cdeab")
Output: true
*/

/* 📝 8️⃣ CHECK IF TWO STRINGS ARE ANAGRAMS
   - Check if two strings have the same frequency of characters.
   - Time Complexity: O(N)
   - Space Complexity: O(1) (constant size array)
*/
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    vector<int> count(26, 0);

    for (char c : s) count[c - 'a']++;
    for (char c : t) {
        if (--count[c - 'a'] < 0) return false;
    }

    return true;
}

/*
📌 DRY RUN (Input: "listen", "silent")
Output: true
*/

/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    cout << "Remove Outer Parentheses: " << removeOuterParentheses("(()())(())") << endl;
    cout << "Reverse Words: " << reverseWords("hello world") << endl;
    cout << "Is Palindrome: " << (isPalindrome("racecar") ? "true" : "false") << endl;
    cout << "Largest Odd Number: " << largestOddNumber("123456") << endl;

    vector<string> words = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(words) << endl;

    cout << "Is Isomorphic: " << (isIsomorphic("egg", "add") ? "true" : "false") << endl;
    cout << "Is Rotation: " << (isRotation("abcde", "cdeab") ? "true" : "false") << endl;
    cout << "Is Anagram: " << (isAnagram("listen", "silent") ? "true" : "false") << endl;

    return 0;
}
// 📌 Time Complexity Summary
// Problem	Time Complexity	Space Complexity
// Remove Outer Parentheses	O(N)	O(N)
// Reverse Words in a String	O(N)	O(N)
// Check Palindrome	O(N)	O(1)
// Largest Odd Number in String	O(N)	O(1)
// Longest Common Prefix	O(N*M)	O(1)
// Isomorphic Strings	O(N)	O(1)
// String Rotation Check	O(N)	O(N)
// Check Anagrams	O(N)	O(1)
