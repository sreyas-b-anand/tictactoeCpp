#include <iostream>
#include <cstring>

#define RESET "\x1b[0m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"

bool conditionChecker();
void currentState();

using namespace std;

string ar[3][3] = {{"[   ]", "[   ]", "[   ]"},
                   {"[   ]", "[   ]", "[   ]"},
                   {"[   ]", "[   ]", "[   ]"}};

string player1, player2;
string name1, name2;
char player;
int m = 0;

void clearBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ar[i][j] = "[   ]";
        }
    }
    m = 0;
}

bool getPlayerInput(int &i, int &j, int playerNum) {
    while (true) {
        cout << "Player " << playerNum << " to play\n";
        cout << "Input the position (row and column): ";
        cin >> i >> j;

        i--;
        j--; 

        if (ar[i][j] != player1 && ar[i][j] != player2) {
            return true; 
        } else {
            cout << BLUE << "Error: Position already taken. Try again." << RESET << endl;
        }
    }
}

int main() {
    int i, j;
    bool winner = false;

    cout << CYAN << "Welcome to TIC TAC TOE game\n\n";
    cout << "Enter player 1's name: " << RESET;
    cin >> name1;
    cout << CYAN << "\nEnter player 2's name: " << RESET;
    cin >> name2;

    cout << "\nChoose either X or O: ";
    cin >> player;

    if (player == 'X' || player == 'x') {
        player1 = "[ X ]";
        player2 = "[ O ]";
    } else if (player == 'O' || player == 'o') {
        player1 = "[ O ]";
        player2 = "[ X ]";
    } else {
        cout << "Error: Invalid choice. Exiting...\n\n";
        return 1;
    }

    cout << "\n\n" << name1 << " is player 1 and plays with " << player1;
    cout << "\n" << name2 << " is player 2 and plays with " << player2;

    cout << "\n\nInstructions";
    cout << CYAN << "\n\nTo input the character in position a22,\n\t" << "Enter 2 2\n" << RESET;
    cout << "\n\nSimilarly, input the required positions throughout the game \n\n ";

    cout << CYAN << "\n\nCURRENT STATE and POSITIONS\n" << RESET;
    cout << "\n[a11] [a12] [a13]\n"
         << "[a21] [a22] [a23]\n"
         << "[a31] [a32] [a33] \n\n";

    cout << CYAN << "\n\nLET THE GAME BEGIN......\n" << RESET;

    while (!winner) {
        // Player 1's turn
        if (getPlayerInput(i, j, 1)) {
            ar[i][j] = player1;
            m++;
        }
        currentState();
        if (conditionChecker()) {
            cout << YELLOW << "\n" << name1 << " is the winner!" << endl << RESET;
            cout << "\nWELL PLAYED\n";
            winner = true;
            break;
        }
        if (m == 9) {
            cout << YELLOW << "\nThe game is drawn" << RESET << endl;
            cout << "\nWELL PLAYED" << endl;
            break;
        }

        // Player 2's turn
        if (getPlayerInput(i, j, 2)) {
            ar[i][j] = player2;
            m++;
        }
        currentState();
        if (conditionChecker()) {
            cout << YELLOW << "\n" << name2 << " is the winner!" << endl << RESET;
            cout << "\nWELL PLAYED\n";
            winner = true;
            break;
        }
    }

    return 0;
}

bool conditionChecker() {
    for (int i = 0; i < 3; ++i) {
        if (ar[i][0] == ar[i][1] && ar[i][1] == ar[i][2] && ar[i][0] != "[   ]") {
            return true;
        }
        if (ar[0][i] == ar[1][i] && ar[1][i] == ar[2][i] && ar[0][i] != "[   ]") {
            return true;
        }
    }
    if (ar[0][0] == ar[1][1] && ar[1][1] == ar[2][2] && ar[0][0] != "[   ]") {
        return true;
    }
    if (ar[0][2] == ar[1][1] && ar[1][1] == ar[2][0] && ar[0][2] != "[   ]") {
        return true;
    }
    return false;
}

void currentState() {
    cout << MAGENTA << "\nCurrent state \n" << RESET;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ar[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

