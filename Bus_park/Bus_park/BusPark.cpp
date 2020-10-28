#include "BusPark.h"

BusPark::BusPark()
{
}

BusPark::~BusPark()
{
}


void BusPark::NewBus()
{
	Bus bus(0, " ", 0);

	  bool flag = true;
	while (flag)
	{
		std::cin >> bus;
		
		auto it = std::find_if(begin(In), end(In), [bus](const Bus& s)
			{
			return bus.number == s.number;
			});

		if (it == In.end())
			flag = false;
		else
			std::cout << "\nError! Number must be unique...\n ";
	}

	In.push_back(bus);
	std::cout << " \n";
}

void BusPark::In_Out(int number)
{
	auto it = std::find_if(begin(In), end(In), [number](const Bus& a) {
		return a.number == number;
		});

	if (it == end(In))
		throw std::exception("Error!\n Impossible this bus is'n in park.\n");
	else
	{
	Out.push_back(Bus(it->number, it->nameOfDriver, it->routeNumber));
		In.erase(it);
	}
	
}

void BusPark::Out_In(int number)
{
	auto it = std::find_if(begin(Out), end(Out), [number](const Bus& a) {
		return a.number == number;
		});

	if (it == end(Out))
		throw std::exception("Error!\n Impossible this bus is'n on route.\n");
	else
	{
		In.push_back(Bus(it->number, it->nameOfDriver, it->routeNumber));
		Out.erase(it);
	}
	
}

void BusPark::PrintBusList(char item)
{
	(item =='1' ) ? std::cout << "\n\tInformation about buses in the park.\n":
		std::cout << "\n\tInformation about buses on the route.\n";

	for_each(begin((item == '1') ? In:Out), end((item == '1') ? In : Out), [](const Bus& bus) {
		std::cout << bus << std::endl;
		});

}


BusPark::Bus::Bus(int number, std::string nameOfDriver, int routeNumber)
{
	this->number = number;
	this->nameOfDriver = nameOfDriver;
	this->routeNumber = routeNumber;
}
