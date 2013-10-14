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

	while(fgets(buffer, 200, file) != NULL)
	{
		tick.date = strtok(buffer, ",");
		tick.bid = atof(strtok(NULL, ","));
		tick.ask = atof(strtok(NULL, ","));
		tick.bid_volume = atof(strtok(NULL, ","));
		tick.ask_volume = atof(strtok(NULL, ","));
		if (line % 1000000 == 0)
			std::cout << tick.date << std::endl;
		line++;
		ticks.insert(tick);
	}

	fclose(file);
}
