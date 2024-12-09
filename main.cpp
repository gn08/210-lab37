#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include <algorithm>
using namespace std;

// Computes a hash index based on the sum of character ASCII values modulo 1000.
// arguments: `input` (const string&) - the input string to hash.
// returns: (int) - the computed hash index.
int gen_hash_index(const string& input){
    int sum = 0;
    for (char c : input){
        sum += (int)c;
    }
    return sum % 1000;
}

// Prints the first 100 entries in the hash table.
// arguments: `hash_table` (const map<int, list<string>>&) - the hash table to print from.
// returns: None.
void print_first_100(const map<int, list<string>>& hash_table){
    int count = 0;
    for (const auto& pair : hash_table){
        if (count >= 100) break;
        cout << "Hash Index: " << pair.first << " [ ";
        for (const auto& code : pair.second){
            cout << code << " ";
        }
        cout << "]" << endl;
        count++;
    }
}

// Searches for a key in the hash table and reports its presence or absence.
// arguments: 
// - `hash_table` (const map<int, list<string>>&) - the hash table to search.
// - `key` (const string&) - the key to search for.
// returns: None.
void search_key(const map<int, list<string>>& hash_table, const string& key){
    int hash_index = gen_hash_index(key);
    auto it = hash_table.find(hash_index);
    if ( it != hash_table.end()){
        const auto& values = it->second;
        if (find(values.begin(), values.end(), key) != values.end()) {
            cout << "Key: " << key << " found at hash index: " << hash_index << endl;
        } else {
            cout << "Key: " << key << " not found in the list at index: " << hash_index << endl;
        }
    } else {
        cout << "Key: " << key << "- not found in the hash table" << endl;
    }
}

// Adds a value to the hash table at the computed hash index.
// arguments: 
// - `hash_table` (map<int, list<string>>&) - the hash table to modify.
// - `value` (const string&) - the value to add.
// returns: none
void add_key(map<int, list<string>>& hash_table, const string& value){
    int hash_index = gen_hash_index(value);
    hash_table[hash_index].push_back(value);
    cout << "The added value is: " << value << "- at index: " << hash_index << endl;
}

// Removes a key from the hash table if it exists at the computed hash index.
// arguments: 
// - `hash_table` (map<int, list<string>>&) - the hash table to modify.
// - `key` (const string&) - the key to remove.
// returns: None.
void remove_key(map<int, list<string>>& hash_table, const string& key){
    int hash_index = gen_hash_index(key);
    auto it = hash_table.find(hash_index);
    if (it != hash_table.end()){
        auto& values = it->second;
        auto value_it = find(values.begin(), values.end(), key);
        if (value_it != values.end()) {
            values.erase(value_it);
            cout << "Removed key: " << key << " from index: " << hash_index << endl;
            if (values.empty()) {
                hash_table.erase(it);
            }
        } else {
            cout << "Key: " << key << " not found in the list at index: " << hash_index << endl;
        }
    } else {
        cout << "Key: " << key << " not found in the hash table." << endl;
    }
}

//Modifies an existing value in the hash table, replacing it with a new value.
// arguments: 
// - `hash_table` (map<int, list<string>>&) - the hash table to modify.
// - `key` (const string&) - the key associated with the old value.
// - `old_value` (const string&) - the value to replace.
// - `new_value` (const string&) - the new value to insert.
// returns: None.
void modify_key(map<int, list<string>>& hash_table, const string& key, const string& old_value, const string& new_value){
    int hash_index = gen_hash_index(key);
    auto it = hash_table.find(hash_index);
    if (it != hash_table.end()){
        auto& values = it-> second;
        auto value_it = find(values.begin(), values.end(), old_value);
        if (value_it != values.end()){
            *value_it = new_value;
            cout << "Replaced value: " << old_value << " with the new value: " << new_value << "at index: " << key << endl;
        } else {
            cout << "Value: " << old_value << " not found at hash: " << key << endl;
        }
    } else {
        cout << "Key: " << key << "not found" << endl;
    }
}

int main() {
    string line;
    int choice;
    map<int, list<string>> hash_table;

    ifstream file("lab-37-data.txt");
    if (!file.is_open()){
        cout << "Error opening" << endl;
        return 1;
    }

    while (getline(file, line)){
        int index = gen_hash_index(line);
        hash_table[index].push_back(line);
    }

    file.close();

    do{
        cout<< "Menu: " << endl;
        cout << "1. Print first 100 entries" << endl;
        cout << "2. Search for key" << endl;
        cout << "3. Add key" << endl;
        cout << "4. Remove key" << endl;
        cout << "5. Modify key" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){
            case 1: {
                print_first_100(hash_table);
                break;
            }
            case 2:{
                string key;
                cout << "Enter key to search: ";
                getline(cin, key);
                search_key(hash_table, key);
                break;

            }
            case 3:{
                string value;
                cout << "Enter value to add: ";
                getline(cin, value);
                add_key(hash_table, value);
                break;
            }
            case 4:{
                string key;
                cout << "Enter key to remove: ";
                getline(cin, key);
                remove_key(hash_table, key);
                break;
            }

            case 5:{
                string key;
                string old_value, new_value;
                cout << "Enter key to modify: ";
                getline(cin, key);
                cout << "Enter old value to replace: ";
                getline(cin, old_value);
                cout << "Enter new value: ";
                getline(cin, new_value);
                modify_key(hash_table, key, old_value, new_value);
                break;
            }

            case 6:{
                cout << "Exiting " << endl;
                break;
            }

            default: {
                cout << "Invalid" << endl;
                break;
            }
        } 
    } while (choice != 6);

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

