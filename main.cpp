#include <iostream>
#include <string>
using namespace std;

int gen_hash_index(const string& input){
    int sum = 0;
    for (char c : input){
        sum += (int)c;
    }
    return sum % 1000;
}



int main() {
    string line;
    map<int, list<string>> hash_table;
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

    }

    file.close();
    
    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

