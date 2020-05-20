#include <iomanip>
#include <vector>
#include "Figures/point.h"
#include "Figures/circle.h"
#include "Figures/line.h"
using namespace std;
int main() {
	cout << setprecision(2) << fixed;
	/*circle i;
	cin >> i;
	VectorList<circle> a(i);
	for (int j = 0; j < 1; j++) {
		cin >> i;
		a.add(i);
	}
	a.quickSort();
	a.output();*/
	vector<circle*> circles;
	vector<line*> lines;
	int control;
	do {
		cout << "Enter: \n 1 to create new circle \n 2 to create new linr \n 3 to see all circles  \n 3 to see all lines \n 4 to see all lines \n 0 to exit and press enter \n ";
		cin >> control;
		if (control == 1) {
			double x, y, r;
			cout << "Enter circle data in format \"X Y Radius \" : ";
			cin >> x >> y >> r;
			circles.push_back(new circle({ x,y }, r));
		}
		else if (control == 2) {
			double k, b;
			cout << "Enter line data in format \"k b \" (y = kx +b) : ";
			cin >>k >>b;
			lines.push_back(new line(k,b));
		}
		else if (control == 3) {
			for (int i = 0; i < circles.size(); i++)
				cout << i + 1 << ". " << *circles[i];
		}
		else if (control == 4) {
			for (int i = 0; i < lines.size(); i++)
				cout << i + 1 << ". " << *lines[i] ;
		}
	} while (control != 0);
	return 0;
}