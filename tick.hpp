#include <string>

using namespace std;

#ifndef TICK_HPP
#define TICK_HPP

class Tick
{
	public:
		int		    time;
		float			bid, ask;
		float			bid_volume, ask_volume;
};

#endif