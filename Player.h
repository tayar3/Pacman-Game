#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
const int RectangleShapeSize = 70;
class Player
{
private:
	int currentRow;
	int currentColumn;
	RectangleShape Pacman;
	Texture t;
public:
	Player(int initialRow, int intialColumn);
	void move(char direction, int arr[][15]);// size el array hayet8ayar 
	void drawOnWindow(RenderWindow& window);
	int getRow();
	int getColumn();
	void superMode();
	//collison haykon fel board: ma3 food aw ghosts
	// lessa fy supermode: hay8ayar el collisions ma3 el objetcs w textures w ghost movements
};

