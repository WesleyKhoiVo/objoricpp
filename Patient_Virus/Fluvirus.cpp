#include "stdafx.h"
#include "Fluvirus.h"


Fluvirus::Fluvirus()
{
	DoBorn();
	InitResistance();	
}

Fluvirus::~Fluvirus()
{
	DoDie();
}

void Fluvirus::DoBorn()
{
	LoadADNInformation();
	if (rand() % 2 == 0)
		this->m_color = 255;
	else
		this->m_color = 16711680;
}

std::list<Virus*> Fluvirus::DoClone()
{
	Fluvirus *other = new Fluvirus;
	std::list<Virus*> tempLst;

	other->m_color = this->m_color;
	other->m_dna = this->m_dna;
	other->m_resistance = this->m_resistance;

	tempLst.push_back(other);

	return tempLst;
	tempLst.clear();
}

void Fluvirus::DoDie()
{
	this->m_color = 0;
	this->m_resistance = 0;
}

void Fluvirus::InitResistance()
{
	if (this->m_color == 255)
	{
		m_resistance = 10 + (rand() % (int)(20 - 10 + 1));
	}
	else
	{
		m_resistance = 10 + (rand() % (int)(15 - 10 + 1));
	}
}
