#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class DrawManager
{
	public:
		static void DrawScreen(RenderWindow& window);
		static void SetCursor(RectangleShape shape);
		static void SetCursorPosition(Vector2<int> position);
};

