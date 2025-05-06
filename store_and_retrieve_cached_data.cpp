#include <iostream>
#include <unordered_map>
#include <string>

class Cache {
private:
    // A map to store the cached data (key -> value)
    std::unordered_map<std::string, std::string> cache;

public:
    // Store data in the cache
    void storeData(const std::string& key, const std::string& value) {
        cache[key] = value;
        std::cout << "Data stored: Key = " << key << ", Value = " << value << std::endl;
    }

    // Retrieve data from the cache
    std::string retrieveData(const std::string& key) {
        if (cache.find(key) != cache.end()) {
            std::cout << "Data retrieved: Key = " << key << ", Value = " << cache[key] << std::endl;
            return cache[key];
        } else {
            std::cout << "Data not found for Key = " << key << std::endl;
            return "";  // Return an empty string if not found
        }
    }

    // Remove data from the cache
    void removeData(const std::string& key) {
        if (cache.find(key) != cache.end()) {
            cache.erase(key);
            std::cout << "Data removed for Key = " << key << std::endl;
        } else {
            std::cout << "Data not found for Key = " << key << ", cannot remove" << std::endl;
        }
    }

    // Clear all cached data
    void clearCache() {
        cache.clear();
        std::cout << "Cache cleared!" << std::endl;
    }

    // Display the current cache contents
    void displayCache() {
        if (cache.empty()) {
            std::cout << "Cache is empty!" << std::endl;
        } else {
            std::cout << "Current cache contents:" << std::endl;
            for (const auto& pair : cache) {
                std::cout << "Key = " << pair.first << ", Value = " << pair.second << std::endl;
            }
        }
    }
};

// Main function to test Cache class
int main() {
    Cache myCache;

    // Store some data in the cache
    myCache.storeData("user1", "John Doe");
    myCache.storeData("user2", "Jane Smith");

    // Retrieve data from the cache
    myCache.retrieveData("user1");
    myCache.retrieveData("user2");
    myCache.retrieveData("user3");  // Non-existent key

    // Remove some data from the cache
    myCache.removeData("user2");
    myCache.removeData("user3");  // Non-existent key

    // Display current cache contents
    myCache.displayCache();

    // Clear the cache
    myCache.clearCache();
    myCache.displayCache();

    return 0;
}
