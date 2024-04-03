#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	char* GetBrand() const override;
	float GetFuelCapacity() const override;
	float GetFuelConsumptionRain() const override;
	float GetFuelConsumptionSun() const override;
	float GetFuelConsumptionSnow() const override;
	float GetAverageSpeedRain() const override;
	float GetAverageSpeedSun() const override;
	float GetAverageSpeedSnow() const override;
	float GetRaceTime() const override;
	void SetRaceTime(float time) override;
};

