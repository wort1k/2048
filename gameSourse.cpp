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
	system("cls");
	std::cout << "_________________________\n";
	for (int i = 0; i < 4; ++i) {
		std::cout << "|";
		for (size_t j = 0; j < 4; j++)
		{
			std::cout.width(6);
			if (field_[i][j] == 0)
			{
				std::cout.width(6);
				std::cout << " |";
			}
			else {
				std::cout.width(5);
				std::cout << field_[i][j] << "|";
			}
		}
		std::cout << "\n_________________________\n";
	}
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
	if (free.empty()){
		run = false;
	}
	else {
		int pos = free[rand() % free.size()];
		int n = 2;
		if (rand() % 5 == 0)
		{
			n = 4;
		}
		field_[3][GetColumn(1)] = n;
	}
}

void field::rowUp(matrix before, int row) {

	for (int i = row; i > 0; --i) {
		for (size_t j = 0; j < field_[0].size(); j++) {
			if (field_[i][j] ==  field_[i - 1][j] == before[i - 1][j] != 0)
			{
				field_[i - 1][j] *= 2;
				field_[i][j] = 0;
			}
			else if (field_[i - 1][j] == 0 && field_[i][j] != 0) {
				field_[i - 1][j] = field_[i][j];
				field_[i][j] = 0;
			}
		}
	}
}

void field::moveUp() {
	matrix before = field_;
	for (size_t i = 1; i < field_.size(); i++) {
		field::rowUp(before,i);
	}
}
	

int main() {
	field field;
	while (run)
	{
		field.fill(field.free());
		field.show();
		system("pause");
		field.moveUp();
		field.show();
		system("pause");
	}
	std::cout << " Game Over";
}