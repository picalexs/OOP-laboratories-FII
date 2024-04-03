#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit
{
	Car** cars;
	int carCount;
	float length;//in km
	Weather weather;

public:
	Circuit();
	void SetLength(float inputLength);
	void SetWeather(Weather inputWeather);
	void AddCar(Car* car);
	void PrintCars() const;
	void Race();
	void ShowFinalRanks() const;
	void ShowWhoDidNotFinish() const;
};

