#include <iostream>
using   std::cout;

#include <time.h>  // Import the ctime library
#include <string.h>

void testDating(){
    tm datetime = {};
    // Earliest that `mktime` accepts with Visual C++ and MinGW g++:

    datetime.tm_year = 1969 - 1900; // Number of years since 1900
    datetime.tm_mon = 6-1; // Number of months since January
    datetime.tm_mday = 19;
    // datetime.tm_hour = 13;
    // datetime.tm_min = 37;
    // datetime.tm_sec = 1;
    // Daylight Savings must be specified
    // -1 uses the computer's timezone setting
    // datetime.tm_isdst = 0; //-1;
    
    const time_t timestamp = mktime( &datetime );
    if( timestamp == -1 ) {
        cout << "!Gah, mktime failed: " << strerror( errno ) << ".\n";
    } else {
        // Note: there is a newline at the end of the string from `ctime`.
        cout << "Fling me around " << ctime(&timestamp) << " and around.\n";
    }
}

int main () { testDating(); }