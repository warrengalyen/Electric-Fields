#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Point
{
public:

Point();
Point(float mass, Vector2f position, Vector2f speed);

float getMass() const;
void setMass(float const& mass);
vector<Vector2f> getForce() const;
Vector2f getTotalForce() const;
void addForce(Vector2f const& force);
void clearForce();
Vector2f getPosition() const;
void setPosition(Vector2f const& position);
Vector2f getSpeed() const;
void setSpeed(Vector2f const& speed);
Vector2f getAcceleration() const;
void setAcceleration(Vector2f const& acceleration);
void setStatic();
void setMovable();
bool isMovable();

void updatePosition(float const& dt);

private:
float m_mass;

vector<Vector2f> m_force;
Vector2f m_position;
Vector2f m_speed;
Vector2f m_acceleration;

bool m_movable;
};
