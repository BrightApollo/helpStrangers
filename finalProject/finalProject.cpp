/*
Some crazy project, implement Google Calendar

Stub out 
    Event Search and Retrieval, so mock events
    Event Conflict Detection
    Event notification System

Schedule or calendar application
Events, participants.
Events have start and end times
Events have a location
Events have names, descriptions, and unique identifiers.
Participants have names and unique identifiers.

Stretch goals:
    Locations have hours of operation.
    Locations have maximum capacities.
    The intersection of an event and participant and locations is an enrollment.

(4) wants an Event class that allows you to find an event.  
An event should be searchable by name, description (hard, needs a string search), ID, date-time, location, open enrollment.

(5) wants an Event class, a Location class, a Participant class.  
This could be: is an event trying to book into a location with an existing event?  
Is a participant booking attendance at an event that conflicts with an existing enrollment?

(10) wants an Enrollment class that looks at Events occurring each minute.  
If the event is now-occurring, get a list of enrollees (participants) who have opted-in to notifications.  
Send notes to them.  
OR more advanced, allow participants to decide when the notification gets generated, i.e. two weeks, one week, three days, etc.  
Then build a scheduler to push alarms onto a list.  
List is checked every minute or five minutes.  
If notification has been tripped, delete the alarm or mark as "sent".

Event methods
Event (constructor)
	Default when blank
	With date and time, name, description, location
	With name, description, location
	With name, description
getEvent(location)
getEvent(date time)
getEvent(name)
getEvent(event ID)
setEvent(new location)
setEvent(new datetime)
checkEvent(using another Event, for conflict)

Participant methods
Participant (constructor)
	Default when blank
	With name
getParticipantID()
getParticipantName()

Location methods
Location (constructor)
	Default when blank
	Name and capacity
	Name only
getLocationCapacity
getLocationCapacity
getTimeSlots
getTimeSlots(single day)
getTimeSlots(date range)
setTimeSlot(day)
setTimeSlot(day pattern, days)

EventCalendar methods
EventCalendar (constructor)
	Default when blank (next month)
addLocation
addEvent (location)
addEventTimeSlot(event plus location, timeslot choices)
checkConflict(-- will check locations overbooked)

*/

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

class Location{
    public:
        Location();
    private:
        std::string locName;
        int maxCap; //maximum capacity
};

class Event {
    public:
        Event();
	    Event(tm inDate, std::string inName, std::string inDesc, Location inLoc);
        Event(std::string inName, std::string inDesc, Location inLoc);
        Event(std::string inName, std::string inDesc);
        Event getEvent(Location inLoc);
        Event getEvent(tm inDate);
        Event getEvent(std::string inName);
        Event getEvent(int tryID);
        void setEventLoc(Location inLoc);
        void setEventTime(tm inDate);
        void checkOverlap(Event inEvent);
    private:
        int eventID;    // need this to be global distinct
        std::string name;
};

class Participant{
    public:
        Participant(std::string inName);
        int getParticipantID();
        std::string getParticipantName();
    private:
        int partID;
        std::string name;
};

void testDating();

int main () {
    
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