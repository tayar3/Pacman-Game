// Nothing is final yet. not even the design and textures. we are first working on the mechanicms and movements
#include <fstream>
#include "Player.h" 
using namespace sf;
const int ROWS = 15, COLUMNS = 15;//sizes nezabatha


int main()
{
    RenderWindow window;
    window.create(VideoMode(1000, 1000), "Pacman Board");//sizes

    int arr[ROWS][COLUMNS];

    ifstream inputFile;
    inputFile.open("p.txt");//design el board
    if (inputFile.is_open())
    {
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLUMNS; j++)
                if (!inputFile.eof())
                    inputFile >> arr[i][j];
    }

    inputFile.close();
    Player player(1,1);//textures pacman
    Texture wallsTexture, backgroundTexture;
    wallsTexture.loadFromFile("walls.png");
    backgroundTexture.loadFromFile("backg.png");//ashouf hewar el background el beda

    RectangleShape board[ROWS][COLUMNS];

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLUMNS; j++)
        {
            board[i][j].setSize(Vector2f(70, 70));
            board[i][j].setPosition(50 + 70 * j, 50 + 70 * i);
            if (arr[i][j] == -1)
                board[i][j].setTexture(&wallsTexture);
            else
                board[i][j].setTexture(&backgroundTexture);
        }
    Event e;
    while (window.isOpen())
    {//ghost beyet7arak. RAND hetet3emel hena
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
            else if (e.type == Event::KeyPressed)
            {
                switch (e.key.code)
                {
                case Keyboard::Up:
                    player.move('U', arr);
                    break;
                case Keyboard::Down:
                    player.move('D', arr);
                    break;
                case Keyboard::Right:
                    player.move('R', arr);
                    break;
                case Keyboard::Left:
                    player.move('L', arr);
                    break;
                }
            }

        }
        window.clear();
        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLUMNS; j++)
                window.draw(board[i][j]);
        player.drawOnWindow(window);
        window.display();

    }
}