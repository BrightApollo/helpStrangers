#include <algorithm> // <=== find and sort functions
#include <iostream>
#include <random>
#include <vector>
#include <chrono>
using namespace std::chrono_literals;

const int TICKET_SIZE = 5;
const int LOWER_BOUND = 1, UPPER_BOUND = 69;

void print_ticket(std::vector<int>& my_ticket);
std::string printedTicket(std::vector<int> inTicket);
bool ball_existed(std::vector<int>& my_ticket, int tmp, bool verbose);
std::vector<int> ticket_gen();
std::vector<int> ticketBuild();
bool result_check(std::string myChoices, std::string ballsChosen);

int main() {
    bool matched = false;
    int runs = 0;
    
    std::string myTick, pulledBalls;

    std::vector<int> my_ticket;
    std::vector<int> result;
    
    auto start = std::chrono::system_clock::now();
    const std::time_t startT = std::chrono::system_clock::to_time_t(start);
    
    //std::cout << "The system clock is currently at " << std::ctime(&startT);
    auto checkpoint = std::chrono::system_clock::now();
     
    std::cout << "Testing mode, we're picking numbers for speed starting at " << std::ctime(&startT) << std::endl;

    my_ticket = ticket_gen();
    myTick = printedTicket(my_ticket);  //turns it into a string
    
    // Get starting timepoint
    start = std::chrono::high_resolution_clock::now();
    do{
        result = ticket_gen();
        pulledBalls = printedTicket(result);    //turns it into a string
        if(myTick == pulledBalls) {
            matched = true;
        }
        runs++;
        if(runs%10000 == 0){
            checkpoint = std::chrono::high_resolution_clock::now();
            std::cout << "Run count: " << runs << " elapsed from start: " << std::chrono::duration_cast<std::chrono::milliseconds>(checkpoint - start) << " " << std::endl;
        }
    }while(!matched);

    auto end = std::chrono::system_clock::now();
    std::time_t endT = std::chrono::system_clock::to_time_t(end);
   
    std::cout << "Finished lottery pulls at " << std::ctime(&endT)
              << " elapsed time: " << std::chrono::duration_cast<std::chrono::seconds>(end - start) << " seconds" << std::endl;
    std::cout << "It took " << runs << " tries to win the lottery." << std::endl;
    
    return 0;

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

std::string printedTicket(std::vector<int> inTicket){
    std::string outString = "";
    //std::cout << "Your ticket has these numbers!!!\n";
    for(int i = 0; i < inTicket.size(); i++){
        if(inTicket[i] < 10){
            outString = outString + "0";
        }
        outString = outString + std::to_string(inTicket[i]);
    }
    return outString;
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
        return false;
    } else {
        if (verbose) {
            std::cout << tmp << ": Existing number";
        }
        return true;
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