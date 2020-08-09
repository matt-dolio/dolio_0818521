#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Stock {
	string symbol;
	double price, change;
};

class Special {
	public:
		string helloworld;
	private:
		int numbers;
};

int main() {	
	Special newone;
	ifstream ins("/public/stock_ticker"); // This is how you open a file for reading
	// We read from ins like we would cin
	string s;
	ins >> s;
	cout << "This is the stock report for " << s << endl;
	vector<Stock> vec;
	while (ins) {
		Stock temp;
		ins >> temp.symbol >> temp.price >> temp.change;
		if (!ins) break;
		vec.push_back(temp);
	}
	ins.close();
	for (Stock s : vec) {
		cout << "Stock name: " << s.symbol << " Price: " << s.price << " Change: " << s.change << endl;
	}
	// Find stock with highest price
	Stock max; // Stock with highest price;
	max.price = -1;
	max.symbol = "ERROR STOCK";
	for (Stock s : vec) {
		if (s.price > max.price)
			max = s;
	}
	cout << "Most expensive stock: " << max.symbol << endl;

	return 0;
}
