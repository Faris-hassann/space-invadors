#include <iostream>
#include <string>
#include <windows.h>
#include <dos.h>
#include <conio.h>

using namespace std;

// global varibales
char board[100][100] = 
{
    "####################################################################################",
    "#                                                                                  #",
    "#    @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@       #",
    "#       @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@          #",
    "#          @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@             #",
    "#             @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@                #",
    "#                @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@                   #",
    "#                   @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@                      #",
    "#                      @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@ @@                         #",
    "#                         @@ @@ @@ @@ @@ @@ @@ @@ @@ @@                            #",
    "#                            @@ @@ @@ @@ @@ @@ @@ @@                               #",
    "#                               @@ @@ @@ @@ @@ @@                                  #",
    "#                                  @@ @@ @@ @@                                     #",
    "#                                     @@ @@                                        #",
    "#                                       @@                                         #",
    "#                                                                                  #",
    "#                                                                                  #",
    "#                                                                                  #",
    "#                                        &                                         #",
    "####################################################################################"
}; 

bool end_game = false;
int gamespeed = 100;
int score = 0;


// functions
void instructions();
void game_over();
void update_score();
void game();

int main()
{
    do{
        system("color a");
        system("cls");
		cout<<" ------------------------------------" << endl; 
        cout<<" |        space invadors Game        | " << endl; 
	    cout<<" ------------------------------------" << endl;
	    cout<<"1. Start Game\n";
		cout<<"2. Instructions\n";	 
		cout<<"3. Quit\n\n";
		cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') 
            game();
		else if( op=='2')
            instructions();
		else if( op=='3')
            exit(0);
		
	}while(1);  
    return 0;
}

void game()
{
    system("color a");
    while (end_game == false)
    {
        system("cls");

        // print the board
        for (int i = 0; i < 20; i++)
        {
            cout << board[i] << endl;
        }

        // movement of the ship
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                switch (board[i][j])
                {
                    case '&':
                        // movement of the ship to the left
                        if (GetAsyncKeyState(VK_LEFT) != false)
                        {
                            int newj = j-1;

                            switch (board[i][newj])
                            {
                                case ' ':
                                    board[i][j] = ' ';
                                    j--;
                                    board[i][newj] = '&';

                                break;
                            }        
                        }

                        // movement of the ship to the right
                        if (GetAsyncKeyState(VK_RIGHT) != false)
                        {
                            int newj = j+1;

                            switch (board[i][newj])
                            {
                                case ' ':
                                    board[i][j] = ' ';
                                    j++;
                                    board[i][newj] = '&';

                                break;
                            }        
                        }

                        // shooting a bullet
                        if (GetAsyncKeyState(VK_SPACE) != false)
                        {
                            // to get out of the ship
                            i--;
                            board[i][j] = '^';

                        }
                    break;

                    case '^':
                        // to move in the board
                        board[i][j] = ' ';
                        i--;
                        
                        // check if it hit the board or not
                        if (board[i][j] != '#' && board[i][j] != '@')
                        {
                            board[i][j] = '^';
                        }
                        else if (board[i][j] == '@')
                        {
                            board[i][j] = ' ';
                        }
                    break;
                }

                /*
                // check the game if you won
                if (board[i][j] != '@')
                {
                    cout << "you won!!" << endl;
                    end_game = true;
                    system("pause");
                     
                } */
            }   
        }

        Sleep(gamespeed);
    }
}

void instructions()
{
    // instructions
    system("cls");
    cout << "instructions" << endl;
    cout << "----------------------" << endl;
    cout << "press left arrow to move left." << endl;
    cout << "press right arrow to move right" << endl;
    cout << "press space button to fire a bullet" << endl;

    // geting back to the menu
    cout << "\n\n press any key to get back to the menu";
    getch();
}