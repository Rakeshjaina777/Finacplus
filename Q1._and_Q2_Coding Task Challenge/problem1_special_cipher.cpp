// Coding Task Challenge for Finacplus

// Question 1: Special Cipher 


// Brute-force Approach


// Logic:
// Apply Caesar-cipher manually by converting each character.

// Scan the result and manually count repeated characters for RLE.


// Custom test case:
// Input: AAAAAA, shift: 2
// Caesar: CCCCCCC
// RLE: C6
// Output: C6 — Verified




#include <iostream>
#include <string>
using namespace std;

char  caesarShift(char c,  int shift) {

    return (c - 'A' +  shift) %  26 +  'A';
     
}

string specialCipherBrute(string input, int shift) {

    string shifted = "";
    for (char c : input) {
      shifted += caesarShift(c, shift);

    }

    string result = "";

    for (int i = 0; i < shifted.length(); ) {

        char curr = shifted[i];

        int count = 1;

        while (i + count < shifted.length() && shifted[i + count] == curr) {

            count++;

        }

        result += curr + to_string(count);
        i += count;
    }


    return result;
}

int main() {
    // Example calling function
    cout << sp  ecialCipherBrute("AABCCC", 3); // Output: D2EF3
}


// Time & Space:
// Time: O(n) — single pass to shift and another for RLE.

// Space: O(n) — storing shifted + result strings.



// Optimal Approach

// approach:  We can combine the Caesar + RLE steps in one loop.

// Code:
string specialCipherOptimal(string input, int shift) {
    string result = "";

    int i = 0;

    while (i < input.size()) {

        char shifted = caesarShift(input[i], shift);

        int count = 1;

        while (i + count < input.size() && input[i + count] == input[i]) {

            count++;

        }
        result += shifted + to_string(count);

        i += count;

    }
    return result;
}


//  Improvement:

// Fewer intermediate 
// strings = better memory usage.

// Skips building full Caesar string.




//  Time & Space:
// Time: O(n)

// Space: O(1) extra (no temporary shifted string).



