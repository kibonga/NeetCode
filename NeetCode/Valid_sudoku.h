#pragma once
#include <vector>
#include <map>
using namespace std;

int valid_sudoku(vector<vector<int>>& vec) {
	map<tuple<int, int>, int> rows;
	map<tuple<int, int>, int> cols;
	map<tuple<int, int, int>, int> sqrs;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 6 && j == 8) {
				int temp = 7;
			}
			if (i == 8 && j == 7) {
				int temp2 = 7;
			}
			int val = vec[i][j];

			if (val == 0) continue;

			int row = rows[make_tuple(i, val)];
			int col = cols[make_tuple(j, val)];
			int sqr = sqrs[make_tuple((i / 3), (j / 3), val)];


			if (val == rows[make_tuple( i, val )] ||
				val == cols[make_tuple( j, val )] ||
				val == sqrs[make_tuple( (i / 3), (j / 3), val )] ) {
				return 0;
			}

			rows[make_tuple(i, val)] = val;
			cols[make_tuple(j, val)] = val;
			sqrs[make_tuple((i / 3), (j / 3), val)] = val;
		}
	}
	return 1;
}