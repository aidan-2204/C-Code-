#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono> 

using namespace std;
using namespace std::chrono;

void playGame() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to Higher or Lower!" << endl;
    cout << "I have chosen a number between 1 & 100. Can you guess it?" << endl;

    do {
        cout << "Which number do you think it is?: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
            cout << "Try level 2 or play again" << endl;

         
            ofstream outFile("scores.txt", ios::app);
            if (outFile.is_open()) {
                outFile << "Level 1: " << attempts << " attempts" << endl;
                outFile.close();
                cout << "Your score has been saved." << endl;
            } else {
                cout << "Unable to open file for writing." << endl;
            }
        }
    } while (guess != secretNumber);
}


void playGameLevel2() {
    srand(time(0)); 

    int secretNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 5;

    cout << "Welcome to Level 2 of Higher or Lower!" << endl;
    cout << "You have " << MAX_ATTEMPTS << " attempts to guess the number." << endl;
    cout << "I have chosen a number between 1 & 100. Can you guess it?" << endl;

    do {
        cout << "Attempts left: " << MAX_ATTEMPTS - attempts << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
            cout << "Try level 3 or play again" << endl;

            
            ofstream outFile("scores.txt", ios::app);
            if (outFile.is_open()) {
                outFile << "Level 2: " << attempts << " attempts" << endl;
                outFile.close();
                cout << "Your score has been saved." << endl;
            } else {
                cout << "Unable to open file for writing." << endl;
            }
            return;
        }
    } while (attempts < MAX_ATTEMPTS);

    cout << "Uh oh, you have used all your attempts. The correct number was: " << secretNumber << "Try again next time!" << endl;
}


void playGameLevel3() {
    srand(time(0)); 

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    const int TIME_LIMIT = 30;

    cout << "Welcome to Level 3 of Higher or Lower!" << endl;
    cout << "But wait, this time you have just 30 seconds to guess." << endl;
    cout << "Lets see if you can beat me this time" << endl;
    cout << "I have chosen a number between 1 & 100. Can you guess it?" << endl;

    auto startTime = steady_clock::now();

    do {
        auto currentTime = steady_clock::now();
        auto elapsed = duration_cast<seconds>(currentTime - startTime).count(); 

        if (elapsed >= TIME_LIMIT) {
            cout << "Time's up! You didn't guess the number in time." << endl;
            return;
        }

        cout << "You have " << TIME_LIMIT - elapsed << " seconds left on the clock" << endl;
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low!" << endl;
        } else if (guess > secretNumber) {
            cout << "Too high!" << endl;
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
            cout << "You are too good at this game!" << endl;

            ofstream outFile("scores.txt", ios::app);
            if (outFile.is_open()) {
                outFile << "Level 3: " << attempts << " attempts" << endl;
                outFile.close();
                cout << "Your score has been saved." << endl;
            } else {
                cout << "Unable to open file for writing." << endl;
            }
            return;
        }
    } while (true);
}

int main() {
    char choice;

    do {
        cout << "Welcome to the amazing game of Higher or Lower!" << endl;
        cout << "Main Menu:" << endl;
        cout << "Play the game or exit?" << endl;
        cout << "1. Higher or Lower (normal)" << endl;
        cout << "2. Higher or Lower (difficult)" << endl;
        cout << "3. Higher or Lower (very difficult)" << endl;
        cout << "4. Exit" << endl;
        cout << "What would you like to do?: ";
        cin >> choice;

        switch (choice) {
            case '1':
                playGame();
                break;
            case '2':
                playGameLevel2();
                break;
            case '3':
                playGameLevel3();
                break;
            case '4':
                cout << "See you next time!" << endl;
                break;
            default:
                cout << "That is not an option. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != '4');

    return 0;
}

