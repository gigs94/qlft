#ifndef _STOCK_PROCESSOR_
#define _STOCK_PROCESSOR_


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <StockAverager.h>

class StocksProcessor {
   public:

       StocksProcessor() {}

       void add (int timestamp, std::string stockName, int volume, int price) {
           if (_processor.find(stockName) == _processor.end())
               _processor[stockName] = StockAverager(stockName);
           _processor[stockName].addEntry(timestamp,volume,price);
       }

       StockAverager& get (std::string stockName) {
           return _processor[stockName];
       }


       StockAverager& operator[](std::string a)
       {
           return _processor[a];
       }

       friend std::ostream& operator<<(std::ostream& os, const StocksProcessor& obj)
       {
           for ( auto it = obj._processor.begin(); it != obj._processor.end(); ++it )
               os << it->second;

           return os;
       }

   private:
       std::map <std::string, StockAverager> _processor;
};


#endif 
