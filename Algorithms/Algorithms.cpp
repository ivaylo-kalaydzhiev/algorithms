#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>

// Stack
// Queue

// Tree
// Binary Search Tree

// Understand abstract interface
// -> What does this structure give you
// -> What is it good for

// Understand implementation possibilities
// Understand algorithm implementation

// Make sure you know everything in
// -> The lecture
// -> The seminar
// -> The homework

// Stack
// -> Balancing braces

// Queue
// -> Hammand numbers
// -> Window sliding

using namespace std;

// ai, aj - first rotten apple
// ak, as - second rotten apple

void rottenApples(int n, int m, int days, int ai, int aj, int ak, int as, bool twoRotten) {
	vector<vector<int>> grid(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			grid[i][j] = abs(ai - i) + abs(aj - j);
		}
	}

	pair<int, int> p = { 1,2 };
	p.first;

	if (twoRotten) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) {
				int newValue = abs(ak - i) + abs(as - j);
				if (grid[i][j] > newValue) {
					grid[i][j] = newValue;
				}
			}
		}
	}

	int count = n * m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (grid[i][j] <= days) {
				count--;
			}
		}
	}

	std::cout << count << std::endl;
}

int main() {
	stack<int> st;

	st.push(12);
	st.push(11);
	st.push(2);

	st.top();

	queue<int> q;

	q.push(12);
	q.push(12);
	q.push(11);
	q.push(12);

	q.front();
	q.back();

	q.pop();
	st.pop();
}