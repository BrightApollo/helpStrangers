/*
This program will flesh out the conflict detection we need for dates

Start date 2025-01-01 12:00 AM
Finish date 2025-05-31 11:59 PM

Concert A is on 2024-12-31 from 1800 �  2025-01-01-0400
Concert B is on 2025-05-31 from 1800 to 2025-06-01 0400
Concert C is on 2024-12-30 from 1800 to 2025-07-01 0000

202501010000 � 202505312359

The start date has to be between these, OR, the end date has to be between these to detect a CONFLICT
Let�s breakdown BETWEENness
testStart >= start && testStart <= end  (BETWEEN)
 OR
testEnd >= start && testEnd <= end (BETWEEN)
	OR
testStart <= start && testEnd >= end (COMPLETE OVERLAPness)

*/

#include <iostream>
#include <string>

//hw extend test for conflict and extend date stuff; test try start and try end dates

struct dateStuff{
    std::string yr;
    std::string mon;
    std::string day;
    std::string hr;
    std::string min;
    std::string wholeDt;
};

dateStuff getUserDate();
void showUserDate(dateStuff inDate);
void testForConflict(dateStuff inStart, dateStuff inEnd, dateStuff
startTryer, dateStuff endTryer);
std::string monFmt(int i);
std::string dayFmt(int i);
std::string hrFmt(int i);
std::string minFmt(int i);

int main(){

    dateStuff startDt{"2025","01","01","00","00","202501010000"}, endDt{"2025","05","31","23","59","202505312359"}, starttryDt{}, endtryDt{};

    std::cout << "Here's the start.\n";
    showUserDate(startDt);

    std::cout << "And here's the end.\n";
    showUserDate(endDt);

    std::cout << "Now enter the start date and time probe.\n";
    starttryDt = getUserDate();

    std::cout << "Now enter the end date and time probe.\n";
    endtryDt = getUserDate();

    std::cout << "Using the start time: ";
    showUserDate(starttryDt);
    
    std::cout << "And the end time: ";
    showUserDate(endtryDt);
    std::cout << "\n";
    
    testForConflict(startDt, endDt, starttryDt, endtryDt);

    return 0;
}

dateStuff getUserDate(){

    dateStuff inDate;
    int i {};

    std::cout << "Year? "; 
        std::cin >> inDate.yr; 
        inDate.wholeDt = inDate.yr; //4-dgit year guarantees string because I say so
    std::cout << "Month? "; 
        std::cin >> i;
        inDate.mon = monFmt(i);
        inDate.wholeDt += inDate.mon; 
        i = 0;
    std::cout << "Day? ";
        std::cin >> i; 
        inDate.mon = dayFmt(i);
        inDate.wholeDt += inDate.day;
        i = 0;
    std::cout << "Hour? ";
        std::cin >> i;
        inDate.hr = hrFmt(i);
        inDate.wholeDt += inDate.hr;
        i = 0;
    std::cout << "Minutes? ";
        std::cin >> i;
        inDate.min = minFmt(i);
        inDate.wholeDt +=inDate.min;

    return inDate;
}

void showUserDate(dateStuff inDate){
    std::cout << inDate.yr << "-";
    std::cout << inDate.mon << "-";
    std::cout << inDate.day << " ";
    std::cout << inDate.hr << ":";
    std::cout << inDate.min << "  /  ";
    std::cout << inDate.wholeDt << "\n";
}
//check this at tryer
void testForConflict(dateStuff inStart, dateStuff inEnd, dateStuff startTryer, dateStuff endTryer){
    if(inStart.wholeDt > inEnd.wholeDt){
        std::cout << "This is not right, end dates need to be after start dates." << std::endl;
    } else if (((startTryer.wholeDt >= inStart.wholeDt) && (startTryer.wholeDt <= inEnd.wholeDt)) ||
    	 ((endTryer.wholeDt >= inStart.wholeDt) && (endTryer.wholeDt <= inEnd.wholeDt)) ||
		 ((startTryer.wholeDt <= inStart.wholeDt) && (endTryer.wholeDt >= inEnd.wholeDt)) ) {
		std::cout << "Your trial IS in conflict with the dates!" << std::endl;
	} else {
        std::cout << "Your trial is not in the window.";
    }
}

std::string monFmt(int i) {
    std::string outStr{};
    while((i < 1) || (i > 12)) {
        std::cout << "Integer out of accepted month range.  Enter a new value: ";
        std::cin >> i;
    }

    if(i < 10) {
        outStr = "0" + std::to_string(i);
    } else {
        outStr = std::to_string(i);
    }
    return outStr;
}

std::string dayFmt(int i) {
    std::string outStr{};
    while((i < 1) || (i > 31)) {
        std::cout << "Integer out of accepted day range.  Enter a new value: ";
        std::cin >> i;
    }
    
    if(i < 10) {
        outStr = "0" + std::to_string(i);
    } else {
        outStr = std::to_string(i);
    }
    return outStr;
}

std::string hrFmt(int i){
    std::string outStr{};
    if((i < 0) || (i > 23)) {
        std::cout << "Integer out of accepted hour range.  Enter a new value: ";
        std::cin >> i;
    }
    
    if(i < 10) {
        outStr = "0" + std::to_string(i);
    } else {
        outStr = std::to_string(i);
    }
    return outStr;
}

std::string minFmt(int i){
    std::string outStr{};
    if((i < 0) || (i > 59)) {
        std::cout << "Integer out of accepted minute range.  Enter a new value: ";
        std::cin >> i;
    }
    
    if(i < 10) {
        outStr = "0" + std::to_string(i);
    } else {
        outStr = std::to_string(i);
    }
    return outStr;

}