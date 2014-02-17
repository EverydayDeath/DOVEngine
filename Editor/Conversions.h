#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Conversions
{
	public:
		static Vector2<int> ScreenPointToGrid(Vector2<int> screenPoint);
		static Vector2<int> GridPointToScreen(Vector2<int> screenPoint);
};

