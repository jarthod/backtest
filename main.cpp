#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "tick.hpp"
#include "circular_buffer.hpp"

int main(int argc, char* argv[])
{
	FILE* 		file = fopen("data/EURUSD.csv", "r");
	char 			buffer[200];
	Tick			tick;
	CircularBuffer<Tick>	ticks;
	unsigned	line = 0;

	// strategy
	float			min = 1000000;
	float			max = 0;
	float			trigger = 0.004; // points
	unsigned	long_positions = 0;
	float			bought_at, sold_at;
	unsigned	short_positions = 0;
	float			gain = 0;

	while(fgets(buffer, 200, file) != NULL)
	{
		tick.date = strtok(buffer, ",");
		tick.bid = atof(strtok(NULL, ","));
		tick.ask = atof(strtok(NULL, ","));
		tick.bid_volume = atof(strtok(NULL, ","));
		tick.ask_volume = atof(strtok(NULL, ","));
		if (line % 1000000 == 0)
			std::cout << tick.date << std::endl;
		if (line > 100000000)
			break;
		line++;
		ticks.insert(tick);
		if (long_positions == 0 && tick.ask > (min + trigger)) // Go long
		{
			if (short_positions > 0)
			{
				gain += (sold_at - tick.ask) * 1000;
				printf("close SHORT %f -> %f (%+.1f pips) total: %+.1f pips\n", sold_at, tick.ask, (sold_at - tick.ask) * 1000, gain);
				short_positions = 0;
			}
			bought_at = tick.ask;
			++long_positions;
			max = 0;
		}
		if (short_positions == 0 && tick.bid < (max - trigger)) // Go short
		{
			if (long_positions > 0)
			{
				gain += (tick.bid - bought_at) * 1000;
				printf("close  LONG %f -> %f (%+.1f pips) total: %+.1f pips\n", bought_at, tick.bid, (tick.bid - bought_at) * 1000, gain);
				long_positions = 0;
			}
			sold_at = tick.bid;
			++short_positions;
			min = 1000000;
		}
		if (tick.ask < min)
			min = tick.ask;
		if (tick.bid > max)
			max = tick.bid;
	}

	fclose(file);
}
