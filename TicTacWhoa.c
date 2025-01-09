// Tic Tac Whoa game
// Game ends when one player gets a 3-in-a-row, if there are no more moves possible, or if either player types "quit"
#include <stdio.h>
#include <string.h>

// Function to get the position on the menu
int getPosition(char first, char second, int *row, int *col) 
{
    *row = '3' - second;            // Converts '1', '2', '3' to 2, 1, 0
    if (first == 'A')
    {
        *col = 3;
    }

    if (first == 'B')
    {
        *col = 7;
    }

    if (first == 'C')
    {
        *col = 11;
    }

    return 1; // Valid position
}


int main()
{
    // menu option
    char menu[4][13] = 
    {
        "3 ___|___|___",
        "2 ___|___|___",
        "1    |   |   ",
        "   A   B   C "
    };

    char input[20];
    char first;
    char second;
    int row;
    int column;
    char player = '1';
    char playerMove = 'X';
    int validInput = 1;
    int gameRunning = 1;
    
    while(gameRunning)
    {
        //print the grid
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                putchar(menu[i][j]);        // prints character at menu[i][j]
            }
            putchar('\n');                  // newline after each row
        }

        // ask for player move
        printf ("\nPlayer %c's Move: ", player);
        scanf("%s", input);

        // Check if input is "quit"
        if (strcmp(input, "quit") == 0) 
        {
            printf("Quiting\n");
            break;
        }

        // Check if input is 2 characters
        if(strlen(input) == 2)
        {
            first = input[0];
            second = input[1];

            // check if first input is valid
            if (first != 'A' && first != 'B' && first != 'C')
            {
                printf("\nInvalid move, please specify both column and row. \n");
                continue;
            }

            // check if second input is valid
            if (second != '1' && second != '2' && second != '3')
            {
                printf("\nInvalid move, please specify both column and row. \n");
                continue;
            }
        }

        // input is invalid
        else
        {
            printf("\nInvalid move, please specify both column and row. \n");
            continue;                     // skip the rest of the while loop and ask for input again
        }

        // when A1
        if (first == 'A' && second == '1')
        {
            getPosition(input[0], input[1], &row, &column);
            if (menu[row][column] == ' ')       // Check if the spot is empty
            { 
                menu[row][column] = playerMove; // Update with the symbol of the current player
                
                // switch player and player move
                player = (player == '1') ? '2' : '1';
                playerMove = (playerMove == 'X') ? 'O' : 'X';
            } 

            else 
            {
                printf("\nSpot already taken. Try again.\n");
            }        
        }
        
        // when A2 or A3
        if (first == 'A' && second == '2' || first == 'A' && second == '3' )
        {
            getPosition(input[0], input[1], &row, &column);
            if (menu[row][column] == '_')       // Check if the spot is empty
            { 
                menu[row][column] = playerMove; // Update with the symbol of the current player

                // switch player and player move
                player = (player == '1') ? '2' : '1';
                playerMove = (playerMove == 'X') ? 'O' : 'X';
            } 

            else 
            {
                printf("\nSpot already taken. Try again.\n");
            }        
        }

        // when B1
        if (first == 'B' && second == '1')
        {
            getPosition(input[0], input[1], &row, &column);
            if (menu[row][column] == ' ')       // Check if the spot is empty
            { 
                menu[row][column] = playerMove; // Update with the symbol of the current player

                // switch player and player move
                player = (player == '1') ? '2' : '1';
                playerMove = (playerMove == 'X') ? 'O' : 'X';
            } 

            else 
            {
                printf("\nSpot already taken. Try again.\n");
            }        
        }
        
        // when B2 or B3
        if (first == 'B' && second == '2' || first == 'B' && second == '3' )
        {
            getPosition(input[0], input[1], &row, &column);
            if (menu[row][column] == '_')       // Check if the spot is empty
            { 
                menu[row][column] = playerMove; // Update with the symbol of the current player

                // switch player and player move
                player = (player == '1') ? '2' : '1';
                playerMove = (playerMove == 'X') ? 'O' : 'X';
            } 

            else 
            {
                printf("\nSpot already taken. Try again.\n");
            }        
        }

        // when C1
        if (first == 'C' && second == '1')
        {
            getPosition(input[0], input[1], &row, &column);
            if (menu[row][column] == ' ')       // Check if the spot is empty
            { 
                menu[row][column] = playerMove; // Update with the symbol of the current player

                // switch player and player move
                player = (player == '1') ? '2' : '1';
                playerMove = (playerMove == 'X') ? 'O' : 'X';
            } 

            else 
            {
                printf("\nSpot already taken. Try again.\n");
            }        
        }
        
        // when C2 or C3
        if (first == 'C' && second == '2' || first == 'C' && second == '3' )
        {
            getPosition(input[0], input[1], &row, &column);
            if (menu[row][column] == '_')       // Check if the spot is empty
            { 
                menu[row][column] = playerMove; // Update with the symbol of the current player

                // switch player and player move
                player = (player == '1') ? '2' : '1';
                playerMove = (playerMove == 'X') ? 'O' : 'X';
            } 

            else 
            {
                printf("\nSpot already taken. Try again.\n");
            }        
        }

        // check if player 1 or 2 won
        for (int i = 0; i < 3; i++)  // Check for all rows
        {
            // Check if the positions in each row are all 'x'
            if (menu[i][3] == 'X' && menu[i][7] == 'X' && menu[i][11] == 'X')
            {
                // Print the grid
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 13; j++)
                    {
                        putchar(menu[i][j]);        // prints character at menu[i][j]
                    }
                    putchar('\n');                  // newline after each row
                }
                printf("\nPlayer 1 wins \n");
                return 0;
            }
            
            
            // Check if the positions in each row are all 'o'
            if (menu[i][3] == 'O' && menu[i][7] == 'O' && menu[i][11] == 'O')
            {
                // Print the grid
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 13; j++)
                    {
                        putchar(menu[i][j]);        // prints character at menu[i][j]
                    }
                    putchar('\n');                  // newline after each row
                }
                printf("\nPlayer 2 wins \n");
                return 0;
            }
        }

        // check if there are no more possible moves
        for (int i = 0; i < 3; i++)  // Check for all rows
        {
            // Check if  all the positions in row 1 are all 'x or o'
            if ((menu[0][3] == 'X' || menu[0][3] == 'O') && (menu[0][7] == 'X' || menu[0][7] == 'O') && (menu[0][11] == 'X' || menu[0][11] == 'O'))
            {
                // Check if all the positions in row 2 are all 'x or o'
                if ((menu[1][3] == 'X' || menu[1][3] == 'O') && (menu[1][7] == 'X' || menu[1][7] == 'O') && (menu[1][11] == 'X' || menu[1][11] == 'O'))
                {
                    // Check if all the positions in row 3 are all 'x or o'
                    if ((menu[2][3] == 'X' || menu[2][3] == 'O') && (menu[2][7] == 'X' || menu[2][7] == 'O') && (menu[2][11] == 'X' || menu[2][11] == 'O'))
                    {
                        // Print the grid
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 13; j++)
                            {
                                putchar(menu[i][j]);        // prints character at menu[i][j]
                            }
                            putchar('\n');                  // newline after each row
                        }
                        printf("\nThere are no more moves possible \n");
                        return 0;
                    }
                }
            }
        }
    }
    
    return 0;
}