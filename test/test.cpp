#include <cpptest.h>
#include <StockAverager.h>
#include <StocksProcessor.h>
#include <cassert>

class StockAverageTester : public Test::Suite { 

    void computeKnownWeightedAverage( ) { 
        StockAverager stock{"aaa"};    
        stock.addEntry(1234567,20,18);
        stock.addEntry(1234567,5,7);
        assert (stock.weightedAvg() == 15);
    } 

    void checkSingleTradeGap() {
        StockAverager stock{"aaa"};    
        stock.addEntry(1234567,10,12);
        assert (stock.gap() == 0);
    }

    void checkMultiTradeGap() {
        StockAverager stock{"aaa"};    
        stock.addEntry(1234567,10,12);
        stock.addEntry(1234667,10,12);
        assert (stock.gap() == 100);
    }

    void fvt() {
        StocksProcessor processor{};    
        processor.add(52924702,"aaa",13,1136);
        processor.add(52924702,"aac",20,477);
        processor.add(52925641,"aab",31,907);
        processor.add(52927350,"aab",29,724);
        processor.add(52927783,"aac",21,638);
        processor.add(52930489,"aaa",18,1222);
        processor.add(52931654,"aaa",9,1077);
        processor.add(52933453,"aab",9,756);

        assert(processor["aaa"].gap() == 5787);
        assert(processor["aaa"].volume() == 40);
        assert(processor["aaa"].weightedAvg() == 1161);
        assert(processor["aaa"].maxPrice() == 1222);

        assert(processor["aab"].gap() == 6103);
        assert(processor["aab"].volume() == 69);
        assert(processor["aab"].weightedAvg() == 810);
        assert(processor["aab"].maxPrice() == 907);

        assert(processor["aac"].gap() == 3081);
        assert(processor["aac"].volume() == 41);
        assert(processor["aac"].weightedAvg() == 559);
        assert(processor["aac"].maxPrice() == 638);
    }

    public: 
      StockAverageTester( ) {
         TEST_ADD(StockAverageTester::computeKnownWeightedAverage);
         TEST_ADD(StockAverageTester::checkSingleTradeGap);
         TEST_ADD(StockAverageTester::checkMultiTradeGap);
         TEST_ADD(StockAverageTester::fvt);
      } 

}; 
    

int main ( ) { 
  StockAverageTester example1;
  Test::TextOutput output(Test::TextOutput::Terse);
  return example1.run(output) ? 1 : 0;
}
