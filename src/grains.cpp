// https://exercism.org/tracks/cpp/exercises/grains


// square counting convention: a1 is square 1, h1 is square 8 .... h8 is square 64

#include<iostream>
#include<map>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;


// --- prototypes ---
unsigned long long int board_sum(int);

int main()
{   system("cls");

    std::map<char,int> file_map = {{'a', 1},{'b', 2},{'c', 3},{'d', 4},{'e', 5},{'f', 6},{'g', 7},{'h', 8}};
    cout << "Enter the name of a chess square, first the letter (file) and then a number (rank):" << endl;
    char file = 'z'; int rank = 0;

    cin >> file;
    file = towlower(file);
    cin >> rank;

    int square_number = 8*(rank-1) + file_map[file]; 
    cout << "You entered " << file << rank << ", which is square number " << square_number << "." << endl;
    
    unsigned long long int square_count = pow(2, square_number - 1);
    cout << "There are " << square_count << " grains on this square." << endl; 
    cout << "There are " << board_sum(square_number) << " total grains on the board." << endl; 

    return 0;
}


// --- function definitions ---
unsigned long long int board_sum(int square_number)
{
    unsigned long long int total = 0;
    return (square_number == 1) ? 1 : pow(2, square_number - 1) + board_sum(square_number - 1);
}