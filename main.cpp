#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
using namespace std;

int gen_hash_index(const string& input){
    int sum = 0;
    for (char c : input){
        sum += (int)c;
    }
    return sum % 1000;
}

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

void search_key(const map<int, list<string>>& hash_table, int key){
    auto it = hash_table.find(key);
    if ( it != hash_table.end()){
        cout << "Hash Index: " << key << " [ ";
        for (const auto& code : it->second){
            cout << code << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "Key: " << key << "- not found in the hash table" << endl;
    }
}

void add_key(map<int, list<string>>& hash_table, const string& value){
    int key = gen_hash_index(value);
    hash_table[key].push_back(value);
    cout << "The added value is: " << value << "- at index: " << key << endl;
}


void remove_key(map<int, list<string>>& hash_table, int key){
    auto it = hash_table.find(key);
    if (it != hash_table.end()){
        hash_table.erase(it);
        cout << "Removed at index: " << key << endl;
    } else {
        cout << "The key: " << key << " was not found" << endl;
    }
}

void modify_key(map<int, list<string>>& hash_table, int key, const string& old_value, const string& new_value){
    auto it = hash_table.find(key);
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

        switch(choice){
            case 1: {
                print_first_100(hash_table);
                break;
            }
            case 2:{
                int key;
                cout < "Enter key to search: ";
                cin >> key;
                search_key(hash_table, key);
                break;
            }
            case 3:{
                string value;
                cout << "Enter value to add: ";
                cin.ignore();
                getline(cin, value);
                add_key(hash_table, value);
                break;
            }
            case 4:{
                int key;
                cout << "Enter key to remove: ";
                cin >> key;
                remove_key(hash_table, key);
                break;
            }

            case 5:{
                int key;
                string old_value, new_value;
                cout << "Enter key to modify: ";
                cin >> key;
                cin.ignore();
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
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

