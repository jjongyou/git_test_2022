#include <iostream>
#include <thread>
using namespace std;

int main(){

	unsigned int num;
	num = thread::hardware_concurrency();
	cout << "thread num : " << num << endl;
	return 0;
}
	
