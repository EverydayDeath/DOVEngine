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

	sf::RectangleShape shape;

	shape.setSize(sf::Vector2f(20, 20));

	sf::Color shapeCol(200, 80, 200);

    shape.setFillColor(shapeCol);

	shape.setPosition(100,25);

	bool charMoving = false;

	float charX = 25;
	float charY = 25;
	float moveSpeedX = 25;
	float moveSpeedY = 25;

	float gravity = 39.81;
	bool jumping = false;
	float jumpSpeed = 40;

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
					case sf::Keyboard::Space:
						if(!jumping)
						{
							jumping = true;
							moveSpeedY = -jumpSpeed;
						}
						break;
					}
					break;
				case sf::Event::KeyReleased:
					switch(event.key.code)
					{
					case sf::Keyboard::Right:
						// left key is pressed: move our character
						if(moveSpeedX > 0)
						{
//							charMoving = false;
							moveSpeedX = 0;
						}
						break;
					case sf::Keyboard::Left:
						if(moveSpeedX < 0)
						{
//							charMoving = false;
							moveSpeedX = 0;
						}
						break;
					}
					break;
				default:
					break;
			}
        }

		if(charX <= 0 && moveSpeedX < 0)
			moveSpeedX = 0;
		if(charX >= windowX-20 && moveSpeedX > 0)
			moveSpeedX = 0;

		if(charY <= windowY-20)
		{
			if(charMoving)
				moveSpeedY += gravity * deltaTime.asSeconds() * 3;
		}
		else
		{
			if(moveSpeedY > 0)
			{
				charY = windowY-20;
				jumping = false;
				moveSpeedY = 0;
			}
		}

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
