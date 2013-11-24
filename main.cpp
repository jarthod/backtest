#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "tick.hpp"
#include "strategies/simple_pips_diff_trigger.hpp"

int main(int argc, char* argv[])
{
	FILE* 		file = fopen("data/EURUSD.csv", "r");
	char 			buffer[200];
	Tick			tick;
	unsigned	line = 0;

	// strategy
	SimplePipsDiffTrigger	strategy(0.004);

	while(fgets(buffer, 200, file) != NULL)
	{
		tick.time = strtok(buffer, ",");
		tick.bid = atof(strtok(NULL, ","));
		tick.ask = atof(strtok(NULL, ","));
		tick.bid_volume = atof(strtok(NULL, ","));
		tick.ask_volume = atof(strtok(NULL, ","));
		// if (line > 10000000)
			// break;
		line++;
		strategy.new_tick(tick);
		if (line % 1000000 == 0)
			strategy.print_state();
	}

	fclose(file);
}
