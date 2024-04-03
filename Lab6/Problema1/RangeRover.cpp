#include "RangeRover.h"

RangeRover::RangeRover() : Car(const_cast <char*>("RangeRover"), 70, 18, 15, 20, 90, 110, 60) {}

char* RangeRover::GetBrand() const
{
	return this->brand;
}

float RangeRover::GetFuelCapacity() const
{
	return this->fuelCapacity;
}

float RangeRover::GetFuelConsumptionRain() const
{
	return this->fuelConsumptionRain;
}

float RangeRover::GetFuelConsumptionSun() const
{
	return this->fuelConsumptionSun;
}

float RangeRover::GetFuelConsumptionSnow() const
{
	return this->fuelConsumptionSnow;
}

float RangeRover::GetAverageSpeedRain() const
{
	return this->averageSpeedRain;
}

float RangeRover::GetAverageSpeedSun() const
{
	return this->averageSpeedSun;
}

float RangeRover::GetAverageSpeedSnow() const
{
	return this->averageSpeedSnow;
}

float RangeRover::GetRaceTime() const
{
	return this->raceTime;
}

void RangeRover::SetRaceTime(float time)
{
	this->raceTime = time;
}
