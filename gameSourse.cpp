#include "GameHeader.h"
#include<random>
int getPosition(int row, int column) {
	return row * 4 + column + 1;
}

int getRow(int position) {
	return (position - 1) / 4;
}

int GetColumn(int position) {
	return (position - 1) % 4;
}

matrix field::data() {
	return field_;
}
void field::show() {
	//system("cls");
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
std::vector<int> field::free() {
	std::vector<int> free;
	for (size_t i = 1; i <= 16; i++)
	{
		if (field_[getRow(i)][GetColumn(i)] == 0) {
			free.push_back(i);
		}
	}
	return free;
}
void field::fill(std::vector<int> free) {
	srand((unsigned)time(NULL));
	int pos = free[rand() % free.size()];
	field_[getRow(pos)][GetColumn(pos)] = 2;
}

int main() {
	srand((unsigned)time(NULL));
	field field;
	field.fill(field.free());
	field.show();
	field.fill(field.free());
	field.show();
	field.fill(field.free());
	field.show();
	
	return 0;
}