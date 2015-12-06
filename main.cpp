#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "tick.hpp"
#include "strategies/simple_pips_diff_trigger.hpp"

int main(int, char**)
{
	FILE* 		file = fopen("data/krakenEUR.csv", "r");
	char 			buffer[200];
	Tick			tick;
	unsigned	line = 0;
	vector<Strategy*> strategies;

	// strategy
  printf(" parameters:");
	for(float t = 1; t <= 9; t += 1)
	{
		Strategy *strategy = new SimplePipsDiffTrigger(t);
		strategies.push_back(strategy);
		printf(",%9s", strategy->name().c_str());
	}
  printf("\n");

	while(fgets(buffer, 200, file) != NULL)
	{
		tick.time = strtok(buffer, ",");
		tick.price = atof(strtok(NULL, ","));
		tick.volume = atof(strtok(NULL, ","));
		line++;

	  for(auto& strategy : strategies)
			strategy->new_tick(tick);

		if (line % 100000 == 0)
		{
			printf(" %s", tick.time.c_str());
			for(auto& strategy : strategies)
				printf(" ,%+7.0f (%3d)", strategy->gain(), strategy->trades());
			printf("\n");
		}
	}

	fclose(file);
}
