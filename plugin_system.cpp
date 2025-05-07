#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Base class for Plugin
class Plugin {
public:
    // Virtual destructor for proper cleanup in derived classes
    virtual ~Plugin() {}

    // Virtual function that derived classes must implement
    virtual void execute() = 0;
};

// PluginA - derived class from Plugin
class PluginA : public Plugin {
public:
    void execute() override {
        cout << "PluginA is executing...\n";
    }
};

// PluginB - derived class from Plugin
class PluginB : public Plugin {
public:
    void execute() override {
        cout << "PluginB is executing...\n";
    }
};

// PluginManager class to load and manage plugins
class PluginManager {
private:
    vector<shared_ptr<Plugin>> plugins;  // Vector to hold loaded plugins

public:
    // Function to load a plugin
    void loadPlugin(shared_ptr<Plugin> plugin) {
        plugins.push_back(plugin);
    }

    // Function to execute all loaded plugins
    void executePlugins() {
        cout << "\nExecuting plugins:\n";
        for (auto& plugin : plugins) {
            plugin->execute();  // Polymorphic call
        }
    }
};

// Main application function
int main() {
    PluginManager pluginManager;

    // Menu to load and execute plugins
    int choice;
    do {
        cout << "\nPlugin System Menu:\n";
        cout << "1. Load PluginA\n";
        cout << "2. Load PluginB\n";
        cout << "3. Execute All Plugins\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create and load PluginA
                auto pluginA = make_shared<PluginA>();
                pluginManager.loadPlugin(pluginA);
                cout << "PluginA loaded.\n";
                break;
            }
            case 2: {
                // Create and load PluginB
                auto pluginB = make_shared<PluginB>();
                pluginManager.loadPlugin(pluginB);
                cout << "PluginB loaded.\n";
                break;
            }
            case 3:
                // Execute all loaded plugins
                pluginManager.executePlugins();
                break;
            case 4:
                cout << "Exiting plugin system...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
