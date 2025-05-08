#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter a line of text (press ENTER to finish):" << endl;

    // Reading characters using get() until newline
    while ((ch = cin.get()) != '\n') {
        // Writing characters using put()
        cout.put(ch);
    }

    cout << "\nEnd of unformatted I/O demo." << endl;
    return 0;
}
