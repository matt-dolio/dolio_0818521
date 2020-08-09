#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
   string inputMonth;
   int inputDay;
   
   cin >> inputMonth;
   cin >> inputDay;
   
   /* Type your code here. */
   string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   
   bool isValidDate = (inputDay < 31 && inputDay > 0);
   
   bool isValidMonth = (find(begin(months), end(months), inputMonth) != end(months));
   
   if (isValidDate && isValidMonth) {
      if (inputMonth == months[0] || inputMonth == months[1]) {
         cout << "Winter" << endl;
      } else if (inputMonth == months[3] || inputMonth == months[4]) {
         cout << "Spring" << endl;
      } else if (inputMonth == months[6] || inputMonth == months[7]) {
         cout << "Summer" << endl;
      } else if (inputMonth == months[9] || inputMonth == months[10]) {
         cout << "Autumn" << endl;
      } else {
         if (inputMonth == months[11]) {
            if (inputDay < 21) cout << "Autumn" << endl;
            else cout << "Winter" << endl;
         }
         if (inputMonth == months[2]) {
            if (inputDay < 20) cout << "Winter" << endl;
            else cout << "Spring" << endl;
         }
         if (inputMonth == months[5]) {
            if (inputDay < 21) cout << "Spring" << endl;
            else cout << "Summer" << endl;
         }
         if (inputMonth == months[8] && inputDay < 22) {
            if (inputDay < 22) cout << "Summer" << endl;
            else cout << "Autumn" << endl;
         }
      }
      
   } else {
      cout << "Invalid" << endl;
   }

   return 0;
}
