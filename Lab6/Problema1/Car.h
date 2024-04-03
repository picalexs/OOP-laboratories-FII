#pragma once
class Car
{
protected:
	char* brand;
	float fuelCapacity;
	float fuelConsumptionRain;
	float fuelConsumptionSun;
	float fuelConsumptionSnow;
	float averageSpeedRain;
	float averageSpeedSun;
	float averageSpeedSnow;
	float raceTime = 0;
public:
	Car(char* brandName, float fcap, float fcRain, float fcSun, float fcSnow, float avgsRain, float avgsSunny, float avgsSnow) :
		brand(brandName), fuelCapacity(fcap), fuelConsumptionRain(fcRain), fuelConsumptionSun(fcSun),
		fuelConsumptionSnow(fcSnow), averageSpeedRain(avgsRain), averageSpeedSun(avgsSunny), averageSpeedSnow(avgsSnow) {}

	virtual char* GetBrand() const = 0;
	virtual float GetFuelCapacity() const = 0;
	virtual float GetFuelConsumptionRain() const = 0;
	virtual float GetFuelConsumptionSun() const = 0;
	virtual float GetFuelConsumptionSnow() const = 0;
	virtual float GetAverageSpeedRain() const = 0;
	virtual float GetAverageSpeedSun() const = 0;
	virtual float GetAverageSpeedSnow() const = 0;
	virtual float GetRaceTime() const = 0;
	virtual void SetRaceTime(float time) = 0;
};

