#include "Fiat.h"

Fiat::Fiat() : Car(const_cast<char*>("Fiat"), 70, 10, 10, 10, 85, 110, 30) {}

char* Fiat::GetBrand() const
{
	return this->brand;
}

float Fiat::GetFuelCapacity() const
{
	return this->fuelCapacity;
}

float Fiat::GetFuelConsumptionRain() const
{
	return this->fuelConsumptionRain;
}

float Fiat::GetFuelConsumptionSun() const
{
	return this->fuelConsumptionSun;
}

float Fiat::GetFuelConsumptionSnow() const
{
	return this->fuelConsumptionSnow;
}

float Fiat::GetAverageSpeedRain() const
{
	return this->averageSpeedRain;
}

float Fiat::GetAverageSpeedSun() const
{
	return this->averageSpeedSun;
}

float Fiat::GetAverageSpeedSnow() const
{
	return this->averageSpeedSnow;
}

float Fiat::GetRaceTime() const
{
	return this->raceTime;
}

void Fiat::SetRaceTime(float time)
{
	this->raceTime = time;
}