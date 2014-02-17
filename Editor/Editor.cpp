#include "Editor.h"
#include "DrawManager.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


//---Fields---
const int blockSize = 32;
const Vector2<int> windowSize(1024,768);
const Vector2<int> levelBlocks(32,24);
string applicationName = "Editor";

//---Methods---

//Getter/Setter

//Returns windowSize
Vector2<int> Editor::GetWindowSize()
{
	return windowSize;
}

//Returns levelBlocks
Vector2<int> Editor::GetLevelBlocks()
{
	return levelBlocks;
}

//Returns blockSize
int Editor::GetBlockSize()
{
	return blockSize;
}

//Main loop
int main()
{
	//Create application window
	RenderWindow applicationWindow;
	applicationWindow.create(sf::VideoMode(windowSize.x,windowSize.y), applicationName);
	applicationWindow.setTitle(applicationName);
	applicationWindow.setVerticalSyncEnabled(true);
	
	//Setup cursor
	RectangleShape cursor;
	cursor.setSize(Vector2f(32, 32));
	Color shapeCol(200, 80, 200);
    cursor.setFillColor(shapeCol);
	DrawManager::SetCursor(cursor);

	//Run application while the window is open
	while(applicationWindow.isOpen())
	{
		//Get input
		InputManager::GetInput(applicationWindow);

		//Clear window
		applicationWindow.clear(sf::Color::Black);

        //Draw new content
		DrawManager::DrawScreen(applicationWindow);

        //End current frame
        applicationWindow.display();
	}

	return 0;
}