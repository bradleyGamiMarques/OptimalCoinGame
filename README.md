# OptimalCoinGame
Solution to the Optimal Coin Game problem in Comp 349 Applied Algorithms

# Statement of the problem

Consider a single row of 𝑛 coins with values 𝑣1𝑣2 … 𝑣𝑛, where is 𝑛 is even and 𝑛 ≥ 2. We play a game against
an opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes it
from the row permanently, and receives the value of that coin. The object of the game is claim the largest amount
of money.

Given the values of coins that are arranged in a single row, determine the maximum possible amount of money
we can definitely win assuming the opponent plays optimally to keep our score as low as possible. We have the
first move.

# Input File (coins.in)

The input file contains several test cases, one per line. Each line contains 1 or more non-negative integers, separated by a
space. The first integer on a line, 𝑛 (where 0 ≤ 𝑛 ≤ 1000, 𝑛 𝑖𝑠 𝑒𝑣𝑒𝑛), is the number of coins in the current test case. The
rest of the line will contain 𝑛 integers, 𝑣1 𝑣2 … 𝑣𝑛 (where 0 ≤ 𝑣𝑖 ≤ 100), which are the values of the 𝑛 coins, listed in the
same order the coins are arranged for the game.
A value of 0 for 𝑛 indicates the end of the file

# Output File (coins.out)

For each test case, output the maximum possible amount of money we can win if we play first and the opponent plays
optimally, trying to make our total as low as possible.

# Sample input

2 5 10

4 10 25 1 5

6 0 5 5 8 9 8

8 0 0 0 0 0 100 0 0

6 100 99 98 97 96 95

6 95 96 100 100 96 95

2 0 0

0

# Sample output

10

30

21

100

294

291

0
