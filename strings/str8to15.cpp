#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <sstream>
#include <map>
using namespace std;

/* 📝 1️⃣ SORT CHARACTERS BY FREQUENCY
   - Sort characters based on their frequency.
   - Time Complexity: O(N log N)
   - Space Complexity: O(N)
*/
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char ch : s) freq[ch]++;

    vector<pair<int, char>> freqArr;
    for (auto &[ch, count] : freq) freqArr.push_back({count, ch});

    sort(freqArr.rbegin(), freqArr.rend()); // Sort in descending order

    string result;
    for (auto &[count, ch] : freqArr) result += string(count, ch);

    return result;
}

/*
📌 DRY RUN (Input: "tree")
Step 1: Count frequency {t:1, r:1, e:2}
Step 2: Sort by frequency
Output: "eert"
*/

/* 📝 2️⃣ MAXIMUM NESTING DEPTH OF PARENTHESES
   - Find max depth of valid parentheses.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int maxDepth(string s) {
    int depth = 0, maxDepth = 0;
    for (char ch : s) {
        if (ch == '(') maxDepth = max(maxDepth, ++depth);
        if (ch == ')') depth--;
    }
    return maxDepth;
}

/*
📌 DRY RUN (Input: "(1+(2*3)+((8)/4))+1")
Output: 3
*/

/* 📝 3️⃣ ROMAN TO INTEGER
   - Convert Roman numerals to integers.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int romanToInt(string s) {
    unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                                      {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
            total -= roman[s[i]];
        } else {
            total += roman[s[i]];
        }
    }

    return total;
}

/*
📌 DRY RUN (Input: "IX")
Output: 9
*/

/* 📝 4️⃣ INTEGER TO ROMAN
   - Convert integer to Roman numeral.
   - Time Complexity: O(1) (Fixed 13 cases)
   - Space Complexity: O(1)
*/
string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
        {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string result;
    for (auto &[value, symbol] : roman) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }
    
    return result;
}

/*
📌 DRY RUN (Input: 58)
Output: "LVIII"
*/

/* 📝 5️⃣ IMPLEMENT ATOI (Convert String to Integer)
   - Convert string to integer following edge cases.
   - Time Complexity: O(N)
   - Space Complexity: O(1)
*/
int myAtoi(string s) {
    int i = 0, sign = 1, num = 0;
    
    while (i < s.size() && s[i] == ' ') i++; // Skip leading spaces
    if (s[i] == '-' || s[i] == '+') sign = (s[i++] == '-') ? -1 : 1; // Handle sign
    
    while (i < s.size() && isdigit(s[i])) {
        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] - '0' > 7)) 
            return (sign == 1) ? INT_MAX : INT_MIN; // Handle overflow
        num = num * 10 + (s[i++] - '0');
    }

    return num * sign;
}

/*
📌 DRY RUN (Input: "   -42")
Output: -42
*/

/* 📝 6️⃣ COUNT NUMBER OF SUBSTRINGS
   - Count substrings where the difference between max & min occurring character is max.
   - Time Complexity: O(N²)
   - Space Complexity: O(1)
*/
int beautySum(string s) {
    int total = 0;
    for (int i = 0; i < s.length(); i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < s.length(); j++) {
            freq[s[j] - 'a']++;
            int maxFreq = *max_element(freq.begin(), freq.end());
            int minFreq = INT_MAX;
            for (int f : freq) if (f > 0) minFreq = min(minFreq, f);
            total += (maxFreq - minFreq);
        }
    }
    return total;
}

/*
📌 DRY RUN (Input: "aabcb")
Output: 5
*/

/* 📝 7️⃣ LONGEST PALINDROMIC SUBSTRING (Expand Around Center)
   - Find the longest palindrome in a string.
   - Time Complexity: O(N²)
   - Space Complexity: O(1)
*/
string longestPalindrome(string s) {
    int start = 0, maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
        for (int j : {0, 1}) { // Expand for odd & even length palindromes
            int left = i, right = i + j;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > maxLen) {
                start = left + 1;
                maxLen = right - left - 1;
            }
        }
    }

    return s.substr(start, maxLen);
}

/*
📌 DRY RUN (Input: "babad")
Output: "bab"
*/

/* 📝 8️⃣ REVERSE EVERY WORD IN A STRING
   - Reverse every word in a given string.
   - Time Complexity: O(N)
   - Space Complexity: O(N)
*/
string reverseWords(string s) {
stringstream ss(s);
    string word;
    vector<string> words;

    // Split words and store them in a vector
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the order of the words
    reverse(words.begin(), words.end());

    // Join the words back into a single string
    string result = "";
    for (const string& w : words) {
        if (!result.empty()) result += " ";
        result += w;
    }

    return result;
}

/*
📌 DRY RUN (Input: "hello world")
Output: "olleh dlrow"
*/

/* 📝 9- Helper Function: Count Substrings with At Most K Distinct Characters
   - Uses Sliding Window (Two Pointers) + Hash Map
   - Time Complexity: O(N)
   - Space Complexity: O(K) (Hash Map)
*/
int countSubstringsAtMostK(const string &s, int K) {
    if (K == 0) return 0; // No valid substrings if K is 0

    unordered_map<char, int> freq; // Store character counts
    int left = 0, count = 0;
    string substring = ""; // Store current window as a string

    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++; // Add new character
        substring += s[right]; // Append character to string

        // Reduce window if distinct count exceeds K
        while (freq.size() > K) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]); // Remove from map if count is 0
            substring = substring.substr(1); // Remove first character from string
            left++; // Shrink window from left
        }

        // Count valid substrings ending at 'right'
        count += (right - left + 1);
    }

    return count;
}

/* 📝 Main Function: Substrings with Exactly K Distinct Characters
   - Uses formula: f(K) = countSubstringsAtMostK(K) - countSubstringsAtMostK(K-1)
   - Time Complexity: O(N)
   - Space Complexity: O(K) (for frequency map)
*/
int substringsWithKDistinct(const string &s, int K) { //gfg
    return countSubstringsAtMostK(s, K) - countSubstringsAtMostK(s, K - 1);
}

/* 📌 DRY RUN (Input: "pqpqs", K = 2)
Step 1: Find substrings with ≤ K=2 distinct chars → 12
Step 2: Find substrings with ≤ K=1 distinct chars → 7
Step 3: Subtract → 12 - 7 = 5
Output: 5
*/

/* 🏆 MAIN FUNCTION TO TEST THE SOLUTION */
int main() {
    string s = "pqpqs";
    int K = 2;
    cout << "Substrings with exactly " << K << " distinct characters: " << substringsWithKDistinct(s, K) << endl;
    return 0;
}


/* 🏆 MAIN FUNCTION TO TEST ALL FUNCTIONS */
int main() {
    cout << "Frequency Sort: " << frequencySort("tree") << endl;
    cout << "Max Depth Parentheses: " << maxDepth("(1+(2*3)+((8)/4))+1") << endl;
    cout << "Roman to Integer: " << romanToInt("IX") << endl;
    cout << "Integer to Roman: " << intToRoman(58) << endl;
    cout << "Atoi: " << myAtoi("   -42") << endl;
    cout << "Beauty Sum: " << beautySum("aabcb") << endl;
    cout << "Longest Palindromic Substring: " << longestPalindrome("babad") << endl;
    cout << "Reverse Words: " << reverseWords("hello world") << endl;

    return 0;
}
