#include "GameHeader.h"

int getPosition(int row, int column) {
	return row * 4 + column;
}

int getRow(int position) {
	return position / 4;
}

int getColumn(int position) {
	return position % 4;
}

matrix field::data() {
	return field_;
}
void field::show() {
	system("cls");
	std::cout << "_________________________________\n";
	for (int i = 0; i < 4; ++i) {
		std::cout << "|";
		for (size_t j = 0; j < 4; j++)
		{
			std::cout << field_[i][j] << "\t";
		}
		std::cout << "|\n";
	}
	std::cout << "_________________________________\n";
}
int fib(int n) {
	int pred = 0; int posl = 1;
	for (int i = 2; i <= n; i++)
	{
		int tmp = posl;
		posl += pred;
		pred = tmp;
	}
	return posl;
}
int main() {
	for(int i = 1; i < 20; ++i)
		cout << fib(i) << " ";
 }