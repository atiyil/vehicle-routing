#include <iostream>
#include "vehicle_routing.h"

using namespace std;

Point::Point(unsigned int x, unsigned int y): x_value(x), y_value(y) {}
unsigned int Point::get_x() { return x_value; }
unsigned int Point::get_y() { return y_value; }
unsigned int Point::set_x(unsigned int new_value) { x_value = new_value; }
unsigned int Point::set_y(unsigned int new_value) { y_value = new_value; }

Passenger::Passenger(string n, Point s, Point e): name(n), start(s), end(e) {}
string Passenger::get_name() { return name; }
Point Passenger::get_start() { return start; }

Vehicle::Vehicle(Point pos, vector<Passenger> pas): position(pos), passengers(pas) {}
Point Vehicle::get_position() { return position; }
void Vehicle::pick_up(Passenger new_pas) { passengers.push_back(new_pas); }
void Vehicle::drop_off() { passengers.pop_back(); }
void Vehicle::move_to(Point pos) { position = pos; }