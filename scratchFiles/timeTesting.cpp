/*
    play with time
*/

#include <iostream>
#include <ctime>  // Import the ctime library

void testDating();

int main () {
    
    testDating();
    
    return 0;
}

void testDating(){
    struct tm datetime;
    time_t timestamp;
  
    datetime.tm_year = 1969 - 1900; // Number of years since 1900
    datetime.tm_mon = 6 - 1; // Number of months since January
    datetime.tm_mday = 19;
    datetime.tm_hour = 3;
    datetime.tm_min = 37;
    datetime.tm_sec = 1;
    // Daylight Savings must be specified
    // -1 uses the computer's timezone setting
    datetime.tm_isdst = -1;
  
    timestamp = mktime(&datetime);
  
    std::cout << ctime(&timestamp);
}
