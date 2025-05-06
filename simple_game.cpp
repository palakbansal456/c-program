#include <iostream>
#include <cstdlib>
#include <ctime>

class Game {
private:
    int playerHealth;
    int enemyHealth;
    int playerScore;
    int maxHealth;
    int maxEnemyHealth;

public:
    // Constructor: Initialize player and enemy health, and score
    Game(int maxHealth = 100, int maxEnemyHealth = 100) {
        this->maxHealth = maxHealth;
        this->maxEnemyHealth = maxEnemyHealth;
        playerHealth = maxHealth;
        enemyHealth = maxEnemyHealth;
        playerScore = 0;
        std::srand(std::time(0)); // Initialize random number generator
    }

    // Function to simulate player's attack on the enemy
    void attack() {
        if (enemyHealth <= 0) {
            std::cout << "Enemy is already defeated!" << std::endl;
            return;
        }

        int damage = std::rand() % 20 + 10; // Random damage between 10 and 30
        enemyHealth -= damage;
        if (enemyHealth < 0) enemyHealth = 0;

        playerScore += 10; // Gain 10 points for attacking

        std::cout << "You attack the enemy for " << damage << " damage!" << std::endl;
        std::cout << "Enemy Health: " << enemyHealth << "/" << maxEnemyHealth << std::endl;
    }

    // Function to simulate player's healing action
    void heal() {
        if (playerHealth >= maxHealth) {
            std::cout << "You are already at full health!" << std::endl;
            return;
        }

        int healAmount = std::rand() % 20 + 10; // Random healing between 10 and 30
        playerHealth += healAmount;
        if (playerHealth > maxHealth) playerHealth = maxHealth;

        playerScore += 5; // Gain 5 points for healing

        std::cout << "You heal yourself for " << healAmount << " health!" << std::endl;
        std::cout << "Player Health: " << playerHealth << "/" << maxHealth << std::endl;
    }

    // Function to simulate player's defense action
    void defend() {
        if (enemyHealth <= 0) {
            std::cout << "Enemy is already defeated!" << std::endl;
            return;
        }

        int defense = std::rand() % 10 + 5; // Random defense value between 5 and 15
        int damage = std::rand() % 20 + 10; // Random attack value between 10 and 30
        damage -= defense;

        if (damage < 0) damage = 0; // If defense is greater than the attack, no damage

        playerHealth -= damage;
        if (playerHealth < 0) playerHealth = 0;

        std::cout << "You defend against the enemy attack and take " << damage << " damage!" << std::endl;
        std::cout << "Player Health: " << playerHealth << "/" << maxHealth << std::endl;
    }

    // Function to simulate the enemy's action (random attack)
    void enemyAction() {
        if (enemyHealth <= 0) {
            std::cout << "The enemy is already defeated!" << std::endl;
            return;
        }

        int action = std::rand() % 3; // Random action: 0 = Attack, 1 = Heal, 2 = Defend

        if (action == 0) {
            int damage = std::rand() % 20 + 10; // Random enemy damage between 10 and 30
            playerHealth -= damage;
            if (playerHealth < 0) playerHealth = 0;
            std::cout << "Enemy attacks you for " << damage << " damage!" << std::endl;
        } else if (action == 1) {
            int healAmount = std::rand() % 20 + 10; // Random healing between 10 and 30
            enemyHealth += healAmount;
            if (enemyHealth > maxEnemyHealth) enemyHealth = maxEnemyHealth;
            std::cout << "Enemy heals itself for " << healAmount << " health!" << std::endl;
        } else {
            std::cout << "Enemy defends itself!" << std::endl;
        }

        std::cout << "Player Health: " << playerHealth << "/" << maxHealth << std::endl;
    }

    // Function to check if the game is over
    bool isGameOver() {
        if (playerHealth <= 0) {
            std::cout << "Game Over! You were defeated by the enemy!" << std::endl;
            return true;
        } else if (enemyHealth <= 0) {
            std::cout << "You won the game! The enemy is defeated!" << std::endl;
            return true;
        }
        return false;
    }

    // Function to display current status (Health, Score, etc.)
    void displayStatus() {
        std::cout << "------------------------" << std::endl;
        std::cout << "Player Health: " << playerHealth << "/" << maxHealth << std::endl;
        std::cout << "Enemy Health: " << enemyHealth << "/" << maxEnemyHealth << std::endl;
        std::cout << "Player Score: " << playerScore << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

// Main function to run the game
int main() {
    Game game;

    // Start the game loop
    while (!game.isGameOver()) {
        game.displayStatus();

        std::cout << "\nChoose an action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Heal\n";
        std::cout << "3. Defend\n";
        std::cout << "4. Enemy Action\n";
        std::cout << "Enter your choice (1-4): ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                game.attack();
                break;
            case 2:
                game.heal();
                break;
            case 3:
                game.defend();
                break;
            case 4:
                game.enemyAction();
                break;
            default:
                std::cout << "Invalid choice! Try again.\n";
                continue;
        }

        // After player's action, the enemy takes a turn
        if (!game.isGameOver()) {
            game.enemyAction();
        }
    }

    return 0;
}
