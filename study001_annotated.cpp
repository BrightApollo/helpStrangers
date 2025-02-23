/*
    This program shows the dfference between pass-by-value and pass-by-reference.alignas
    Pass-by-value makes a copy of the number, passes it to the function, 
        and whatever happens to that value is restricted to the copy
    Pass-by-reference passes the actual address of the value (where it lives in memory) 
        and passes that to the function.  If you change the value inside the program it changes
        the value at the address.  This means that variable is changed for the entire declared
        scope of the variable.
*/

#include <iostream>
// using namespace std;
// we don't need to use namespace restrictions.  Learn to type.  Stroustrup doesn't do this, we won't either.

// forget "promises".   The "int" at the beginning of the function declaration states that an "int" will be returned
// also, good style says we just declare the function "signature" here: the return value, function name, and params
int update_phone_number(int old_phone_num);  

// true, no "return" statement, but by now when you see "void" you need to know that this means the return value is void
void update_phone_number_by_ref(int& old_phone_num);  //there should not be any return statement

int main(){
    // review function
    int my_phone_number = 123;
    int your_phone_number = 678;

    std::cout << "Before: " << my_phone_number << std::endl;

    // we're not doing try..catch here so saying "catch the returned value" is not correct
    // In C we would say we handle the return code or handle the return value.
    // Same applies.  You can call a function that returns an int without setting that
    // function equal to a variable... but you didn't do anything with that returned value -- you didn't handle it.
    // try..catch is something more advanced, and is actually rooted in Java coding, so forget it here.
    // just think "handle the return code"
    my_phone_number = update_phone_number(my_phone_number); // catch the returned value

    std::cout << "After: " << my_phone_number << std::endl;

    //This is pretty basic.
    //You can also write, and may write it this way more often, as follows:
    /*
        std::cout << "This is the phone number before: " << my_phone_number;
        std::cout << " and this is after: " << update_phone_number(my_phone_number);
        std::cout << std::endl;

        This is style, but it lets you see a stack of related statements quickly. 
    */

    std::cout << "YPN Before: " << your_phone_number << std::endl;
    //remember, this is not really "in-place", no one talks about it like that
    //this is "we change the value as if we re-declared it"
    update_phone_number_by_ref(your_phone_number); // the in-place update, no-catch needed
    std::cout << "YPNAfter: " << your_phone_number << std::endl;

    return 0;
}

// we put function bodies for the declared functions here.  
int update_phone_number(int old_phone_num){  
    return old_phone_num + 1;
}

void update_phone_number_by_ref(int& old_phone_num){
    // here we increment the value stored at the declared scope.
    // scope is important and needs to be understood.
    // in this context this means we didn't copy a value to make it scoped to only this function; rather
    // we gave this function a pointer to the variable's point of declaration, which means it is can be changed
    // in that *wider scope*.
    old_phone_num += 1; //update in place
}
    