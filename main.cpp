#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "tick.hpp"
#include "strategies/simple_pips_diff_trigger.hpp"

int main(int, char**)
{
	FILE* 		market = fopen("data/XBTEUR.csv", "r");
	FILE* 		positions = fopen("positions.dat", "w");
	char 			buffer[200];
	Tick			tick;
	unsigned	line = 0;
	vector<Strategy*> strategies;

	// strategy
  printf(" parameters:");
	for(float t = 5; t <= 5; t += 2)
	{
		Strategy *strategy = new SimplePipsDiffTrigger(t);
		strategies.push_back(strategy);
		printf(",%9s", strategy->name().c_str());
	}
  printf("\n");

	while(fgets(buffer, 200, market) != NULL)
	{
		tick.time = atoi(strtok(buffer, ","));
		tick.bid = atof(strtok(NULL, ","));
		tick.ask = atof(strtok(NULL, ","));
		tick.bid_volume = atof(strtok(NULL, ","));
		tick.ask_volume = atof(strtok(NULL, ","));
		line++;

	  for(auto& strategy : strategies)
			strategy->new_tick(tick);

		if (line % 10000 == 0)
		{
			printf(" %d", tick.time);
			for(auto& strategy : strategies)
				printf(" ,%+7.0f (%3lu)", strategy->gain(), strategy->positions().size());
			printf("\n");
		}
	}

	for(auto& strategy : strategies) {
		float gain = 0;
		for(auto& position : strategy->positions()) {
			if (position.type == Position::SHORT) {
				fprintf(positions, "%d, %f, %d, %f,,,, %f\n", position.open_time, position.open_price, position.close_time - position.open_time, position.close_price - position.open_price, gain);
			} else {
				fprintf(positions, "%d,,,, %f, %d, %f, %f\n", position.open_time, position.open_price, position.close_time - position.open_time, position.close_price - position.open_price, gain);
			}
			gain += position.gain();
		}
	}

	fclose(market);
	fclose(positions);
}
