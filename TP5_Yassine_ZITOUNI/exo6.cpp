#include <iostream>
#include <regex>
#include <string>
using namespace std;

// Function to check if a string contains an email address
bool contains_email(const std::string& text);

int main() {
    string text;
    getline(cin, text); // Get the full input text

    contains_email(text); // Call the function to check for an email

    return 0;
}
bool contains_email(const std::string& text) {
    // Define a regex pattern to match basic email addresses
    regex pattern(R"((\w+@\w+\.\w+))");

    smatch match; // Object to store the match result

    // Search for an email pattern in the given text
    if (regex_search(text, match, pattern)) {
        cout << "Adresse email détectée : " << match[0] << endl;
        return true;
    }

    cout << "Aucune adresse email détectée" << endl;
    return false;
}