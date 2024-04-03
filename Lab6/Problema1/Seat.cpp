#include "Seat.h"

Seat::Seat() : Car(const_cast <char*>("Seat"), 10, 6, 9, 7, 10, 25, 10) {}

char* Seat::GetBrand() const
{
	return this->brand;
}

float Seat::GetFuelCapacity() const
{
	return this->fuelCapacity;
}
float Seat::GetFuelConsumptionRain() const
{
	return this->fuelConsumptionRain;
}
float Seat::GetFuelConsumptionSun() const
{
	return this->fuelConsumptionSun;
}
float Seat::GetFuelConsumptionSnow() const
{
	return this->fuelConsumptionSnow;
}
float Seat::GetAverageSpeedRain() const
{
	return this->averageSpeedRain;
}
float Seat::GetAverageSpeedSun() const
{
	return this->averageSpeedSun;
}
float Seat::GetAverageSpeedSnow() const
{
	return this->averageSpeedSnow;
}

float Seat::GetRaceTime() const
{
	return this->raceTime;
}

void Seat::SetRaceTime(float time)
{
	this->raceTime = time;
}