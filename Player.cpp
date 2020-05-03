#include "Player.h"
Player::Player(int initialRow, int intialColumn)
{
	currentColumn = intialColumn;
	currentRow = initialRow;
	Pacman.setSize(Vector2f(RectangleShapeSize, RectangleShapeSize));//size hayet8ayar
	Pacman.setPosition(50 + RectangleShapeSize * intialColumn, 50 + RectangleShapeSize * initialRow);
	t.loadFromFile("Pacman_right.png");
	Pacman.setTexture(&t);
}
void Player::move(char direction, int arr[][15])// size el array hayet8ayar 
{
	if (direction == 'U')
	{
		if (arr[currentRow - 1][currentColumn] != -1)
		{
			currentRow--;
			Pacman.move(0, -RectangleShapeSize);//dah kaman hayet8ayar
			t.loadFromFile("Pacman_up.png");
			Pacman.setTexture(&t);
		}
	}
	if (direction == 'D')
	{
		if (arr[currentRow +1][currentColumn] != -1)
		{
			currentRow++;
			Pacman.move(0, RectangleShapeSize);//dah kaman hayet8ayar
			t.loadFromFile("Pacman_down.png");
			Pacman.setTexture(&t);
		}
	}
	if (direction == 'R')
	{
		if (arr[currentRow][currentColumn+1] != -1)
		{
			currentColumn++;
			Pacman.move(RectangleShapeSize,0 );//dah kaman hayet8ayar
			t.loadFromFile("Pacman_right.png");
			Pacman.setTexture(&t);
		}
	}
	if (direction == 'L')
	{
		if (arr[currentRow][currentColumn-1] != -1)
		{
			currentColumn--;
			Pacman.move(-RectangleShapeSize, 0);//dah kaman hayet8ayar
			t.loadFromFile("Pacman_left.png");
			Pacman.setTexture(&t);
		}
	}
}
void Player::drawOnWindow(RenderWindow& window)
{
	window.draw(Pacman);
}
int Player::getRow()
{
	return currentRow;
}
int Player::getColumn()
{
	return currentColumn;
}
void Player::superMode()
{
	//SuperMode=collision with super pellet
}
