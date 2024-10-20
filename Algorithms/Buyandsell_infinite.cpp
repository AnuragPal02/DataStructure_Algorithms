/*

Given a list containing future prediction of share prices, find the maximum profit earned by buying and selling shares any number of times with the constraint, a new transaction can only start after the previous transaction is complete, i.e., you can only hold at most one share at a time.

Input : [1, 5, 2, 3, 7, 6, 4, 5]
Output: 10
Explanation: Total profit earned is 10

Buy on day 1 and sell on day 2
Buy on day 3 and sell on day 5
Buy on day 7 and sell on day 8


Input : [10, 8, 6, 5, 4, 2]
Output: 0

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
 

class Solution
{
public:
	int findMaxProfit(vector<int> const &price)
	{
		// ye interesting question hai
		// isme bas tabhi khareedna jab pichle wale din se bhi chota ho
		// aur tabhi bechna jab aage wala din aaj wale se chota ho 
		// aur ham iske liye sabse chota wale ko track karke j me rakhenge
		
		// profit ka hisab 
		int profit = 0;
		
		int n = price.size();
		int buy_karliya = 0;
		for(int i=0;i<n;i++){
			
			// agar pahle din hai to tabhi khareedenge jab aane wala din profit de
			if(i==0 && price[i+1]>= price[i]){
				buy_karliya = i;
			}
			
			// ham tabhi khareedenge jab pichle wala din aaj wale se bada ho
			if(price[i-1] > price[i]){
				buy_karliya = i;
			}
			
			// aur bechenge tab jab aage wala aaj wale se chota ho kyuki ham baad me bhei
			//khareed sakte hain
			if(price[i] > price[i+1] && price[i-1] <= price[i] || (i==n-1) && price[i] > price[i-1]){
				profit += price[i] - price[buy_karliya];
			}
		}
		return profit;
	}
};
