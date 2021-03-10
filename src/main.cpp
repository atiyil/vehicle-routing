#include <iostream>
#include <fstream>
#include <unordered_map>
#include "../libs/json.hpp"

#include "vehicle_routing.h"

using json = nlohmann::json;
using namespace std;

void increment_time(const string& line, unordered_map<string,vector<Passenger>>& start_list, unordered_map<string,vector<Passenger>>& end_list, Vehicle& car){
  
  // define a json object to parse json requests
  json j = json::parse(line);

  // iterate over each ride request
  for (int i=0; i < j["requests"].size(); i++) {
    cout << j["requests"][i] << endl;
  // TODO: handle ride requests and move the car to the next position
  }
  cout << "incrementing time by 1..\n";
}

int main() {
  cout << "Welcome to Ride Sharing service! Enjoy the ride!\n\n";

  // receive X and Y grid values from the user
  int x,y; 
  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;

  // create 2 hash tables to keep the list of Requests for quick access
  unordered_map<string,vector<Passenger>> start_list;
  unordered_map<string,vector<Passenger>> end_list;

  // initial position of the vehicle is assumed as (0,0)
  Point initial_point = Point(0,0);

  // the vehicle has initially no passengers
  vector<Passenger> passenger_list; 
  
  // initialize the vehicle
  Vehicle car = Vehicle(initial_point,passenger_list);

  // read input file to get list of requests at each time-step
  ifstream request_file("request_lists.txt");
  string line;

  if (request_file.is_open()){
    while (getline(request_file,line)){

      // each request list corresponds to a line in the json file
      cout << "Received new request: " << line << endl;
      increment_time(line, start_list, end_list, car);
    }
    request_file.close();
  }

  else cout << "Cannot open the request lists file!\n";

  return 0;
}
