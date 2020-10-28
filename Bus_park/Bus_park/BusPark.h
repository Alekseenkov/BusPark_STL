#pragma once
#include<list>
#include<iostream>
#include<string>
#include<algorithm>
#include"Get.h"

class BusPark
{
public:
	BusPark();
	~BusPark();
	void NewBus();
	void In_Out(int number);
	void Out_In(int number);
	void PrintBusList(char item);

private:
	class Bus
	{
	public:
		int number;
		std::string nameOfDriver;
		int routeNumber;

		Bus(int number, std::string nameOfDriver, int routeNumber);
		
	};


	std::list<Bus> In;
	std::list<Bus> Out;
	

	friend std::ostream& operator<<(std::ostream& stream, const Bus& bus)
	{
		std::cout << "\nBus number - " << bus.number
			<< "\nBus name of driver - " << bus.nameOfDriver
			<< "\nBus route number - " << bus.routeNumber << std::endl;

		return stream;
	}
	
	friend std::istream& operator>>(std::istream& stream, Bus& bus)
	{
		Get get;
		
		std::cout << " Enter bus number -> ";
		bus.number = get._int();
			
		std::cout << " Enter name of driver -> ";
		bus.nameOfDriver = get._full_name();

		std::cout << " Enter route number -> ";
		bus.routeNumber = get._int();

		return stream;
	}
	
};




