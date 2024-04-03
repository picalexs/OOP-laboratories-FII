#include "BMW.h"

BMW::BMW() : Car(const_cast<char*>("BMW"), 120, 14, 12, 15, 90, 180, 70) {}

char* BMW::GetBrand() const
{
	return this->brand;
}

float BMW::GetFuelCapacity() const
{
	return this->fuelCapacity;
}
float BMW::GetFuelConsumptionRain() const
{
	return this->fuelConsumptionRain;
}
float BMW::GetFuelConsumptionSun() const
{
	return this->fuelConsumptionSun;
}
float BMW::GetFuelConsumptionSnow() const
{
	return this->fuelConsumptionSnow;
}
float BMW::GetAverageSpeedRain() const
{
	return this->averageSpeedRain;
}
float BMW::GetAverageSpeedSun() const
{
	return this->averageSpeedSun;
}
float BMW::GetAverageSpeedSnow() const
{
	return this->averageSpeedSnow;
}

float BMW::GetRaceTime() const
{
	return this->raceTime;
}

void BMW::SetRaceTime(float time)
{
	this->raceTime = time;
}
