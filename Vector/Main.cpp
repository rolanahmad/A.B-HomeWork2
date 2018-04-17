#include "Vector.h"

void main() {
	Vector v1(10);

	v1.push_back(15);
	v1.print(); cout << "\n";

	v1.push_this(3,10);
	v1.print(); cout << "\n";

	v1.delete_this(3);
	v1.print(); cout << "\n";

	v1.at(3);
	v1.print(); cout << "\n";

	system("pause");
}