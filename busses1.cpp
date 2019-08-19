// Yandex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <string>
//#include<algorithm>
//#include<cmath>

#include <iostream>
#include <map> 
#include <vector>
using namespace std;

int main()
{

	int N;

	cin >> N;

	map<string, vector<string>> bus_to_stops;
	map<string, vector<string>> stops_to_bus;

	for (int i = 0; i < N; i++) {
	
		string command;
		cin >> command;
		
		if (command == "NEW_BUS") {

			string bus;
			string bus_stop;
			int bus_stop_count;

			cin >> bus >> bus_stop_count;

			for (int j = 0; j < bus_stop_count; j++) {
				cin >> bus_stop;
				stops_to_bus[bus_stop].push_back(bus);
				bus_to_stops[bus].push_back(bus_stop);
			}
		}

		else if (command == "BUSES_FOR_STOP") {

			string stop;
			cin >> stop;

			int count = 0;

			if (stops_to_bus.find(stop) == stops_to_bus.end() || stops_to_bus.at(stop).size() == 0) {
				cout << "No stop";
			}

			else {
				for (auto k : stops_to_bus.at(stop))
					cout << k << " ";
			}

			cout << endl;


		}
		else if (command == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;

			if (bus_to_stops.find(bus)==bus_to_stops.end() || bus_to_stops.at(bus).size() == 0) {
				cout << "No bus";
				cout << endl;
			}
			else {
				for (auto k : bus_to_stops[bus]) {				
					int m = 0;

					cout << "Stop "<<k<<": ";
					for (auto l : stops_to_bus[k]) {
						if (l != bus) {
							cout << l << " ";
							m++;
						}
					}
					if (m == 0)
						cout << "no interchange";

					cout << endl;
				}
			}

		}
		else if (command == "ALL_BUSES") {
			if (bus_to_stops.size() == 0)
				cout << "No buses" << endl;

			for (auto k : bus_to_stops) {
				cout << "Bus " << k.first << ": ";
				for (auto l : k.second) {
					cout << l << " ";
				}
				cout << endl;
			}

		}

	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
