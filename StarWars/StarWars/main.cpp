

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
int main() {
	float rota = 0;
	int eleccion = 0;
	int pasos = 0;
	int frames = 0;
	double velocidad = 0.1;
	//Colocar texto
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}

	sf::Text text1,text2,text3;
	text1.setFont(font);
	text1.setString("EXPOSICION");
	text1.setCharacterSize(24);
	text1.setColor(sf::Color::White);
	text2.setFont(font);
	text2.setString("Presionar la tecla A para Figuras Geometricas y Rotacion");
	text2.setCharacterSize(24);
	text2.setColor(sf::Color::White);
	text3.setFont(font);
	text3.setString("Presionar la tecla B para Animaciones y Flipeo");
	text3.setCharacterSize(24);
	text3.setColor(sf::Color::White);
	text2.setPosition(sf::Vector2f(0, 20));
	text3.setPosition(sf::Vector2f(0, 40));
	
	sf::RenderWindow window(sf::VideoMode(1000, 625), "Exposicion");
	sf::CircleShape shape;
	shape.setRadius(40.f);
	shape.setPosition(100.f, 100.f);
	shape.setFillColor(sf::Color::Cyan);

	sf::RectangleShape rectangle(sf::Vector2f(150, 80));
	rectangle.setSize(sf::Vector2f(150, 80));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(400.f, 100.f);

	sf::CircleShape triangu(40,3);
	triangu.setPosition(800.f, 100.f);
	triangu.setFillColor(sf::Color::Red);

	sf::CircleShape rombo(40,4);
	rombo.setPosition(250.f, 400.f);
	rombo.setFillColor(sf::Color::White);

	sf::CircleShape octagon(40,8);
	octagon.setPosition(600.f, 400.f);
	octagon.setFillColor(sf::Color::Yellow);

	//Animacion y flipeo
	sf::Texture player;
	if (!player.loadFromFile("walk.png"))
	{
		// error...
	}
	sf::Sprite sprite1;
	sprite1.setTexture(player);
	sprite1.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	sprite1.setTextureRect(sf::IntRect(0, 0, 95.16, 158.75));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			eleccion = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
			eleccion = 2;
		}
		window.clear();
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		if (eleccion == 1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				rota = rota + 1;
				rectangle.setRotation(rota);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rota = rota - 1;
				rectangle.setRotation(rota);
			}
			window.clear();
			window.draw(shape);
			window.draw(rectangle);
			window.draw(triangu);
			window.draw(rombo);
			window.draw(octagon);
		}
		if (eleccion == 2) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				sprite1.move(0, -velocidad);
				sprite1.setTextureRect(sf::IntRect(95.16*pasos, 158.75 * 3, 95.16, 158.75));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				sprite1.move(0, velocidad);
				sprite1.setTextureRect(sf::IntRect(95.16*pasos, 0, 95.16, 158.75));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				sprite1.move(velocidad, 0);
				sprite1.setTextureRect(sf::IntRect(95.16*pasos, 158.75 * 2, 95.16, 158.75));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				sprite1.move(-velocidad, 0);
				sprite1.setTextureRect(sf::IntRect(95.16*pasos, 158.75 * 1, 95.16, 158.75));
			}
			if (frames % 100 == 0) {
				pasos++;
			}
			frames++;
			if(pasos==11){
				pasos = 0;
			}
			window.clear();
			window.draw(sprite1);
		}
		window.display();
	}

}