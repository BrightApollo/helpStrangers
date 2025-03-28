#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;


void print_ticket(vector<int>& my_ticket){
for(int i = 0; i<my_ticket.size();i++){
cout<<my_ticket[i]<<" ";
}
cout<<endl;
}

int main(){
int tmp;
int lower_bound = 1;
int upper_bound = 69;
int ticket_size = 5;
vector<int> my_ticket;

// the generator ===> generator algorithm + distribution definition
mt19937 random_generator_one_number_at_a_time(time(0)); // current time since 1970/1/1

// the data distribution that we will accept
uniform_int_distribution<> white_ball(1, 69);

for (int i = 0; i<ticket_size; i++){
tmp = white_ball(random_generator_one_number_at_a_time);
}

print_ticket(my_ticket);

// Pick five(5) numbers between 1-69 & one(1) Powerball number between 1-26.


}