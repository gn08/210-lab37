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

void print_first_100(){
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

void search_key(){
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

void add_key(){
    int key = gen_hash_index(value);
    hash_table[key].push_back(value);
    cout << "The added value is: " << value << "- at index: " << key << endl;
}


void remove_key(){
    auto it = hash_table.find(key);
    if (it != hash_table.end()){
        hash_table.erase(it);
        cout << "Removed at index: " << key << endl;
    } else {
        cout << "The key: " << key << " was not found" << endl;
    }
}

void modify_key(){

}

int main() {
    string line;
    map<int, list<string> hash_table;
    int count = 0;

    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;

    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    string test_string;
    cout << "Enter string to calculate: ";
    getline(cin, test_string);

    int hash_index = gen_hash_index(test_string);
    cout << "The hash index of " << test_string << " is: " << hash_index << endl;
    
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

    for(const auto& pair : hash_table) {
        if (count >= 100) break;
        cout << "Hash index is: " << pair.first;
        for (const auto& code: pair.second){
            cout << code << endl;
        }
        count++;

    }
    
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

