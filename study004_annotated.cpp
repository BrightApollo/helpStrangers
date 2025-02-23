/*
    This is a meaningful refinement of the ticket-generation code, because it checks the current ticket
    against the current random pull, and makes sure our ticket has no duplicates
    We can probably skip including ctime with some minor changes, but it's not hurting us here.
*/
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

const int TICKET_SIZE = 5;
void print_ticket(std::vector<int>& my_ticket);
bool ball_existed(std::vector<int>& my_ticket, int tmp, bool verbose);
std::vector<int> ticket_gen();

int main() {
    std::vector<int> my_ticket = ticket_gen();
    print_ticket(my_ticket);

    // Pick five(5) numbers between 1-69 & one(1) Powerball number between 1-26.
}

void print_ticket(std::vector<int>& my_ticket){
    std::cout << "Your ticket has these numbers!!!\n";
    for(int i = 0; i < my_ticket.size(); i++){
        std::cout << "[" << my_ticket[i] << "] ";
    }
    std::cout << std::endl;
}
    
bool ball_existed(std::vector<int>& my_ticket, int tmp, bool verbose) {
    
    // understand this function call to "find"
    // "auto" means the compiler determines the variable type
    // the paramters state a starting position, end position, and variable to test against the vector value being examined
    auto found = find(my_ticket.begin(), my_ticket.end(), tmp);

    /*
        Your professor is being cute.  "verbose" is simulating a DEBUG flag, which we use to turn on debugging
        for a program.  It is usually set "at the top" and captured on a command line for compilation time evaluation.found
        This method here is suitable for small programs, not a bad technique.
    */
    if (found == my_ticket.end()) {     // so one side effect of the function is that the found value will be -1 if it falls off the end
        if (verbose) {
            std::cout << tmp << ": Not found";
        }
        return 0;
    } else {
        if (verbose) {
            std::cout << tmp << ": Existing number";
        }
        return 1;
    }
}
    
std::vector<int> ticket_gen() {
    int tmp;
    int lower_bound = 1, upper_bound = 69;
    bool isFound;
    std::vector<int> my_ticket;
    
    // the generator ===> generator algorithm + distribution definition
    std::mt19937 random_generator_one_number_at_a_time(
    std::time(0)); // current time since 1970/1/1
    
    // the data distribution that we will accept
    std::uniform_int_distribution<> white_ball(1, 69);
    
    // technically for/while loops are compiled down to the same code, but the convention 
    // you will see most often for seeding a set of number or values will have a for-loop
    // you need to learn how to use a while-loop so I suppose this is fine, but in real life
    // this would be /weird/
    while(my_ticket.size() < 5) {
        tmp = white_ball(random_generator_one_number_at_a_time);
    
        // changed the var declaration to up top and made the var readable
        isFound = ball_existed(my_ticket, tmp, false);  // note if you change this to "true" in the function you will get more output
    
        while (isFound) { // if number exists, try to generate another number;
            tmp = white_ball(random_generator_one_number_at_a_time);
            isFound = ball_existed(my_ticket, tmp, false);
        }
    
        // this means, after the while, the number is new for real
        my_ticket.push_back(tmp);
    }
    
    return my_ticket;
}
    