#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// ANSI COLOR CODES FOR TERMINAL STYLING.
const string RESET       = "\033[0m";
const string BOLD        = "\033[1m";
const string GOLD        = "\033[38;5;220m"; // Metallic Gold for borders/lines
const string DEEP_BROWN  = "\033[38;5;130m"; // Warm Brown/Earth for title & instructions
const string AMBER_GLOW  = "\033[38;5;214m"; // Amber Glow for list prompts
const string RUBY_RED    = "\033[38;5;196m"; // Rich Crimson Ruby for selected winner
const string DARK_ERROR  = "\033[38;5;124m"; // Dark Ruby Red for warnings
const string SPACE       = "                                   ";

int main(){
    srand(time(0));

    char runAgain;
    bool isFirstRun = true;

    do {
        vector<string> options;
        string option;

        if (isFirstRun){
            cout << GOLD << SPACE << "====================================================\n" << RESET;
            cout << BOLD << SPACE << DEEP_BROWN << "                     POP-UP PODIUM                  \n" << RESET;
            cout << GOLD  << SPACE<< "====================================================\n" << RESET;
            cout << DEEP_BROWN  << SPACE<< "        Press " << BOLD << "[ENTER]" << RESET << DEEP_BROWN << " when you are finished. \n" << RESET;
            cout << GOLD << SPACE << "----------------------------------------------------\n\n" << RESET;
        } else {
            cout << GOLD << SPACE << "====================================================\n" << RESET;
            cout << BOLD << SPACE << DEEP_BROWN << "                ANOTHER TREASURE DRAW               \n" << RESET;
            cout << GOLD << SPACE << "====================================================\n" << RESET;
        }

        cout << BOLD << DEEP_BROWN << SPACE << "Add a new gem to the treasure hoard.\n" <<RESET;

        while(true){
            cout << BOLD << AMBER_GLOW << SPACE << "  [" << options.size() + 1 << "]" << RESET << " ";
            getline(cin, option);

            if (option.empty()){
                if(options.size() >= 2){
                    break;
                }

                cout << DARK_ERROR << "\n" << SPACE << "          A lone pebble is no treasure hoard.\n\n" << RESET;
            }

            else {
                options.push_back(option);
            }
        }

        int randomIndex = rand() % options.size();

        cout << GOLD << "\n"  << SPACE << "====================================================\n";
        cout << BOLD << DEEP_BROWN << "\n" << SPACE << "                The choice is made!\n" << SPACE << "   You now bear the perfect trophy from the vault.\n";
        cout << GOLD << "\n"  << SPACE << "====================================================\n\n" << RESET;
        cout << BOLD << RUBY_RED << SPACE << "      >>>            " << options[randomIndex] << "             <<<\n" << RESET;

        cout << BOLD << DEEP_BROWN << "\n" << SPACE << "   Shall we roll the dice once more? (y/n): " << RESET;
        cin >> runAgain;
        cin.ignore();
        cout << "\n\n";

        isFirstRun = false;

        } while (runAgain == 'y' || runAgain == 'Y');
    
    return 0;
    
}