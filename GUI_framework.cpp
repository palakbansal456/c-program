#include <iostream>
#include <vector>
#include <memory>  // For smart pointers

using namespace std;

// Base class representing a generic GUI component
class GUIComponent {
public:
    virtual void render() = 0;  // Pure virtual function to render the component
    virtual void click() = 0;   // Pure virtual function to handle click event
    virtual ~GUIComponent() {}   // Virtual destructor for proper cleanup
};

// Derived class representing a Button
class Button : public GUIComponent {
public:
    void render() override {
        cout << "Rendering Button\n";
    }

    void click() override {
        cout << "Button clicked!\n";
    }
};

// Derived class representing a TextField
class TextField : public GUIComponent {
public:
    void render() override {
        cout << "Rendering TextField\n";
    }

    void click() override {
        cout << "TextField clicked! Enter text...\n";
    }
};

// Derived class representing a Label
class Label : public GUIComponent {
public:
    void render() override {
        cout << "Rendering Label\n";
    }

    void click() override {
        cout << "Label clicked!\n";
    }
};

// GUI Manager to manage and render all components
class GUIManager {
private:
    vector<shared_ptr<GUIComponent>> components;  // Use shared pointers to handle memory management

public:
    // Add a component to the GUI
    void addComponent(shared_ptr<GUIComponent> component) {
        components.push_back(component);
    }

    // Render all components
    void renderAll() {
        for (auto& component : components) {
            component->render();  // Polymorphic call
        }
    }

    // Handle click event on all components
    void handleClicks() {
        for (auto& component : components) {
            component->click();  // Polymorphic call
        }
    }
};

int main() {
    // Create a GUI manager
    GUIManager guiManager;

    // Add different types of components to the GUI manager
    guiManager.addComponent(make_shared<Button>());
    guiManager.addComponent(make_shared<TextField>());
    guiManager.addComponent(make_shared<Label>());

    // Render all components (polymorphic call to render)
    cout << "Rendering all components:\n";
    guiManager.renderAll();

    // Handle clicks for all components (polymorphic call to click)
    cout << "\nHandling clicks on all components:\n";
    guiManager.handleClicks();

    return 0;
}
