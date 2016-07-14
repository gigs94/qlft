all: main

tester: test/test.cpp
	clang++ -pedantic -std=c++11 -o tester test/test.cpp -I/usr/local/include -I./src  -lcpptest

test: tester

stock_processor: src/StockAverager.cpp
	clang++ -pedantic -std=c++11 -o stock_processor src/StockAverager.cpp -I./src

main: stock_processor

