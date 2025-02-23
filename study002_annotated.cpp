#include <iostream>
#include <vector>
#include <random>
#include <ctime>

void print_ticket(std::vector<int>& my_ticket);  //assumption here is my_ticket will be the address of a vector

int main(){
    int tmp;
    int lower_bound = 1;
    int upper_bound = 69;
    int ticket_size = 5;
    std::vector<int> my_ticket;

    // surprisingly good description of what we are doing here
    // the generator ===> generator algorithm + distribution definition
    std::mt19937 random_generator_one_number_at_a_time(time(0)); // current time since 1970/1/1

    // the data distribution that we will accept
    std::uniform_int_distribution<> white_ball(1, 69);

    /*
    The way most people might do this in C++
        // NEED RANDOM NUM GENERATOR
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    */

    for (int i = 0; i < ticket_size; i++){
        tmp = white_ball(random_generator_one_number_at_a_time);
        //missing vector step here, adding now.
        my_ticket.push_back(tmp);
    }

    print_ticket(my_ticket);

    // Pick five(5) numbers between 1-69 & one(1) Powerball number between 1-26.
    // we're looking for user inut here?

}

void print_ticket(std::vector<int>& my_ticket){
    std::cout << "Here we are in the function! " << std::endl;  
    for(int i = 0; i<my_ticket.size();i++){

        std::cout <<my_ticket[i] << " ";
    }
    std::cout << std::endl;
}
    