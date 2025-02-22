#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

// Function to count the frequency of words in a given text
void word_frequency(const std::string& text);

int main() {
    string userText;
    getline(cin, userText); // Get a full line of input from the user

    word_frequency(userText); // Call the function to analyze word frequency

    return 0;
}

void word_frequency(const std::string& text) {
    istringstream chunck(text); // Stream to break text into words
    string word;
    unordered_map<string, int> myWords; // Map to store word frequencies

    // Read words from the input stream and update their count in the map
    while (chunck >> word) {
        if (myWords.find(word) != myWords.end()) {
            myWords[word]++; // Increment count if word already exists
        } else {
            myWords[word] = 1; // Initialize count if word is encountered for the first time
        }
    }

    // Print each word along with its frequency
    for (auto& pair : myWords) {
        cout << pair.first << " ==> " << pair.second << endl;
    }
}
