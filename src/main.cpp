/*! \mainpage Lab 2 - Shapes
*
* This program gives you a basic SFML winow in which to draw your shapes.
*
* The classes and files you use are up to you.  
*
* This software froms the basis of your submission for lab book 1
*/

/*! \file main.cpp
* \brief Main file for the application
*
* Contains the entry point of the application 
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
using namespace std;

//includes circle class header file
#include "circle.h"


int main() //!< Entry point for the application
{
	//creates a window where to draw shapes with the size, name and then sets thee frame limit
	sf::RenderWindow Window(sf::VideoMode(1024, 800), "Lab Book 1 - Shapes");
	Window.setFramerateLimit(60);

	
	//calls the circle from circle class
	Circle circle(300, 300, 100, 60);

	//creates 4 lines to create a triangle(4th line connects the first point and last together
	//then sets the position for each line/point using vectors
	sf::VertexArray triangle(sf::LineStrip, 4);
	triangle[0].position = sf::Vector2f(50, 50);
	triangle[1].position = sf::Vector2f(200, 50);
	triangle[2].position = sf::Vector2f(200, 200);
	triangle[3].position = sf::Vector2f(50, 50);

	//creates 5 lines to create a square(5th line connects the first point and last together
	//then sets the position for each line/point using vectors
	sf::VertexArray Square(sf::LineStrip, 5);
	Square[0].position = sf::Vector2f(400, 400);
	Square[1].position = sf::Vector2f(650, 400);
	Square[2].position = sf::Vector2f(650, 650);
	Square[3].position = sf::Vector2f(400, 650);
	Square[4].position = sf::Vector2f(400, 400);

	//creates 5 lines to create a rectangle(5th line connects the first point and last together
	//then sets the position for each line/point using vectors
	sf::VertexArray rectangle(sf::LineStrip, 5);
	rectangle[0].position = sf::Vector2f(700, 70);
	rectangle[1].position = sf::Vector2f(750, 70);
	rectangle[2].position = sf::Vector2f(750, 300);
	rectangle[3].position = sf::Vector2f(700, 300);
	rectangle[4].position = sf::Vector2f(700, 70);
	
	//creates 2 lines/points to create a line
	//then sets the position for each line/point using vectors
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(900, 500)),
		sf::Vertex(sf::Vector2f(900, 750))
	};
	//creates 2 lines/points to create a line which is 1 pixel lenght to make it a dot
	//then sets the position for each line/point using vectors
	sf::Vertex dot[] =
	{
		sf::Vertex(sf::Vector2f(800, 500)),
		sf::Vertex(sf::Vector2f(800, 501))
	};
	
		
	//creates 60 lines/points to create an arc
	//then it difines the properties of the arch
	sf::VertexArray ellipse(sf::LineStrip, 60);
	int i_angleIncrement = 360 / 60;
	int i_theta = 0;
	int Xpos = 500;
	int Ypos = 200;
	int Width = 100;
	int Height = 30;

	//does a for loop to draw the Ellipse shape, which then draws onto the windowed screen
	for (int i = 0; i < 60; i++) {

		ellipse[i].position = sf::Vector2f((Xpos + std::cos(i_theta)* Width), (Ypos + std::sin(i_theta)* Height));
		i_theta += i_angleIncrement;
	}


	//creates 10 lines/points to create an arc
	//then it difines the properties of the arch
	sf::VertexArray arc(sf::LineStrip, 10);
	int angleIncrements = 360 / 60;
	int i_thetat = 0;
	int i_maxThetat = 60;
	int XposPoint = 200;
	int YposPoint = 700;
	int CurveWidth = 180;
	int CurveHeight = 100;
	int P= 0;

	//does a do while loop to create the arc which the draws onto the windowed screen
	do {
		arc[P].position = sf::Vector2f((XposPoint + std::cos(i_thetat)* CurveWidth), (YposPoint + std::sin(i_thetat)* CurveHeight));
		i_thetat += angleIncrements;
		P++;
	
	} while (i_thetat < i_maxThetat);	



	//while the window is open it clears it sets the background as black and then draws the shapes
	while (Window.isOpen())
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)//if close buttone is pressed it checks to see if window has closed
			{
				Window.close();
			}
		}


		Window.clear(sf::Color::Black);

		//Draws the shapes onto the window
		Window.draw(circle);
		Window.draw(triangle);
		Window.draw(rectangle);
		Window.draw(Square);
		Window.draw(line, 2, sf::Lines);
		Window.draw(dot, 2, sf::Lines);
		Window.draw(ellipse);
		Window.draw(arc);
		Window.display();

	}

	   	 
		
};
