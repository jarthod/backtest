# Backtest

A simple &amp; fast bitcoin trading strategy backtesting tool.

```
make
./backtest
gnuplot -p plot.gnu
```

## Market data

This program is designed to load market data formatted in CSV like this:

| timestamp | bid | ask | bid volume | ask volume |

```
1449528932,363.85,364.28,9.0,9.0
1449528942,363.84,364.28,9.0,9.0
1449529022,363.96,364.28,9.0,9.0
1449529081,363.84,364.99,9.0,9.0
1449529142,363.73,364.89,9.0,9.0
1449529202,363.84,364.5,9.0,1.0
1449529262,363.74,364.4899,9.0,5.0
1449529322,363.74,364.48,9.0,9.0
1449529382,363.74,364.48,9.0,9.0
1449529442,363.75,364.47,9.0,9.0
```

## Strategies

The strategies are defined as C++ subclasses of the `Strategy` class.

## Dependencies

`make` and `clang` or `g++` (`make CXX=g++` in this case).