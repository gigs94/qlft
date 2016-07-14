
# Design & Construction

## Definitions
 - *TimeStamp* is value indicating the microseconds since midnight.
 - *Symbol* is the 3 character unique identifier for a financial instrument (Stock, future etc.)
 - *Quantity* is the amount traded
 - *Price* is the price of the trade for that financial instrument.
 - *Maximum time gap* Amount of time that passes between consecutive trades of a symbol
 - *[Total] Volume*  (Sum of the quantity for all trades in a symbol).
 - *Weighted Average Price*  Average price per unit traded not per trade.



## Requirements
 1. Input in csv format:   <TimeStamp>,<Symbol>,<Quantity>,<Price>
 2. process (near) infinite amounts of data (can't load entire input files)
 3. Output in csv format:  <Symbol>,<MaxTimeGap>,<Volume>,<WeightedAveragePrice>,<MaxPrice>
 4. if only 1 trade is in the file then the gap is 0.
 5. Result should be truncated to whole numbers.
 6. Safe Assumptions
    - TimeStamp is always for the same day and won't roll over midnight.
    - TimeStamp is increasing or same as previous tick (time gap will never be < 0).
    - Price - our currency is an integer based currency.  No decimal points.
    - Price - Price is always > 0.



## Test Case

### Example 1

Example: here is a row for a trade of 10 shares of aaa stock at a price of 12 

1234567,aaa,20,18
1234567,aaa,5,7

  Example: the following trades
	- 20 shares of aaa @ 18
	- 5 shares of aaa @ 7
	- Weighted Average Price = ((20 * 18) + (5 * 7)) / (20 + 5) = 15


### Example 2

Sample Input:
 - 52924702,aaa,13,1136
 - 52924702,aac,20,477
 - 52925641,aab,31,907
 - 52927350,aab,29,724
 - 52927783,aac,21,638
 - 52930489,aaa,18,1222
 - 52931654,aaa,9,1077
 - 52933453,aab,9,756

Sample Output:
 - aaa,5787,40,1161,1222
 - aab,6103,69,810,907
 - aac,3081,41,559,638
