# Backtest

A simple &amp; fast bitcoin trading strategy backtesting tool.

```
make
./backtest
gnuplot -p plot.gnu
```

## Market data

This program is design to load market data from [bitcoincharts.com historical CSV data](http://api.bitcoincharts.com/v1/csv).
The CSV file looks like this:

```
1389173189,624.010000000000,0.200000000000
1389173198,624.010000000000,0.097670000000
1389173198,623.538360000000,0.013579760000
1389173265,623.538360000000,0.148960240000
1389173339,623.540660000000,0.200000000000
1389173528,623.540660000000,0.176300000000
1389173534,623.540650000000,0.406330000000
1389173545,623.538360000000,1.800000000000
1389173545,623.538460000000,0.200000000000
1389173668,623.538360000000,0.123700000000
```

columns are:
- time
- price
- volume

## Strategies

The strategies are defined as C++ subclasses of the `Strategy` class.

## Dependencies

`make` and `clang` or `g++` (`make CXX=g++` in this case).