#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

const int TICKET_SIZE = 5;
void print_ticket(std::vector<int>& my_ticket);

bool ball_existed(std::vector<int>& my_ticket, int tmp);

int main(){
    int tmp;
    int lower_bound = 1, upper_bound = 69;
    std::vector<int> my_ticket;
    bool isFound;

    // the generator ===> generator algorithm + distribution definition
    std::mt19937 random_generator_one_number_at_a_time(time(0)); // current time since 1970/1/1

    // the data distribution that we will accept
    std::uniform_int_distribution<> white_ball(1, 69);

    for (int i = 0; i < TICKET_SIZE; i++){
        tmp = white_ball(random_generator_one_number_at_a_time);
        //missing vector step here, adding now.
        my_ticket.push_back(tmp);
    }

    print_ticket(my_ticket);

    // Pick five(5) numbers between 1-69 & one(1) Powerball number between 1-26.

    //check the ticket
    // let's loop over 100 tries to see how many times any of the five numbers hit.
    for(int i = 0; i < 100; i++) {
        tmp = white_ball(random_generator_one_number_at_a_time);
        isFound = ball_existed(my_ticket, tmp);
        std::cout << "This is try number [" << i << "] ";
        if (isFound){  // we check both outcomes, not just one
            std::cout << "You hit on a number!  It was: " << tmp;
        }
        std::cout << std::endl;
    }

}

void print_ticket(std::vector<int>& my_ticket){
    std::cout << "Your ticket has these numbers!!!\n";
    for(int i = 0; i < my_ticket.size(); i++){
        std::cout << "[" << my_ticket[i] << "] [";
    }
    std::cout << std::endl;
}

bool ball_existed(std::vector<int>& my_ticket, int tmp) {
    
    auto found = find(my_ticket.begin(), my_ticket.end(), tmp);    
    
    if(found==my_ticket.end()){
        // uncomment for debugging std::cout << tmp << ": Not found";
        return false;   //should be returning TRUE or FALSE
    } else {
        // uncomment for debugging std::cout << tmp << ": Existing number";
        return true;
    }
}
    