#include "Conversions.h"
#include "Editor.h"
#include <SFML/Graphics.hpp>

using namespace sf;

//---Fields---

//---Methods---

//Converts from screen coordinates to grid coordinates
Vector2<int> Conversions::ScreenPointToGrid(Vector2<int> screenPoint)
{
	int blockSize = Editor::GetBlockSize();
	return Vector2<int>(screenPoint.x/blockSize,screenPoint.y/blockSize);
}

//Converts from grid coordinates to screen coordinates
Vector2<int> Conversions::GridPointToScreen(Vector2<int> gridPoint)
{
	int blockSize = Editor::GetBlockSize();
	return Vector2<int>(blockSize*gridPoint.x,blockSize*gridPoint.y);
}