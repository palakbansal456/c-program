#include <iostream>
using namespace std;

class Logger {
private:
    string message;

public:
    // Constructor to set a message
    Logger(const string& msg) {
        message = msg;
        cout << "Logger created: " << message << endl;
    }

    // Destructor to log when object is destroyed
    ~Logger() {
        cout << "Logger destroyed: " << message << endl;
    }
};

int main() {
    {
        Logger log1("Starting process...");
        Logger log2("Opening file...");
    } // log1 and log2 go out of scope here, destructors are called

    cout << "End of main function." << endl;

    return 0;
}
