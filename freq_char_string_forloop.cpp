#include <iostream>
using namespace std;

int main() {
    string str;
    int freq[256] = {0};

    cout << "Enter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); ++i) {
        freq[(unsigned char)str[i]]++;
    }

    cout << "\nCharacter frequencies:\n";
    for (int i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            cout << "'" << (char)i << "' = " << freq[i] << endl;
        }
    }

    return 0;
}
