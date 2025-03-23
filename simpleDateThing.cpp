#include <iostream>
#include <string>

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
void testForConflict(dateStuff inStart, dateStuff inEnd, dateStuff tryer);

int main(){

    dateStuff startDt{}, endDt{}, tryDt{};

    std::cout << "Enter a start date and time.\n";
    startDt = getUserDate();
    showUserDate(startDt);

    std::cout << "Enter a finish date and time.\n";
    endDt = getUserDate();  //test conflicts by setting end date, then we poke holes in it.
    showUserDate(endDt);

    std::cout << "Now enter a test probe date within the start and end.\n";
    tryDt = getUserDate();
    
    testForConflict(startDt, endDt, tryDt);

    return 0;
}

dateStuff getUserDate(){

    dateStuff inDate;

    std::cout << "Year? "; std::cin >> inDate.yr; inDate.wholeDt = inDate.yr;
    std::cout << "Month? "; std::cin >> inDate.mon; inDate.wholeDt += inDate.mon;
    std::cout << "Day? "; std::cin >> inDate.day; inDate.wholeDt += inDate.day;
    std::cout << "Hour? "; std::cin >> inDate.hr; inDate.wholeDt += inDate.hr;
    std::cout << "Minutes? "; std::cin >> inDate.min; inDate.wholeDt += inDate.min;

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

void testForConflict(dateStuff inStart, dateStuff inEnd, dateStuff tryer){
    if(inStart.wholeDt > inEnd.wholeDt){
        std::cout << "This is not right, end dates need to be after start dates." << std::endl;
    } else {
        if((tryer.wholeDt > inStart.wholeDt) && (tryer.wholeDt < inEnd.wholeDt)){
            std::cout << "Your trial is inside the dates!";
        } else {
            std::cout << "Your trial is not in the window.";
        }
    }
}