/*
This program will flesh out the conflict detection we need for dates

Start date 2025-01-01 12:00 AM
Finish date 2025-05-31 11:59 PM

Concert A is on 2024-12-31 from 1800 –  2025-01-01-0400
Concert B is on 2025-05-31 from 1800 to 2025-06-01 0400
Concert C is on 2024-12-30 from 1800 to 2025-07-01 0000

202501010000 – 202505312359

The start date has to be between these, OR, the end date has to be between these to detect a CONFLICT
Let’s breakdown BETWEENness
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

    testForConflict(startDt, endDt, starttryDt, endtryDt);

    return 0;
}

dateStuff getUserDate(){

    dateStuff inDate;

    std::cout << "Year? "; std::cin >> inDate.yr; inDate.wholeDt = inDate.yr;
    std::cout << "Month? "; std::cin >> inDate.mon; inDate.wholeDt += inDate.mon;
    std::cout << "Day? "; std::cin >> inDate.day; inDate.wholeDt += inDate.day;
    std::cout << "Hour? "; std::cin >> inDate.hr; inDate.wholeDt += inDate.hr;
    std::cout << "Minutes? "; std::cin >> inDate.min; inDate.wholeDt +=inDate.min;

    return inDate;
}

void showUserDate(dateStuff inDate){
    std::cout << inDate.yr << "-";
    std::cout << inDate.mon << "-";
    std::cout << inDate.day << " ";
    std::cout << inDate.hr << ":";
    std::cout << inDate.min << "\n";
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
