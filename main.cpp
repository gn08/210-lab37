#include <iostream>
#include <string>
using namespace std;

int sum_ascii(const string& input){
    int sum = 0;
    for (char c : input){
        sum += (int)c;
    }
    return sum;
}



int main() {
    string line;
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;

    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;

    string test_string;
    cout << "Enter string to calculate: ";
    getline(cin, test_string);

    int ascii_sum = sum_ascii(test_string);
    cout << "The ascii sum of " << test_string << " is: " << ascii_sum << endl;
    
    ifstream file("lab-37-data.txt");
    if (!file.is_open){
        cout << "Error opening" << endl;
        return 1;
    }

    grand_total = 0;
    while (getline(file, line)){
        grand_total += sum_ascii(line);
    }

    file.close();
    cout << "Grand total for ascii is: " << grand_total << endl;

    return 0;
}

/* 
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

