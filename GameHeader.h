#pragma once
#include <iostream>
#include <vector>
using matrix = std::vector<std::vector<int>>;
using std::cin; using std::cout;

bool run = true;
int getPosition(int, int);
int getRow(int);
int GetColumn(int);
class field {
private:
	matrix field_ = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
public:
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	matrix data();
	void fill(std::vector<int>);
	void show();
	std::vector<int> free();
	void rowUp(matrix, int );
};


