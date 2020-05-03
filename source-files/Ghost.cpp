#include "Ghost.h"



Ghost::Ghost(int x, int y, int s, string image, string n)
{
	rectangle.setSize(Vector2f(70, 70));
	rectangle.setPosition(x, y);
	texture.loadFromFile(image);
	rectangle.setTexture(&texture);
	currentRow = x;
	currentColumn = y;
	name = n;
	speed = s;
	supermode = false;
}

//void Ghost::moveOnWindow(PacMan& pacman, Board board)
//	// this will determine the ghost's movement based on the shortest path to pacman (Dijkstra's algorithm)
	// the movement is autonomous and will use the move() method
	//if (!supermode)
	//{

	//}
//}

void Ghost::move(char direction, int arr[][10]) //direction will be from rand
{
	if (direction == 'U' || direction == 'u')
	{
		if (arr[currentRow - 1][currentColumn] != -1)
		{
			currentRow--;
			rectangle.move(0, -speed);
		}
	}
	else if (direction == 'D' || direction == 'd')
	{
		if (arr[currentRow + 1][currentColumn] != -1)
		{
			currentRow++;
			rectangle.move(0, speed);
		}
	}
	else if (direction == 'R' || direction == 'r')
	{
		if (arr[currentRow][currentColumn + 1] != -1)
		{
			currentColumn++;
			rectangle.move(speed, 0);
		}
	}
	else if (direction == 'L' || direction == 'l')
	{
		if (arr[currentRow][currentColumn - 1] != -1)
		{
			currentColumn--;
			rectangle.move(-speed, 0);
		}
	}
}


void Ghost::superMode()
{
	supermode = true;
	speed = speed / 2;
	texture.loadFromFile("scared.png");
	rectangle.setTexture(&texture);
}


void Ghost::drawOnWindow(RenderWindow& window)
{
	window.draw(rectangle);
}

int Ghost::getRow()
{
	return currentRow;
}

int Ghost::getColumn()
{
	return currentColumn;
}

bool Ghost::isSuperMode()
{
	return supermode;
}


Ghost::~Ghost()
{
}

