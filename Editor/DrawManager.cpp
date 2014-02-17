#include "DrawManager.h"
#include <SFML/Graphics.hpp>

using namespace sf;

//---Fields---
RectangleShape cursor;

//---Methods---

//Draws everything on screen
void DrawManager::DrawScreen(RenderWindow& window)
{
	window.draw(cursor);
}

//Getter/Setter

//Sets a new cursor
void DrawManager::SetCursor(RectangleShape shape)
{
	cursor = shape;
}

//Sets the cursor's position
void DrawManager::SetCursorPosition(Vector2<int> position)
{
	cursor.setPosition(position.x,position.y);
}

