/*
4. Negotiating a consumer loan is not always straightforward. One form of loan is the
discount installment loan, which works as follows. Suppose a loan has a face value
of $1,000, the interest rate is 15%, and the duration is 18 months. The interest is
computed by multiplying the face value of $1,000 by 0.15, yielding $150. That
figure is then multiplied by the loan period of 1.5 years to yield $225 as the total
interest owed. That amount is immediately deducted from the face value, leaving
the consumer with only $775. Repayment is made in equal monthly installments
based on the face value. So the monthly loan payment will be $1,000 divided by 18,
which is $55.56. This method of calculation may not be too bad if the consumer
needs $775, but the calculation is a bit more complicated if the consumer needs
$1,000. Write a program that will take three inputs: the amount the consumer needs
to receive, the interest rate, and the duration of the loan in months. The program
should then calculate the face value required in order for the consumer to receive
the amount needed. It should also calculate the monthly payment.

x - (x * int * dur) = amt I need
x = amt I need / ((int * dur) - 1)


Sample output:
    tell me how much you need: 1000.00
    tell me how long you need to pay it back, in years: 4
    tell me the interest rate in decimal: 0.0625
    great.
    Your loan amount is: 1333.33 and that'll be in equal payments of 27.7778 for 48 months.
*/

#include <iostream>
#include <cmath>

using namespace std;

    double interest = 0.0;
    double payDur = 0.0;
    double targAmt = 0.0;

int main() {

    return 0;

}