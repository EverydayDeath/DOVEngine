#pragma once

#include "DrawManager.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Editor
{
	public:
		static int main();
		static int GetBlockSize();
		static Vector2<int> GetWindowSize();
		static Vector2<int> GetLevelBlocks();
};