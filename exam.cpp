#include <iostream>
#include <string>

using namespace std;

class chair
{
public:
	chair(string name_)
	{
		name = name_;
		cout << getName() << endl;
	}
private:
	string getName() { return name; }
private:
	string name;
};

int main(){
	chair c("lookip");
	cout << "End \n";
	return 0;
}
