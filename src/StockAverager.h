#ifndef _STOCK_AVERAGER_
#define _STOCK_AVERAGER_

#include <iostream>
#include <string>

class StockAverager {

    public:
        void addEntry(long timestamp, int volume, int price) {
            _totalCost += (volume * price);
            _totalShares += volume;

            weightedAverageCalc();
            maxPriceCalc(price);
            gapCalc(timestamp);

            _lasttime = timestamp;
        }

        int gap(std::string stockname) {
            return _gap;
        }

        StockAverager() {}
        StockAverager(std::string stockName) : _stockName(stockName), _gap(0), _lasttime(0), _maxPrice(0) {}


       friend std::ostream& operator<<(std::ostream& os, const StockAverager& obj)
       {
           if (obj._stockName != "")
           {
              os << obj._stockName << ","
                 << obj._gap << ","
                 << obj._totalShares << ","   
                 << obj._weightedAverage << ","   
                 << obj._maxPrice << "\n";
           }
           return os;
       }

        int volume() {
           return _totalShares;
        }

        int weightedAvg() {
            return _weightedAverage;
        }

        int gap() {
           return _gap;
        }

        int maxPrice() {
           return _maxPrice;
        }

    private:
        int _weightedAverage;
        int _gap;
        int _totalCost;
        int _totalShares;
        int _maxPrice;
        std::string _stockName;
        long _lasttime;

        void maxPriceCalc(int price) {
           if (_maxPrice < price) {
               _maxPrice = price;
           }
        }

        void weightedAverageCalc() {
           _weightedAverage = _totalCost / _totalShares;
        }

        void gapCalc(long newtime) {
           if (_lasttime == 0) {
               _gap = 0;
           }
           else
           {
              long new_gap = newtime - _lasttime;
              if (new_gap > _gap) {
                 _gap = new_gap;
              }
           }
        }

};

#endif // _STOCK_AVERAGER_
