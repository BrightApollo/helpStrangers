#include <algorithm> // <=== find and sort functions
#include <ctime>    // we can seed a random function generator using std::random_device rd instead of time()
#include <iostream>
#include <random>
#include <vector>

const int TICKET_SIZE = 5;
const int LOWER_BOUND = 1, UPPER_BOUND = 69;

void print_ticket(std::vector<int>& my_ticket);
bool ball_existed(std::vector<int>& my_ticket, int tmp, bool verbose);
std::vector<int> ticket_gen();
std::vector<int> ticketBuild();
int result_check(std::vector<int>& result, std::vector<int>& ticket);

int main() {
    int winnings;
    char choice = 'Z';
    std::vector<int> my_ticket;
    std::vector<int> result;

    std::cout << "Do you want to pick five (5) numbers between 1-69? 'y' to choose, 'n' to have the machine pick them: ";
    std::cin >> choice;
    
    if(choice == 'y') {
        my_ticket = ticketBuild();
    } else {
        my_ticket = ticket_gen();
    }
    std::cout << "Your ticket:         ";
    print_ticket(my_ticket);
    std::cout << std::endl;

    result = ticket_gen();
    std::cout << "The winning numbers: ";
    print_ticket(result);
    std::cout<< std::endl;

    winnings = result_check(result, my_ticket);

    if(winnings > 0){
        std::cout << "You won: " << winnings;
    } else {
        std::cout << "Try again. Sorry";
    }

    // Pick five(5) numbers between 1-69 & one(1) Powerball number between 1-26.
}

void print_ticket(std::vector<int>& my_ticket){
    //std::cout << "Your ticket has these numbers!!!\n";
    for(int i = 0; i < my_ticket.size(); i++){
        std::cout << "[";
        if(my_ticket[i] < 10){
            std::cout << "0";
        }
        std::cout << my_ticket[i] << "] ";
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
    int LOWER_BOUND = 1, UPPER_BOUND = 69;
    bool isFound;
    std::vector<int> newTicket; //brand-new ticket!!!
    
    // the generator ===> generator algorithm + distribution definition
    std::random_device rd;  // a seed source for the random number engine, better than time(0)
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> white_ball(LOWER_BOUND, UPPER_BOUND);  //use the vars
    
    // technically for/while loops are compiled down to the same code, but the convention 
    // you will see most often for seeding a set of number or values will have a for-loop
    // you need to learn how to use a while-loop so I suppose this is fine, but in real life
    // this would be /weird/
    while(newTicket.size() < 5) {
        tmp = white_ball(gen);
    
        // changed the var declaration to up top and made the var readable
        isFound = ball_existed(newTicket, tmp, false);  // note if you change this to "true" in the function you will get more output
    
        while (isFound) { // if number exists, try to generate another number;
            tmp = white_ball(gen);
            isFound = ball_existed(newTicket, tmp, false);
        }
    
        // this means, after the while, the number is new for real
        newTicket.push_back(tmp);
    }
    sort(newTicket.begin(), newTicket.end());
    
    return newTicket;
}
 
std::vector<int> ticketBuild() {
    int tmp;
    bool isFound;
    std::vector<int> newTicket; //brand-new ticket!!!
    
    do {
        std::cout << "Enter a new number between " << LOWER_BOUND << " and " << UPPER_BOUND << " :"; std::cin >> tmp;
        isFound = ball_existed(newTicket, tmp, false);
        
        while(isFound || (tmp < LOWER_BOUND) || (tmp > UPPER_BOUND)) { 
            std::cout << "Enter a new number:"; std::cin >> tmp;
            isFound = ball_existed(newTicket, tmp, false);
        }
        newTicket.push_back(tmp);
    } while(newTicket.size() < 5);

    sort(newTicket.begin(), newTicket.end());
    
    return newTicket;
}

int result_check(std::vector<int>& result, std::vector<int>& ticket){ // sorted only
    int match_white_ball_count = 0;
    
    for (int i = 0; i < result.size(); i++){    //note the for-loop is not an iterator, because we need the side-effect
        for(int j = 0; j < ticket.size(); j++){
            if (result[i] == ticket[j]){
              match_white_ball_count += 1;
            }
        } //prior version scanned both indices in lockstep, which is not correct
    }

    /* we're going to do a case-switch below to show how that does if else
    if (match_white_ball_count == 5){
        return 1000000;     //honestly we should return strings but let it go
    } else if (match_white_ball_count == 4){
        return 50000;
    } else if(match_white_ball_count>1) {
        return 4;
    } else {
        return 0;
    }
    */
    
    switch(match_white_ball_count){    //switch(var) means test this variable against one or more cases
        case 5: return 1000000;     //honestly we should return strings but let it go
            break;
        case 4: return 50000;
            break;
        case 3: //fall through
        case 2: //fall through
        case 1: return match_white_ball_count;    //a little trick to return a double
            break;  // shuldn't reach this because we have a return
        case 0: return 0;
            break;
        default: return -1; //we are trapping a count value that isn't an integer between 0 and 5.
            break;
    }
}