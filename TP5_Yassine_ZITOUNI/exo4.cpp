#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

// Function to find and display the top 'n' most frequent words in a given text
void top_frequent_words(const std::string& text, int n);

int main() {
    string text;
    getline(cin, text); // Get the full input text

    cout << endl;
    
    int how_many_words;
    cin >> how_many_words; // Get the number of top frequent words to display

    top_frequent_words(text, how_many_words); // Call the function

    return 0;
}

// Function to remove punctuation from the text
string clean_text(const string& text) {
    string cleaned;
    set<char> forbid = {',', ';', '.', ':'}; // Set of punctuation marks to remove

    // Iterate through text and append only allowed characters
    for (char c : text) {
        if (forbid.find(c) == forbid.end()) cleaned += c;
    }

    return cleaned;
}

void top_frequent_words(const string& text, int n) {
    istringstream chunck(clean_text(text)); // Stream to extract words from cleaned text
    string word;
    unordered_map<string, int> myWords; // Map to store word frequencies

    // Read words from the input stream and update their count in the map
    while (chunck >> word) {
        if (myWords.find(word) != myWords.end()) 
            myWords[word]++; // Increment count if word already exists
        else 
            myWords[word] = 1; // Initialize count if word is encountered for the first time
    }

    // Convert the map into a vector of pairs for sorting
    vector<pair<string, int>> sorted_words(myWords.begin(), myWords.end());

    // Sort the words by frequency in descending order
    sort(sorted_words.begin(), sorted_words.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second; // Sort by frequency (higher first)
        });

    // Determine the number of words to print (cannot exceed the number of unique words)
    int to;
    if (n>=sorted_words.size()) to=sorted_words.size()-1;
    else to=n;

    // Print the top 'n' most frequent words
    for (int i = 0; i < to; ++i) 
        cout << sorted_words[i].first << " ==> " << sorted_words[i].second << endl;
}