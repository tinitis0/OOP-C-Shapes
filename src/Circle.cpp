//includes the circle headerfile
#include "Circle.h"


Circle::Circle(int xIn, int yIn, int rIn, int nIn) {
	posX = xIn;
	posY = yIn;
	radius = rIn;
	pointAmmount = nIn;
	pointArray.setPrimitiveType(sf::LineStrip);
	pointArray.resize(pointAmmount);
	createCircle();
}
//creates the circle with the correct dimentions and point count
void Circle::createCircle() { //creates the circle shape 
	int i_theta = 0;
	int i_angleIncrement = 360 / pointAmmount;
		for (int i = 0; i < pointAmmount; i++) {
		pointArray[i].position = sf::Vector2f((posX + std::cos(i_theta) * radius), (posY + std::sin(i_theta) * radius));
		i_theta += i_angleIncrement;
	}
}
//creates a draw function for circle
void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(pointArray);
}


