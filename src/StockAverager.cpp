#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <StockAverager.h>
#include <StocksProcessor.h>



int main()
{
    std::ifstream infile{"input.csv"};
    std::ofstream outfile{"output.csv"};
    StocksProcessor processor{};

    while (infile)
    {
        std::string line;
        std::string stockName;
        long timestamp;
        int volume;
        int price;

        if (!std::getline( infile, line )) break;
        std::istringstream ss( line );
  
        std::string d;
        if (!getline( ss, d, ',' )) break;
        timestamp = std::stol(d);

        if (!getline( ss, stockName, ',' )) break;

        if (!getline( ss, d, ',' )) break;
        volume = std::stoi(d);

        if (!getline( ss, d, '\n' )) break;
        price = std::stoi(d);
  
        processor.add(timestamp,stockName,volume,price);
    };

    outfile << processor;
};
