/*
3. An organization intends to get people to sponsor the education of underprivileged
children. As part of their program, they launch a website where people can register
by entering their details and the amount (in USD) they wish to sponsor each
month. The website calculates the number of children the donor can sponsor based
on the amount required to educate one child.
Write a program that inputs the amount required for one child's education, and
the amount a person is willing to sponsor, and calculates how many children
can be sponsored by that person. The program should also print how much of
the person's amount is remaining after calculating the number of children, and
suggest how many more dollars would educate another child. (Hint: Use a do
while loop)
*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main () {

    double educateAmt = 0.0;
    double donorAmt = 0.0;
    double moreDollars = 0.0;
    int factorAmt;

    std::cout << "How much does it cost to educate one child? "; std::cin >> educateAmt;
    std::cout << "What sized monthly donation did you receive? "; std::cin >> donorAmt;

    if(donorAmt < educateAmt){
        std::cout << "Find a friend to match your donation.  Every little bit helps." << std::endl;
    } else {
    }

    return 0;
}