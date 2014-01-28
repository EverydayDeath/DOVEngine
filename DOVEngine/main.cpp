#include <SFML/Graphics.hpp>

int main()
{
	//time management Clock
	sf::Clock clock;

	int windowX = 250;
	int windowY = 250;

    // create the window
    sf::RenderWindow window(sf::VideoMode(windowX, windowY), "DOVEngine");

	window.setTitle("DOVEngine");
	window.setVerticalSyncEnabled(true); 

	// Declare and load a texture
	sf::Texture texture;
	texture.loadFromFile("C:\\Users\\Ryan S\\Pictures\\Trees\\Trees\\bush2.png");

	// Create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);

	sprite.setPosition(100, 25);

	sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

	shape.setPosition(100,25);

	bool charMoving = false;

	float charX = 25;
	float charY = 25;
	float moveSpeedX = 25;
	float moveSpeedY = 25;

	// run the program as long as the window is open
    while (window.isOpen())
    {

		sf::Time deltaTime = clock.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
			switch(event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch(event.key.code)
					{
					case sf::Keyboard::Right:
						// left key is pressed: move our character
						charMoving = true;
						moveSpeedX = 25;
						break;
					case sf::Keyboard::Left:
						charMoving = true;
						moveSpeedX = -25;
						break;
					}
					break;
				case sf::Event::KeyReleased:
					break;
				default:
					break;
			}
        }

		if(charX <= 5)
			moveSpeedX = 25;
		if(charX >= windowX-5)
			moveSpeedX = -25;
		if(charY <= 5)
			moveSpeedY = 25;
		if(charY >= windowY-5)
			moveSpeedY = -25;

		if(charMoving)
		{
			charX += 10 * moveSpeedX * deltaTime.asSeconds();
			charY += 10 * moveSpeedY * deltaTime.asSeconds();
		}

       // clear the window with black color
		window.clear(sf::Color::Black);

        // draw everything here...
		shape.setPosition(charX, charY);
        window.draw(shape);

        // end the current frame
        window.display();
    }

    return 0;
}