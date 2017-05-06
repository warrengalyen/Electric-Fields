#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button : public RectangleShape
{
public:
	Button(Vector2f position, Vector2f size, Font &font, string text, Color color, bool initialCondition) ;
	bool isButtonClicked(Mouse::Button button, Vector2f mousePos, bool mouseClickedLastFrame) ;
	void switchButton();
	void setText(Font &font, string text, int size);

	bool getCondition();

	void draw(RenderWindow &window);

private:
	bool m_condition ;
	Text m_text ;
	Color m_color ;
};

