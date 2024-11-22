#include <iostream>
using namespace std;
int rows = 6;
int columns = 7;
string symbol = "-";
int count2 = 0;

string symbolplayer1 = "X";
string symbolplayer2 = "O";

string matrix[6][7];

bool columnfull(int columndrop)
{
    return matrix[0][columndrop - 1] != symbol;
}

bool gameWin=false;

void gamewinningcheck(int columndrop)
{
    int row = -1;
    
    for (int j = rows - 1; j >= 0; j--)
    {
        if (matrix[j][columndrop - 1] == symbolplayer1 || matrix[j][columndrop - 1] == symbolplayer2)
        {
            row = j;
            break;
        }
    }
    
    //for horizontal check
    for (int i = 0; i < columns - 3; i++)  
    {
        if (matrix[row][i] == matrix[row][i + 1] && matrix[row][i] == matrix[row][i + 2] && matrix[row][i] == matrix[row][i + 3])
        {
            if (matrix[row][i] == symbolplayer1)
            {
                cout << "Game won by player 1!" << endl;
                 gameWin=true;
            }
            else if (matrix[row][i] == symbolplayer2)
            {
                cout << "Game won by player 2!" << endl;
                gameWin=true;
            }
        }
    }

    //now for vertical check
    for (int i = rows-1; i >= rows-3; i--)
    {
        if (matrix[i][columndrop-1] == matrix[i-1][columndrop-1] && matrix[i-1][columndrop-1] == matrix[i-2][columndrop-1] && matrix[i-2][columndrop-1] == matrix[i-3][columndrop-1])
        {
            if (matrix[i][columndrop-1]==symbolplayer1)
            {
               cout << "Game won by player 1!" << endl;
                gameWin=true;
            }
            else if (matrix[i][columndrop-1]==symbolplayer2)
            {
                 cout << "Game won by player 2!" << endl;
                 gameWin=true;
            }
            
            
        }
        
    }
    //for diagonal check
    // For diagonal check: bottom-right to top-left (↖)
for (int i = rows - 1; i >= 3; i--)  // Ensure there's space for 4 diagonally
{
    for (int j = columns - 1; j >= 3; j--)  // Ensure there's space for 4 diagonally
    {
        if (matrix[i][j] == matrix[i - 1][j - 1] && matrix[i][j] == matrix[i - 2][j - 2] && matrix[i][j] == matrix[i - 3][j - 3])
        {
            if (matrix[i][j] == symbolplayer1)
            {
                cout << "Game won by player 1!" << endl;
                gameWin = true;
                return;  // Exit the function once a winner is found
            }
            else if (matrix[i][j] == symbolplayer2)
            {
                cout << "Game won by player 2!" << endl;
                gameWin = true;
                return;  // Exit the function once a winner is found
            }
        }
    }
}
// For diagonal check: bottom-right to top-left (↖)
for (int i = rows - 1; i >= 3; i--)  // Ensure there's space for 4 diagonally
{
    for (int j = columns - 1; j >= 3; j--)  // Ensure there's space for 4 diagonally
    {
        if (matrix[i][j] == matrix[i - 1][j - 1] && matrix[i][j] == matrix[i - 2][j - 2] && matrix[i][j] == matrix[i - 3][j - 3])
        {
            if (matrix[i][j] == symbolplayer1)
            {
                cout << "Game won by player 1!" << endl;
                gameWin = true;
                return;  // Exit the function once a winner is found
            }
            else if (matrix[i][j] == symbolplayer2)
            {
                cout << "Game won by player 2!" << endl;
                gameWin = true;
                return;  // Exit the function once a winner is found
            }
        }
    }
}

    
}

void columndecider(int columndrop, int player)
{
    while (columndrop < 0 || columndrop > 7 || columnfull(columndrop))
    {
        if (columndrop < 0 || columndrop > 7)
        {
            cout << "Wrong Input, Enter a column between 1 and 7" << endl;
        }
        else if (columnfull(columndrop))
        {
            cout << "Column is full try another one, player" << player << endl;
        }

        cin >> columndrop;
    }

    for (int j = rows - 1; j >= 0; j--)
    {

        if (matrix[j][columndrop - 1] == symbol)
        {
            if (count2 % 2 == 0)
            {
                matrix[j][columndrop - 1] = symbolplayer1;
            }
            else if (count2 % 2 != 0)
            {
                matrix[j][columndrop - 1] = symbolplayer2;
            }
            break;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    count2++;
}

int main()
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = symbol;
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int columndrop;
    int count = rows * columns;
    int count3=0;

    for (int l = 0; l < count; l++)
    {
        if (gameWin)
        {
            break;
        }
        
        if (l % 2 == 0)
        {
            cout << "Your turn PLayer 1: " ;
            cin >> columndrop;
            columndecider(columndrop, 1);
            gamewinningcheck(columndrop);
        }
        else if (l % 2 != 0)
        {
            cout << "Your turn PLayer 2: " ;
            cin >> columndrop;
            columndecider(columndrop, 2);
            gamewinningcheck(columndrop);
        }
        count3++;
    }
    if (count3==42)
    {
        cout << "It resulted in a draw as board is filled" << endl;
    }
}
