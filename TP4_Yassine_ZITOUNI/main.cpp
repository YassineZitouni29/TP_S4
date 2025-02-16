#include <iostream>
#include <bits/stdc++.h> // Includes all standard libraries for convenience
#ifndef EXO
#define EXO 11 // Define a macro EXO with a default value of 11
#endif

using namespace std;

// Function to get the value of a key from the LRU cache
int get(list<pair<int,int>>& cache, unordered_map<int, list<pair<int,int>>::iterator>& lru, int key) {
    if (lru.find(key) == lru.end()) return -1; // If key is not found, return -1

    // Move the accessed element to the front (most recently used)
    list<pair<int,int>>:: iterator it = lru[key];
    pair<int,int> item = *it;
    cache.erase(it);
    cache.push_front(item);
    lru[key] = cache.begin();
    return item.second;
}

// Function to insert a key-value pair into the LRU cache
void put(list<pair<int,int>>& cache, unordered_map<int, list<pair<int,int>>::iterator>& lru, int key, int value, int cap) {
    if (lru.find(key) != lru.end()) { // If the key already exists, update its value
        list<pair<int,int>>::iterator it = lru[key];
        pair<int,int> item = *it;
        item.second = value;
        cache.erase(it);
        cache.push_front(item);
        lru[key] = cache.begin();
    } else { 
        if (cache.size() == cap) { // If cache is full, remove the least recently used element
            int lrukey = cache.back().first;
            lru.erase(lrukey);
            cache.pop_back();
        }
        // Insert the new key-value pair at the front
        cache.push_front({key, value});
        lru[key] = cache.begin();
    }
}

// Function to display the current state of the cache
void display(list<pair<int,int>>& cache) {
    cout << "Current cache state: ";
    for (auto i : cache) {
        cout << "( " << i.first << ", " << i.second << " ) ";
    }
    cout << endl;
}

int main() {
    #if EXO == 1
    // Sum an array of numbers
    int tableau[] = {10, 20, 30, 40, 50};
    int summ = 0;
    for (auto i : tableau) {
        summ += i;
        cout << i << " ";
    }
    cout << endl;
    cout << summ << endl;

    #elif EXO == 2
    // Work with a 3x3 matrix and calculate the diagonal sum
    int matrice[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int summ = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << *(*(matrice + i) + j) << " ";
        }
        summ += *(*(matrice + i) + i); // Summing diagonal elements
        cout << endl;
    }
    cout << summ << endl;

    #elif EXO == 3
    // Using std::array to reverse an array
    std::array<int, 5> tableau = {2, 9, 8, 6, 5};
    cout << "Original: ";
    for (auto it = tableau.begin(); it != tableau.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\nReversed: ";
    for (auto it = tableau.rbegin(); it != tableau.rend(); ++it) {
        cout << *it << " ";
    }

    #elif EXO == 4
    // Read a list of integers, double each, and display them
    vector<int> tab;
    cout << "Enter your list: " << endl;
    string listi;
    getline(cin, listi);
    int i = 0;
    string chunck;
    while (i < listi.length()) {
        if (listi[i] != ' ') { chunck += listi[i]; }
        else {
            if (chunck != "") tab.push_back(stoi(chunck));
            chunck = "";
        }
        ++i;
    }
    tab.push_back(stoi(chunck)); // Convert last element
    cout << "Doubled list: " << endl;
    for (auto it = tab.begin(); it != tab.end(); ++it) {
        (*it) *= 2; 
        cout << *it << " ";
    }

    #elif EXO == 5
    // Manipulating a doubly linked list (std::list)
    list<int> tab;
    cout << "Enter your list: " << endl;
    string listi;
    getline(cin, listi);
    int i = 0;
    string chunck;
    while (i < listi.length()) {
        if (listi[i] != ' ') { chunck += listi[i]; }
        else {
            if (chunck != "") tab.push_back(stoi(chunck));
            chunck = "";
        }
        ++i;
    }
    tab.push_back(stoi(chunck)); // Convert last element

    // Add numbers at the beginning and end
    cout << "Enter a number to add at the beginning: ";
    int num1;
    cin >> num1;
    tab.push_front(num1);

    cout << "Enter a number to add at the end: ";
    int num2;
    cin >> num2;
    tab.push_back(num2);

    // Display modified list
    for (auto num : tab) {
        cout << num << " ";
    }

    #elif EXO == 6
    // Using std::set to store unique numbers
    set<int> seti;
    cout << "Enter your set: " << endl;
    string sett;
    getline(cin, sett);
    int i = 0;
    string chunck;
    while (i < sett.length()) {
        if (sett[i] != ' ') { chunck += sett[i]; }
        else {
            if (chunck != "") seti.insert(stoi(chunck));
            chunck = "";
        }
        ++i;
    }
    seti.insert(stoi(chunck)); // Insert last element

    cout << "Original set: ";
    for (int num : seti) cout << num << " ";
    cout << endl;

    // Try inserting an existing number
    cout << "Enter a number you already added: ";
    int numm;
    cin >> numm;
    seti.insert(numm);
    cout << "After insertion: ";
    for (int num : seti) cout << num << " ";
    cout << "(No duplicates)" << endl;

    #elif EXO == 7
    // Using std::map (ordered dictionary)
    map<string, int> classroom;
    classroom["Yassine"] = 87;
    classroom["Ahmed"] = 91;
    classroom["Rhita"] = 96;

    for (auto& [key, value] : classroom) {
        cout << key << " : " << value << endl;
    }

    #elif EXO == 8
    // Using unordered_map to count word occurrences
    unordered_map<string, int> mymap;
    cout << "Enter words: " << endl;
    string words;
    getline(cin, words);
    int i = 0;
    string word = "";
    while (i < words.length()) {
        if (words[i] != ' ') {
            word += words[i];
        } else {
            if (word != "") mymap[word]++;
            word = "";
        }
        ++i;
    }
    mymap[word]++; // Count last word

    for (auto& pair : mymap) cout << pair.first << " : " << pair.second << endl;

    #elif EXO == 11
    // LRU Cache Implementation
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> lru;
    int capacity;
    cout << "Enter the capacity of the LRU cache: " << endl;
    cin >> capacity;
    put(cache, lru, 1, 10, capacity);
    put(cache, lru, 2, 20, capacity);
    get(cache, lru, 1);
    put(cache, lru, 55, 22, capacity);
    put(cache, lru, 2, 33, capacity);
    display(cache);
    #endif
}
