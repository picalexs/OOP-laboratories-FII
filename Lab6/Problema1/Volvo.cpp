#include "Volvo.h"

Volvo::Volvo() : Car(const_cast <char*>("Volvo"), 80, 10, 8, 11, 70, 90, 50) {}

char* Volvo::GetBrand() const
{
	return this->brand;
}

float Volvo::GetFuelCapacity() const
{
	return this->fuelCapacity;
}
float Volvo::GetFuelConsumptionRain() const
{
	return this->fuelConsumptionRain;
}
float Volvo::GetFuelConsumptionSun() const
{
	return this->fuelConsumptionSun;
}
float Volvo::GetFuelConsumptionSnow() const
{
	return this->fuelConsumptionSnow;
}
float Volvo::GetAverageSpeedRain() const
{
	return this->averageSpeedRain;
}
float Volvo::GetAverageSpeedSun() const
{
	return this->averageSpeedSun;
}
float Volvo::GetAverageSpeedSnow() const
{
	return this->averageSpeedSnow;
}

float Volvo::GetRaceTime() const
{
	return this->raceTime;
}

void Volvo::SetRaceTime(float time)
{
	this->raceTime = time;
}