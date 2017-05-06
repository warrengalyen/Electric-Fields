#pragma once

#include "Point.h"
#include "Utility.h"

class Charge : public Point
{
public:
Charge(float const& charge, float const& mass, Vector2f const& position);
float getCharge() const;
void setCharge(float const& charge);

Vector2f getCoulombForce(Charge const& e) const;
vector<Vector2f> getFieldLine(Vector2f const& start, float const& angle, vector<Charge> const&charges, float const& segmentLength, int const& segmentNumber) const;
vector<VertexArray> getFieldLineVA(int const& nbOfLines, vector<Charge> const& charges, Color const& color, float const& segmentLength, int const& segmentNumber) const;

vector<Vector2f> getVField(vector<Charge> const& charge, float const& segmentLength, Vector2f start, int segmentNumber) const;
vector<VertexArray> getVFieldVA(int const& nbOfLines, vector<Charge> const& charges, Color const& color, float const& segmentLength, int const& segmentNumber) const;

static Vector2f getEField(Vector2f const& M, vector<Charge> const& charge, float const& segmentLength);
static Vector2f getNormalizedEField(Vector2f const& M, vector<Charge> const& charge, float const& segmentLength);
static float getV(Vector2f const& M, vector<Charge> const& charge);

private:
float m_charge;

};

