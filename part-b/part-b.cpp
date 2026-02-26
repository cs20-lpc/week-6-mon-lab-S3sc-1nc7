#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/

void towerHanoi(int n, string r1, string r2, string r3, int& m) { //use second rod as helper rod
	if (n == 1) {
		cout << "Moving disc " << n << " from " << r1 << " to " << r3 << endl; //base case rod 1 -> rod 3
        m++;    
        return;
    }

	towerHanoi(n - 1, r1, r3, r2, m); // rod 1 -> rod 2
    cout << "Moving disc " << n << " from " << r1 << " to " << r3 << endl;
    m++;
	towerHanoi(n - 1, r2, r1, r3, m); //rod 2 -> rod 3
}

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Rod #1", "Rod #2", "Rod #3", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}
