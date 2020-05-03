#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace sf;

class Ghost
{
	int currentRow;
	int currentColumn;
	int speed;
	bool supermode;
	RectangleShape rectangle;
	string name;
	Texture texture;
public:
	Ghost(int, int, int, string, string);
	//void moveOnWindow(PacMan& pacman, Board board);
	void drawOnWindow(RenderWindow& window);
	void move(char, int arr[][10]);
	void superMode();
	int getRow();
	int getColumn();
	bool isSuperMode();
	~Ghost();
};



