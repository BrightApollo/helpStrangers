/*
6. A city cab service provider charges customers based on distance and time. The
service charges $2 for the first two kilometers. After the first two kilometers,
the service charges $0.50 per kilometer for the next six kilometers. After six
kilometers, the customer is charged $1 per kilometer. At the end of the ride, a fee
of $0.2 per minute is charged based on the total travel duration. Write a program
that reads the distance traveled in kilometers and the time taken in minutes for a
cab ride and computes the fare based on the service's charges.

Also this cab company suuuuuuuuuuuuuuuuuuuuuuuuucks.

Sample output:
    How far did you go, in kilometers? 17
    And how long did you ride, in minutes? 32
    Your ride time cost $6.4 and your travel time cost $14 for a grand total fare of $20.4
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main () {

    double inKlicks = 12.0;
    double inMin = 8.0;

    double perMin = 4.3;
    double distanceCost = 18.250;

    cout.precision(2);

    perMin = inMin * 0.2;

    cout << "Your ride time cost $" << fixed << perMin;
    cout << " and your travel time cost $" << fixed << distanceCost;
    cout << " for a grand total fare of $" << fixed << distanceCost + perMin << endl;

    return 0;

}