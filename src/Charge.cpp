#include "Charge.h"
#include <iostream>

Charge::Charge(float const& charge, float const& mass, Vector2f const& position)
{
	m_charge = charge;
	setMass(mass);
	setPosition(position);
	setMovable();
}

float Charge::getCharge() const
{
	return m_charge;
}

void Charge::setCharge(float const& charge)
{
	m_charge = charge;
}

Vector2f Charge::getCoulombForce(Charge const& e) const
{
	return (100000000.f * getCharge() * e.getCharge() / pow(Distance(getPosition(), e.getPosition()), 3.f)) * (getPosition() - e.getPosition());
}

vector<Vector2f> Charge::getFieldLine(Vector2f const& start, float const& angle, vector<Charge> const& charges, float const& segmentLength, int const& segmentNumber) const
{
	Vector2f p = rotatePoint(start + Vector2f(0, -1), start, angle);
	vector<Vector2f> E;
	E.push_back(p);

	for(int i = 1; i < segmentNumber; i++)
	{
		E.push_back(E[i - 1] + getCharge() / abs(getCharge()) * Charge::getNormalizedEField(E[i - 1], charges, segmentLength));
	}

	return E;
}

vector<VertexArray> Charge::getFieldLineVA(int const& nbOfLines, vector<Charge> const& charges, Color const& color, float const& segmentLength, int const& segmentNumber) const
{
	vector<VertexArray> EVA(nbOfLines);
	vector<vector<Vector2f> > E(nbOfLines);
	Vertex v;

	for(int i = 0; i < nbOfLines; i++)
	{
		E[i] = getFieldLine(getPosition(), i * (360 / nbOfLines), charges, segmentLength, segmentNumber);
	}

	for(int i = 0; i < nbOfLines; i++)
	{
		EVA[i].setPrimitiveType(LinesStrip);

		for (unsigned int j = 0; j < E[i].size(); j++)
		{
			v.position = Vector2f(E[i][j]);
			v.color = color;
			EVA[i].append(v);
		}
	}

	return EVA;
}

Vector2f Charge::getEField(Vector2f const& M, vector<Charge> const& charge, float const& segmentLength)
{
	Vector2f result(0, 0);

	for (unsigned int i = 0; i < charge.size(); i++)
	{
		result += charge[i].getCharge() / pow( Distance(M, charge[i].getPosition()), 2.f) * (M - charge[i].getPosition());
	}

	return result * segmentLength;
}

Vector2f Charge::getNormalizedEField(Vector2f const& M, vector<Charge> const& charge, float const& segmentLength)
{
	Vector2f result(0, 0);

	for (unsigned int i = 0; i < charge.size(); i++)
	{
		result += charge[i].getCharge() / pow( Distance(M, charge[i].getPosition()), 2.f) * (M - charge[i].getPosition());
	}

	return result / Norm(result) * segmentLength;
}

float Charge::getV(Vector2f const& M, vector<Charge> const& charge)
{
	float result = 0;

	for(unsigned int i = 0; i < charge.size(); i++)
	{
		result += charge[i].getCharge() / Distance(M, charge[i].getPosition());
	}

	return result;
}

