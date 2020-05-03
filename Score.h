#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

	using namespace std;
	using namespace sf;

	class Score
	{
		int currentScore;
		int highScore;
		Text text;
		int row;
		int column;
	public:
		Score();
		void incrementScore(int); // increments current score
		void saveHighScore(string); // saves high score to a file
		void drawOnWindow(RenderWindow& window);
		~Score();
	};



