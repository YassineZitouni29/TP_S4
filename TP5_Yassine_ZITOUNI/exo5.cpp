#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

// Function to sort words by their length in ascending order
void sort_by_length(string& text);

int main() {
    string text;
    getline(cin, text); // Get the full input text

    sort_by_length(text); // Call the function to sort and print words by length

    return 0;
}

void sort_by_length(string& text) {
    multimap<string, int> each_word; // Store words with their lengths

    istringstream chunck(text); // Stream to extract words from text
    string word;

    // Read words from input stream and insert into the multimap
    while (chunck >> word) {
        each_word.insert({word, word.length()});
    }

    // Convert multimap to vector for sorting
    vector<pair<string, int>> words(each_word.begin(), each_word.end());

    // Sort words by length in ascending order
    sort(words.begin(), words.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second < b.second;
         });

    string result;

    // Construct sorted sentence
    for (const auto& pair : words) {
        result += pair.first + " ";
    }

    cout << result << endl; // Print the sorted words
}
