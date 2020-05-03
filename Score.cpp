#include "Score.h"



Score::Score()
{
	currentScore = 0;
	string line;
	ifstream inFile;
	inFile.open("highscore.txt");
	if (inFile.is_open())
	{
		getline(inFile, line);
		inFile.close();
	}

	highScore = stoi(line);
	text.setString("Score : " + to_string(currentScore) + "\nHigh Score : " + line);
	text.setPosition(500, 20);

}

void Score::incrementScore(int x)
{
	currentScore += x;
	if (currentScore > highScore) // sets new high score
	{
		highScore = currentScore;
		saveHighScore("highscore.txt");
	}
}
void Score::saveHighScore(string filename)
{

}
void Score::drawOnWindow(RenderWindow& window)
{
	window.draw(text);
}


Score::~Score()
{
}

