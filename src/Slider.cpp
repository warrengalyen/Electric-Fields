#include "Slider.h"

using namespace std;
using namespace sf;

Slider::Slider(Vector2f bodySize, Vector2f sliderSize, Vector2f position, float min, float max, string text, Font &font)
{
	m_body = RectangleShape(bodySize);
	m_slider = RectangleShape(sliderSize);
	m_body.setFillColor(Color::Blue);
	m_body.setOutlineColor(Color::Black);
	m_body.setOutlineThickness(3);
	m_slider.setFillColor(Color::White);
	m_slider.setOutlineColor(Color::Black);
	m_slider.setOutlineThickness(3);

	m_textPosition = position;
	m_text.setFont(font);
	m_text.setPosition(position);
	m_text.setCharacterSize(15);
	m_text.setString(text);
	m_text.setFillColor(Color::Black);
	m_initialText = text;

	m_position = m_text.findCharacterPos(m_text.getString().getSize() - 1) + Vector2f(40, 5);
	m_body.setPosition(m_position);
	m_slider.setPosition(Vector2f( m_position.x + (bodySize.x - sliderSize.x) / 2, m_position.y - (sliderSize.y - bodySize.y) / 2));
	m_wasClicked = false;
	m_min = min;
	m_max = max;

	ostringstream oss;
	oss << getSliderValue();
	m_text.setString(m_initialText + oss.str());
}

bool Slider::isSliderClicked(Mouse::Button button, Vector2f mousePos)
{
	if ( (m_slider.getGlobalBounds().contains(mousePos) && Mouse::isButtonPressed(Mouse::Left)) || m_wasClicked)
	{
		m_slider.setPosition(mousePos.x + -m_slider.getSize().x / 2, m_slider.getPosition().y);

		if (m_slider.getPosition().x >= m_body.getPosition().x + m_body.getSize().x - m_slider.getSize().x) // boundings
			m_slider.setPosition(Vector2f(m_body.getPosition().x + m_body.getSize().x - m_slider.getSize().x, m_slider.getPosition().y));

		if (m_slider.getPosition().x <= m_body.getPosition().x)
			m_slider.setPosition(Vector2f(m_body.getPosition().x, m_slider.getPosition().y));

		m_wasClicked = true;

		if(!Mouse::isButtonPressed(Mouse::Left))
			m_wasClicked = false;

		ostringstream oss;
		oss << getSliderValue();
		m_text.setString(m_initialText + oss.str());
		return true;
	}
	else return false;
}

int Slider::getSliderValue()
{
	return ((m_slider.getPosition().x - m_position.x) / (m_body.getSize().x - m_slider.getSize().x) - 0.5) * (m_max - m_min) + (m_max + m_min) / 2;
}
void Slider::setText(Font &font, string text, int size)
{
	m_text.setFont(font);
	m_text.setPosition(m_textPosition);
	m_text.setCharacterSize(size);
	m_text.setString(text);
	m_text.setFillColor(Color::Black);
}

void Slider::draw(RenderWindow &window)
{
	window.draw(m_body);
	window.draw(m_slider);
	window.draw(m_text);
}
