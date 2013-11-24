# Backtest

A simple &amp; fast forex strategy backtesting solution.

```
make
./backtest
```

## Market data

This program is design to load market data from Dukascopy CSV tick data.
The required CSV file looks like this:

```
2007.03.30 00:00:05.934,1.33277,1.33287,24.80,44.70
2007.03.30 00:00:11.274,1.33281,1.33291,39.20,30.90
2007.03.30 00:00:28.531,1.33279,1.33289,6.10,43.10
```

columns are:
- time
- bid
- ask
- bid volume
- ask volume

## Strategies

The strategies are defined as C++ subclasses of the `Strategy` class.

## Dependencies

Nothing special, only `g++`.