#include <iostream>
using namespace std;

int main() {

   /* Type your code here. */
   int input, sparechange, dollars, quarters, dimes, nickels, pennies;
   cin >> input;
   
   if (!cin) {
      cout << "Error" << endl;
      return 0;
   } else if (input < 1) {
      cout << "No change" << endl;
      return 0;
   }
   
   dollars = (input / 100);
   sparechange = input % 100;
   quarters = (sparechange / 25);
   sparechange -= (quarters * 25);
   dimes = (sparechange / 10);
   sparechange -= (dimes * 10);
   nickels = (sparechange / 5);
   sparechange -= (nickels * 5);
   pennies = (sparechange / 1);
   sparechange -= (pennies * 1);
   
   if (dollars) {
     cout << dollars << ((dollars != 1) ? " Dollars" : " Dollar") << endl;
   }
   if (quarters) {
      cout << quarters << ((quarters != 1) ? " Quarters" : " Quarter") << endl;
   }
   if (dimes) {
      cout << dimes << ((dimes != 1) ? " Dimes" : " Dime") << endl;
   }
   if (nickels) {
      cout << nickels << ((nickels != 1) ? " Nickels" : " Nickel") << endl;
   }
   if (pennies) {
      cout << pennies << ((pennies != 1) ? " Pennies" : " Penny") << endl;  
   }
   
   

   return 0;
}
