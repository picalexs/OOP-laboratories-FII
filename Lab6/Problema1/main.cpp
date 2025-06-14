#include <iostream>
#include "BMW.h"
#include "Circuit.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Volvo.h"
using namespace std;

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.PrintCars();
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}