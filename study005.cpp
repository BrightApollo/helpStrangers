#include <algorithm> // <=== find and sort functions
#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

void print_ticket(vector<int> &my_ticket) {
for (int i = 0; i < my_ticket.size(); i++) {
cout << my_ticket[i] << " ";
}
cout << endl;
}

bool ball_existed(vector<int> &my_ticket, int tmp, bool verbose) {
auto found = find(my_ticket.begin(), my_ticket.end(), tmp);

if (found == my_ticket.end()) {
if (verbose) {
cout << tmp << ": Not found";
}
return 0;
} else {
if (verbose) {
cout << tmp << ": Existing number";
}
return 1;
}
}

vector<int> ticket_gen() {
int tmp;
int lower_bound = 1;
int upper_bound = 69;
int ticket_size = 5;
vector<int> my_ticket;

// the generator ===> generator algorithm + distribution definition
mt19937 random_generator_one_number_at_a_time(
time(0)); // current time since 1970/1/1

// the data distribution that we will accept
uniform_int_distribution<> white_ball(1, 69);

while (my_ticket.size() < 5) {
tmp = white_ball(random_generator_one_number_at_a_time);

bool found = ball_existed(my_ticket, tmp, false);

while (found != 0) { // if number exist, try to generate another number;
tmp = white_ball(random_generator_one_number_at_a_time);
found = ball_existed(my_ticket, tmp, false);
}

// this means, after the while, the number is new for real
my_ticket.push_back(tmp);
}

sort(my_ticket.begin(), my_ticket.end());

return my_ticket;
}

double result_check(vector<int>& result, vector<int>& ticket){ // sorted only
int match_white_ball_count = 0;

for (int i = 0; i<ticket.size();i++){
if (result[i] == ticket[i]){
match_white_ball_count += 1;
}
}

if (match_white_ball_count == 5){
return 1000000;
} else if (match_white_ball_count == 4){
return 50000;
} else if(match_white_ball_count>1) {
return 4;
} else {
return 0;
}




}


int main() {
vector<int> my_ticket = ticket_gen();

vector<int> result = ticket_gen();
print_ticket(my_ticket);

print_ticket(result);

double my_win = result_check(result, my_ticket);

if(my_win>0){
cout<<"You won: "<<my_win;
} else {
cout<<"Try again. Sorry";
}

// Pick five(5) numbers between 1-69 & one(1) Powerball number between 1-26.
}