#pragma once

#include <SFML/Graphics.hpp>
#include "Utility.h"
#include <sstream>

using namespace std;
using namespace sf;

class Slider
{
public:
Slider(Vector2f bodySize, Vector2f sliderSize, Vector2f position, float min, float max, string text, Font &font);

bool isSliderClicked(Mouse::Button button, Vector2f mousePos);
int getSliderValue();
void setText(Font &font, string text, int size);

void draw(RenderWindow &window);

private:
RectangleShape m_body;
RectangleShape m_slider;
Vector2f m_position;
Vector2f m_textPosition;
bool m_wasClicked;
float m_min;
float m_max;
Text m_text;
string m_initialText;
};

