#ifndef VEHICLE_ROUTING_H
#define VEHICLE_ROUTING_H

#include <vector>
#include <string>

using namespace std;

class Point{
  private:
    unsigned int x_value,y_value;
  public:
    Point(unsigned int, unsigned int);
    unsigned int get_x();
    unsigned int get_y();
    unsigned int set_x(unsigned int);
    unsigned int set_y(unsigned int);  
};

class Passenger{
  private:
    string name;
    Point start;
    Point end;
  public:
    Passenger(string,Point,Point);
    string get_name();
    Point get_start();
};

class Vehicle{
  private:
    Point position;
    vector<Passenger> passengers;
  public:
    Vehicle (Point, vector<Passenger>);
    void move_to(Point);
    void drop_off();
    void pick_up(Passenger);
    Point get_position();
    vector<Passenger> get_passengers();
};

#endif