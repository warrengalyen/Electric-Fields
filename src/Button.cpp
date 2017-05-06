#include "Button.h"
#include "Utility.h"

Button::Button(Vector2f position, Vector2f size, Font &font, string text, Color color, bool initialCondition)
{
	m_text.setFont(font);
	m_text.setPosition(position);
	m_text.setCharacterSize(15);
	m_text.setString(text);
	m_text.setFillColor(Color::Black);
	setSize(size);
	setPosition(m_text.findCharacterPos(m_text.getString().getSize() - 1) + Vector2f(10, 0));
	setOutlineThickness(3);
	setOutlineColor(Color::Black);
	m_color = color;
	m_condition = initialCondition;
}

bool Button::isButtonClicked(Mouse::Button button, Vector2f mousePos, bool mouseClickedLastFrame)
{
	if (getGlobalBounds().contains(mousePos) && mouseClickedOnce(Mouse::Left, mouseClickedLastFrame))
	{
		switchButton();
		return true;
	}
	else return false;
}

void Button::switchButton()
{
	m_condition = !m_condition;
}

void Button::setText(Font &font, string text, int size)
{
	m_text.setFont(font);
	m_text.setPosition(getPosition());
	m_text.setCharacterSize(size);
	m_text.setString(text);
	m_text.setFillColor(Color::Black);
}

bool Button::getCondition()
{
	return m_condition;
}

void Button::draw(RenderWindow &window)
{
	if(m_condition)
		setFillColor(m_color);
	else
		setFillColor(Color::White);

	window.draw(*this);
	window.draw(m_text);
}
