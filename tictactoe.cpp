#include <bits/stdc++.h>
#include <cctype>
#include <unistd.h>

using namespace std;

// Class to play Tic-Tac-Toe Game
class XOplay
{
private:
    char board[3][3];                       //stores the game progress
    string player1, player2;                //names of the players
    char piece1, piece2;                    //pieces of the players
    vector<int> moves;                      //stores the last game played
    vector<char> plays;                     //stores the order of the pieces played
    bool gamePlayed;                        //stores wheter the players have played a game or not

public:
    XOplay();

    ~XOplay();

    void setNames();

    void displayBoard();

    void resetBoard();

    void displayBoardCordinates();

    void startGame();

    void updateCordinate(int n, int i);

    bool isNotLegal(int n);

    bool isWinner();

    bool isEqual(int a, int b, int c);

    void rewindGame();

    void replayGame();

    void wantToReplay();

    void menu();
};

XOplay::XOplay(){
    gamePlayed = false;
}

//Funtion to take input from the players
void XOplay::setNames(){
    cout << "Enter Player 1 Name: ";
    cin >> player1;
    cout << "Enter Your Piece character (Player 1): ";
    cin >> piece1;

    cout << "Enter Player 2 Name: ";
    cin >> player2;
label:
    cout << "Enter Your Piece character(Player 2): ";
    cin >> piece2;

    if (tolower(piece1) == tolower(piece2))
    {
        cout << "Choose a different piece from Player 1!" << endl;
        goto label;
    }
}

// Destructor
XOplay::~XOplay()
{   
    cout << endl;
    cout << "Game Over" << endl;
}

// Function to display the current state of the board
void XOplay::displayBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Function for resetting the board
void XOplay::resetBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '.';
}

// Function to show the players the coordinate of the board
void XOplay::displayBoardCordinates()
{
    cout << " " << 1 << " | " << 2 << " | " << 3 << endl;
    cout << "-----------" << endl;
    cout << " " << 4 << " | " << 5 << " | " << 6 << endl;
    cout << "-----------" << endl;
    cout << " " << 7 << " | " << 8 << " | " << 9 << endl;
}

// Function to start the game
void XOplay::startGame()
{
    if(gamePlayed!=true){
        setNames();
    }
    else{
       gamePlayed = false; 
    }
    resetBoard();
    int choice, temp = 0;
    cout << endl
         << "Cordinates on Board" << endl;
    displayBoardCordinates();
    cout << "Enter the coordinate number to make your move." << endl
         << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << endl;
        displayBoard();
        cout << endl;
        (i % 2 == 0) ? cout << "[" << piece1 << "] " << player1 << "'s Turn: " : cout << "[" << piece2 << "] " << player2 << "'s Turn: ";
        cin >> choice;

        if (isNotLegal(choice))
        {
            cout << "Invalid move. Try again." << endl;
            cout << "Choose Another Square." << endl
                 << endl;
            i--;
            continue;
        }

        updateCordinate(choice, i);

        moves.push_back(choice);

        if (isWinner())
        {
            string winner = (i % 2 == 0) ? player1 : player2;
            cout << "\nCongratulations! " << winner << " You Have Won!" << endl;
            temp++;
            break;
        }
    }
    cout << endl;
    displayBoard();

    if (temp == 0)
    {
        cout << "\nThe Game was a Draw" << endl;
    }
    cout<<endl;
    gamePlayed = true;
}

// Function To update the X/O board according to the player input
void XOplay::updateCordinate(int n, int i)
{
    char c = (i % 2 == 0) ? piece1 : piece2;
    board[n / 3][n % 3 - 1] = c;
    plays.push_back(c);
}

// To check if the move by the player is Valid or Not
bool XOplay::isNotLegal(int n)
{
    return !(n >= 1 && n <= 9) || board[n / 3][n % 3 - 1] == piece1 || board[n / 3][n % 3 - 1] == piece2;
}

// To check if any player has won the game
bool XOplay::isWinner()
{
    return isEqual(1, 2, 3) || isEqual(7, 8, 9) || isEqual(4, 5, 6) || isEqual(1, 4, 7) || isEqual(2, 5, 8) || isEqual(3, 6, 9) || isEqual(1, 5, 9) || isEqual(3, 5, 7);
}

// Function to see if 3 coordinates on the Board are equal
bool XOplay::isEqual(int a, int b, int c)
{
    if (board[a / 3][a % 3 - 1] == '.' || board[b / 3][b % 3 - 1] == '.' || board[c / 3][c % 3 - 1] == '.')
    {
        return false;
    }

    return (board[a / 3][a % 3 - 1] == board[b / 3][b % 3 - 1]) && (board[a / 3][a % 3 - 1] == board[c / 3][c % 3 - 1]);
}

// Function to rewind the game u have played
void XOplay::rewindGame()
{
    if (!gamePlayed)
    {
        cout << "Play a game to rewind it" << endl;
        return;
    }

    for (int i = 0; i < moves.size(); i++)
    {
        board[moves[i] / 3][moves[i] % 3 - 1] = plays[i];
    }

    cout << "\nGame Rewinding: " << endl
         << endl;
    displayBoard();
    cout << endl;

    for (int i = moves.size() - 1; i >= 0; i--)
    {
        sleep(4);
        board[moves[i] / 3][moves[i] % 3 - 1] = '.';
        displayBoard();
        cout << endl;
    }
}

// Function to replay the game
void XOplay::replayGame()
{

    if (!gamePlayed)
    {
        cout << "Play a game to replay it" << endl;
        return;
    }
    resetBoard();
    cout << "\nGame Replaying: " << endl
         << endl;
    displayBoard();
    cout << endl;

    for (int i = 0; i < moves.size(); i++)
    {
        sleep(4);
        board[moves[i] / 3][moves[i] % 3 - 1] = plays[i];
        displayBoard();
        cout << endl;
    }
}


//Function to Replay the game
void XOplay::wantToReplay()
{
    if (!gamePlayed)
    {
        cout << "Play a game to play again" << endl;
        return;
    }
    
    string abc;
    char xyz;
    cout << "Wanna Play again?" << endl;
    cout << "Enter (Yes/No) : ";
    cin >> abc;
    if (abc == "Yes")
    {
        abc = player1;
        player1 = player2;
        player2 = abc;

        xyz = piece1;
        piece1 = piece2;
        piece2 = xyz;
        gamePlayed = true;
        moves.clear();
        plays.clear();
        startGame();
    }
    else
    {
        cout << "Thanks for playing" << endl;
    }
}

//Funtion to display menu for the game
void XOplay:: menu(){

    int n;

    while (1)
    {
        cout<<"1. Start the Game"<<endl;
        cout<<"2. Replay your previous game"<<endl;
        cout<<"3. Rewind your previous game"<<endl;
        cout<<"4. You want to Play Again?"<<endl;
        cout<<"5. Exit \n\n";

        cout<<"Enter : ";
        cin>>n;
        switch (n)
        {
        case 1:
            startGame();
            gamePlayed = false;
            break;
        case 2:
            replayGame();
            break;
        case 3:
            rewindGame();
            break;
        case 4:
            wantToReplay();
            break;
        case 5:
            return;
            break;
        
        default:
        cout<<"Invalid Choice!"<<endl;
            break;
        }
    }
    
}

int main()
{
    XOplay obj;
    obj.menu();

    return 0;
}
