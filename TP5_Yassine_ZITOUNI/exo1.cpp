#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is a palindrome
bool palindrome(string userWord);

int main() {
    string userWord;
    getline(cin, userWord); // Get user input (including spaces)
    
    // Check if the input is a palindrome and display the result
    if (palindrome(userWord)) 
        cout << "Your word is a palindrome" << endl;
    else 
        cout << "Your word is not a palindrome" << endl;

    return 0;
}

bool palindrome(string userWord) {
    string word = "";
    
    // Convert the input string to lowercase and remove spaces
    for (size_t j = 0; j < userWord.length(); ++j) {
        if (userWord.at(j) != ' ') { 
            word += tolower(userWord.at(j)); // Convert to lowercase for case insensitivity
        }
    }

    int i = 0;
    int Long = word.length();
    int till = Long / 2; // Only check up to half of the string

    // Compare characters from the beginning and end moving towards the center
    while (i < till) {
        if (word.at(i) != word.at(Long - i - 1)) 
            return false; // If any pair of characters doesn't match, it's not a palindrome
        ++i;
    }

    return true; // If all pairs match, it's a palindrome
}
