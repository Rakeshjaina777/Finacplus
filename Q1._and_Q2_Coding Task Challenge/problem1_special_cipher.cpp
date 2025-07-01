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


// shift function 
char  caesarShift(char c,  int shift) {

    return (c - 'A' +  shift) %  26 +  'A';
     
}

//  brute force function
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

    //  calling function
    
    cout << sp  ecialCipherBrute("AABCCC", 3); // Output: D2EF3
}


// Time & Space:
// Time Complexity: O(n) — single pass to shift and another for RLE.

// Space Complexity: O(n) — storing shifted + result strings. 



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

// Fewer intermediate  strings = better memory usage.

// Skips building full Caesar string.




//  Time & Space:
// Time: O(n)

// Space: O(1) extra (no temporary shifted string).




// -------------------------backend services class logivc and implemantation-------------------------

// backend services class logivc and implemantation similar to the above logic in node js framework nest js




@Injectable()

export class SpecialCipherService {

  private caesarShift(c: string,
     shift: number): string {

    return String.fromCharCode(((c.charCodeAt(0) - 65 + shift) % 26) 
    + 65);
  }

  encode(input: string, shift: number): string {
    let result = '';

    let i = 0;

    while (i < input.length) {

       const currChar = input[i];
      
       let count = 1;

      while (i + count < input.length && input[i + count] === currChar) {
          
        count++;
      }

      const shifted = this.caesarShift(currChar, shift);

      result += shifted + count.toString();

      i += count;
    }

    return result;
  }
}


Controller('cipher')

export class SpecialCipherController {

  constructor(private readonly cipherService: SpecialCipherService) {}


   @Post('encode')
   
   encodeMessage(@Body() dto: SpecialCipherDto) {
    
    const encoded = this.cipherService.encode(dto.input, dto.shift);

    return { result: encoded };

  }
}




