// Optimal Coin Game
// Bradley Marques
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::ifstream;
using std::ofstream;
using std::vector;
int SolveCoinGameOptimally(vector<int>);
void main() {
	ifstream fin("coins.in");
	if (fin.is_open()) {
		ofstream fout("coins.out");

		// Main part of program goes here.  Use fin and fout for input and output.
		// May also use cout statements for debugging purposes.
		int number_of_coins_in_current_test_case;
		fin >> number_of_coins_in_current_test_case;
		while (number_of_coins_in_current_test_case > 0){
			int coin_values = 0;
			int number_of_coins_counter = number_of_coins_in_current_test_case;
			vector<int>game_board;
			while (number_of_coins_counter > 0) {
				fin >> coin_values;
				game_board.push_back(coin_values);
				number_of_coins_counter--;
			}
			int max_amount_of_money = SolveCoinGameOptimally(game_board);
			cout << max_amount_of_money << endl;
			fout << max_amount_of_money << endl;
			fin >>number_of_coins_in_current_test_case;
		}
		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}
int SolveCoinGameOptimally(vector<int>game_board){
	int size = game_board.size();
	// Create a 2D Vector that has all values initialized to zero.
	vector<vector<int>>moves(size, vector<int>(size,0));
	for (int index = 0; index < moves.size(); index++) {
		for(int i = 0, j = index; j < moves.size(); i++, j++ ){
			// Define the subproblems. I am assuming that the ith coin is the left and the jth coin is the right.
			int subproblem_one, subproblem_two, subproblem_three;
			// Subproblem 1 = if Marques chooses the ith coin and Dr. Baber
			// chooses ith coin + 1;
			if (i + 2 <= j) {
				subproblem_one = moves[i + 2][j];
			}
			else {
				subproblem_one = 0;
			}
			// Subproblem 2 = if Marques chooses the ith coin and Dr. Baber chooses the
			// jth coin. Or if Dr. Baber chooses the ith coin and Marques chooses the jth coin.
			if (i + 1 <= j - 1) {
				subproblem_two = moves[i + 1][j - 1];
			}
			else {
				subproblem_two = 0;
			}
			// Subproblem 3 = if Marques choose the jth coin and Dr. Baber chooses the jth coin - 1
			if (i <= j - 2) {
				subproblem_three = moves[i][j - 2];
			}
			else {
				subproblem_three = 0;
			}
			moves[i][j] = max(game_board[i] + min(subproblem_one, subproblem_two), game_board[j] + min(subproblem_two, subproblem_three));
		}
	}
	return moves[0][size - 1];
}
