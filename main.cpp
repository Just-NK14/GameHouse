#include <bits/stdc++.h>
#include <windows.h>

#include "XOplay.cpp"
#include "SudokoPlay.cpp"
#include "Chess.cpp"
#include "SnakeLadders.cpp"


using namespace std;

void setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
}

void logo()
{
    cout << "WELCOME! TO " << endl
         << endl;

    string logo[5] = {
        " GGGGGGG   AAAAAAA  M     M  EEEEEEE    H     H  OOOOOOO  U     U  SSSSSS  EEEEEEE",
        "G          A     A  MM   MM  E          H     H  O     O  U     U  S       E      ",
        "G   G G G  AAAAAAA  M M M M  EEEEE      HHHHHHH  O     O  U     U  SSSSSS  EEEEE  ",
        "G       G  A     A  M  M  M  E          H     H  O     O  U     U       S  E      ",
        " GGGGGGG   A     A  M     M  EEEEEEE    H     H  OOOOOOO   UUUUU   SSSSSS  EEEEEEE"};

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < logo[i].size(); ++j)
        {
            if (j <= 37)
            {
                setcolor(11);
            }
            else
            {
                setcolor(12);
            }
            cout << logo[i][j];
            setcolor(7);
        }
        cout << endl;
    }
    cout << endl;
}

void playTicTacTie()
{
    XOplay *game = new XOplay();
    game->menu();
    delete game;
}

int main()
{

    logo();
    int n;
    while (1)
    {
        cout << endl;
        cout << "******GAME HOUSE MENU******" << endl;
        cout << "1. Play Tic-Tac-Toe." << endl;
        cout << "2. Play Sudoko." << endl;
        cout << "3. Play Chess." << endl;
        cout << "4. Play Snake and Ladders." << endl;
        cout << "5. About Game House." << endl;
        cout << "6. Exit " << endl;

        cout << "Enter Choice : ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << endl;
            playTicTacTie();
            break;
        case 2:
            playSudoku();
            break;
        case 3:
            playChess();
            break;
        case 4:
            playsal();
            break;
        case 5:
            cout << "\nAbout Game House:" << endl;
            cout << "The Game House project's main objective was to create an entertaining platform." << endl;
            cout << "The key aim is to showcase how (OOP) principles can be seamlessly integrated." << endl;
            cout << "It offers users seamless transitions between different games." << endl;
            break;
        case 6:
            cout << "\nEXIT SUCCESSFULLY.";
            return 0;
            break;

        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    }

    return 0;
}
