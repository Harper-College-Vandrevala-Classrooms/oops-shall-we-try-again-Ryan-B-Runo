#include <iostream>
using namespace std;

string prompt(string promptText, string errorMessage, int lowerBound, int upperBound){
    int response;
    cout << promptText << "\n";
    cin >> response;

    if(lowerBound < response && response < upperBound){
        return to_string(response);
    }
    return errorMessage;
}

string prompt(string promptText, string errorMessage, int bound, bool boundIsUpper){
    int response;
    cout << promptText << "\n";
    cin >> response;

    if(boundIsUpper){
        if(response < bound){
            return to_string(response);
        }else{
            return errorMessage;
        }
    }else{
        if(response > bound){
            return to_string(response);
        }else{
            return errorMessage;
        }
    }
}

string prompt(string promptText){
    int response;
    cout << promptText << "\n";
    cin >> response;

    return to_string(response);
}

int main(){
    string value = "error";
    while(value == "error"){// both bounds
        value = prompt("Enter an int 0-100", "error", 0, 100);
        if(value != "error"){
            cout << "The value chosen by the user is " << value << "\n";
        }
    }
    value = "error";

    while(value == "error"){
        value = prompt("Enter an int (>100)", "error", 100, false);// lower bound
        if(value != "error"){
            cout << "The value chosen by the user is " << value << "\n";
        }
    }
    value = "error";

    while(value == "error"){
        value = prompt("Enter an int (<-20)", "error", -20, true);// upper bound
        if(value != "error"){
            cout << "The value chosen by the user is " << value << "\n";
        }
    }

    value = prompt("Enter an int:");
    cout << value << "\n";

    return 0;
}