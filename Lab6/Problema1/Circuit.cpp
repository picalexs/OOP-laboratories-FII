#include "Circuit.h"
#include <cstdio>

Circuit::Circuit()
{
	this->cars = nullptr;
	this->carCount = 0;
	this->length = 0;
	this->weather = Weather::Sunny;
}

void Circuit::SetLength(float inputLength)
{
	this->length = inputLength;
}

void Circuit::SetWeather(Weather inputWeather)
{
	this->weather = inputWeather;
}

void Circuit::AddCar(Car* car)
{
	Car** tmp = new Car * [this->carCount + 1];
	for (int i = 0; i < this->carCount; i++)
	{
		tmp[i] = this->cars[i];
	}
	tmp[this->carCount] = car;
	this->carCount++;
	delete[] this->cars;
	this->cars = tmp;
}

void Circuit::PrintCars() const
{
	for (int i = 0; i < this->carCount; i++) {
		printf("Car %s\n", this->cars[i]->GetBrand());
		printf("Fuel capacity = %.6g\n", this->cars[i]->GetFuelCapacity());
		printf("Fuel consumption rainy= %.6g\n", this->cars[i]->GetFuelConsumptionRain());
		printf("Fuel consumption sunny= %.6g\n", this->cars[i]->GetFuelConsumptionSun());
		printf("Fuel consumption snowy= %.6g\n", this->cars[i]->GetFuelConsumptionSnow());
		printf("Average speed rainy= %.6g\n", this->cars[i]->GetAverageSpeedRain());
		printf("Average speed sunny= %.6g\n", this->cars[i]->GetAverageSpeedSun());
		printf("Average speed snowy= %.6g\n", this->cars[i]->GetAverageSpeedSnow());
		printf("\n");
	}
}

void SortCars(Car**& cars, int carCount)
{
	for (int i = 0; i < carCount - 1; i++)
	{
		for (int j = i + 1; j < carCount; j++)
		{
			if (cars[i]->GetRaceTime() > cars[j]->GetRaceTime())
			{
				Car* tmp = cars[i];
				cars[i] = cars[j];
				cars[j] = tmp;
			}
		}
	}
}

void Circuit::Race()
{
	for (int i = 0; i < this->carCount; i++)
	{
		float fuelCapacity = cars[i]->GetFuelCapacity();
		float fuelConsumption, averageSpeed;

		switch (this->weather)
		{
		case Weather::Rain:
			fuelConsumption = cars[i]->GetFuelConsumptionRain();
			averageSpeed = cars[i]->GetAverageSpeedRain();
			break;
		case Weather::Sunny:
			fuelConsumption = cars[i]->GetFuelConsumptionSun();
			averageSpeed = cars[i]->GetAverageSpeedSun();
			break;
		case Weather::Snow:
			fuelConsumption = cars[i]->GetFuelConsumptionSnow();
			averageSpeed = cars[i]->GetAverageSpeedSnow();
			break;
		}

		if (this->length / fuelConsumption > fuelCapacity)
		{
			cars[i]->SetRaceTime(-1);
		}
		else
		{
			cars[i]->SetRaceTime(this->length / averageSpeed);
		}
	}
	SortCars(this->cars, this->carCount);
}

void Circuit::ShowFinalRanks() const
{
	int place = 1;
	for (int i = 0; i < this->carCount; i++)
	{
		if (cars[i]->GetRaceTime() != -1)
			printf("Car %s finished the race in place %d\n", this->cars[i]->GetBrand(), place++);
	}
	printf("\n");
}

void Circuit::ShowWhoDidNotFinish() const
{
	for (int i = 0; i < this->carCount && cars[i]->GetRaceTime() == -1; i++)
	{
		if (cars[i]->GetRaceTime() == -1)
		{
			printf("Car %s did not finish the race\n", this->cars[i]->GetBrand());
		}
	}
	printf("\n");
}

