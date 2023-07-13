#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define IP "192.168.1.13"
#define packet 10
using namespace std;

int add(int a, int b)
{
  return a + b;
}

int main() {
	float data = packet;

	cout << "data : " << data << endl;
	string ip = IP;
	cout << ip << endl;
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        cout << add(v[0], v[1]) << endl;
	return 0;
}
