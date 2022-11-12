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
int maint() { return 0; }