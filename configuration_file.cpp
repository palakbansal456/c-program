#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to read the configuration file and store key-value pairs
bool readConfigFile(const string& filename, unordered_map<string, string>& config) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open configuration file." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        // Skip empty lines and comments (lines starting with #)
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Find the position of '=' and split the line into key and value
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            config[key] = value;
        }
    }

    file.close();
    return true;
}

// Function to process the configuration and control program behavior
void processConfig(const unordered_map<string, string>& config) {
    // Retrieve the max_attempts setting
    int max_attempts = 3;  // Default value
    if (config.find("max_attempts") != config.end()) {
        max_attempts = stoi(config.at("max_attempts"));
    }

    // Retrieve the enable_feature_x setting
    bool enable_feature_x = false;  // Default value
    if (config.find("enable_feature_x") != config.end()) {
        enable_feature_x = (config.at("enable_feature_x") == "true");
    }

    // Print out the settings
    cout << "Max attempts: " << max_attempts << endl;
    cout << "Feature X enabled: " << (enable_feature_x ? "Yes" : "No") << endl;

    // Control behavior based on settings
    if (enable_feature_x) {
        cout << "Feature X is now active!" << endl;
    } else {
        cout << "Feature X is disabled." << endl;
    }

    // Simulate the behavior based on max_attempts
    for (int i = 1; i <= max_attempts; ++i) {
        cout << "Attempt " << i << "/" << max_attempts << endl;
        // Simulate some action here (e.g., login, task execution, etc.)
    }
}

int main() {
    unordered_map<string, string> config;
    string config_filename = "config.txt";

    // Read the configuration file
    if (!readConfigFile(config_filename, config)) {
        return 1; // Error occurred while reading the file
    }

    // Process the configuration settings and control program behavior
    processConfig(config);

    return 0;
}
