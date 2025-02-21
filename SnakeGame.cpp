#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void Draw()
{
	system("cls"); // clear console window
	for (int i = 0; i < width+2; i++)       // print top walls
		cout << "#";   
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)             // print right walls
				cout << "#";

			if (i == y && j == x)   // print head
				cout << "O";
			else if (i == fruitY && j == fruitX)    // print fruit
				cout << "F";

			else                     
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)     // print tail
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";         // print space inside walls
			}

			if (j == width - 1)      // print right walls
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width+2; i++) // print bottom walls
		cout << "#";
	cout << endl;

	cout << endl << "Score:" << score << endl;        // Display score
}

void Input()    // moves the sanke with wasd characters
{
	if (_kbhit())   // returns positive number if character in keyboard is pressed, if not, it'll return 0
	{
		switch (_getch())     // returns the character that was pressed (handles the controls)
		{
		case 'a':
			dir = LEFT;
			break;

		case 'd':
			dir = RIGHT;
			break;

		case 'w':
			dir = UP;
			break;

		case 's':
			dir = DOWN;
			break;

		case 'x':                   // end game
			gameOver = true;
			break;
		}
	}
}

void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width || x < 0 || y > height || y < 0)
	  gameOver = true;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main()
{
	srand(time(NULL));
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(100);
	}

	return 0;
}