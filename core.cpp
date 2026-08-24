#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    char runAgain;

    do {
        vector<string> options;
        string option;
    
        cout << "Enter your options one at a time.\n";
        cout << "Type \"done\" when you are finished.\n\n";

        while(true){
            cout << "Enter an option: ";
            getline(cin, option);

            if (option == "done"){
                if(options.size() >= 3){
                    break;
                }

                cout << "Please enter at least 3 options first.\n";
            }

            else if (option.empty()){
                cout << "An option cannot be empty.\n";
            }

            else {
                options.push_back(option);
            }
        }

        int randomIndex = rand() % options.size();

        cout << "\n Selection Option: \n";
        cout << ">>> " << options[randomIndex] << " <<<\n";

        cout << "\nUse the randomizer again? (y/n): ";
        cin >> runAgain;
        cin.ignore();

        } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}