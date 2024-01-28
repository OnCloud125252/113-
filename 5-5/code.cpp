#include <iostream>
#include <random>
using namespace std;

int main(int argc, char** argv) {
	int randNum= 10 + rand() % (20 -10 + 1); 
	cout << randNum;
	
	return 0;
}
