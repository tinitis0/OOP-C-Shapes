#pragma once
#include "SFML/Graphics.hpp" //inlcudes the sfml graphics library

//makes circle class drawable
class Circle : public sf::Drawable
{
	//creating private intagers
private:
	int posX;
	int posY;
	int radius;
	int pointAmmount; 

	sf::VertexArray pointArray;

	//creating methods
public:

	Circle(int xIn, int yIn, int rIn, int n);
	void createCircle();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
