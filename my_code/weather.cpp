# include <iostream>
# include <string>
# include "weather.h"

std::ostream& operator << (std::ostream& os, const GPS& gps) {
	os << "latitude: " << gps.latitude << "; longitude: " << gps.longitude;
	return os;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) : station_nm(nm), my_loc(loc) {
}

string Weather::get_name() const {
	return station_nm;
}

int Weather::get_rating() const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}
ostream& operator<<(ostream& os, const Weather& w) {
	// w.set_rating(47);
	os << w.get_name() << ": rating " << w.get_rating() << " " << w.my_loc;
	return os;
}