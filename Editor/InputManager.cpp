#include "InputManager.h"
#include "DrawManager.h"
#include "Conversions.h"
#include <SFML/Graphics.hpp>

using namespace sf;

//---Fields---

//---Methods---

//Looks for input events
void InputManager::GetInput(RenderWindow& window)
{
	Event event;

	//Poll events in window
	while (window.pollEvent(event))
    {
		switch(event.type)
		{
		//Close window event
		case Event::Closed:
			window.close();
			break;
		
		//Mouse button pressed event
		case Event::MouseMoved:
			DrawManager::SetCursorPosition(Conversions::GridPointToScreen(Conversions::ScreenPointToGrid(Vector2<int>(event.mouseMove.x,event.mouseMove.y))));
			break;
		}
	}
}
