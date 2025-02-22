#include <iostream>
#include <string>
using namespace std;

// Function to encode a string using Run-Length Encoding (RLE)
string encode_rle(const string& text);

int main() {
    string text;
    getline(cin, text); // Get a full line of input from the user

    cout << encode_rle(text) << endl; // Print the encoded string

    return 0;
}

string encode_rle(const string& text) {
    int count = 1; // Counter for consecutive character occurrences
    string result; // Encoded result string
    char c = text[0]; // First character to compare

    // Iterate through the string starting from the second character
    for (size_t i = 1; i < text.length(); ++i) {
        if (text.at(i) == c) {
            count++; // Increment count if the character is the same as previous
        } else {
            // Append character and its count to the result string
            result += c;
            result += to_string(count);
            
            // Reset the counter and update the current character
            c = text.at(i);
            count = 1;
        }
    }

    // Append the last character and its count
    result += c;
    result += to_string(count);

    return result;
}
