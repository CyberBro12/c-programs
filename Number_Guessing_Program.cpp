#include<iostream>
#include<string>
#include<algorithm>
#include<thread>
#include<chrono>
using namespace std;

void sleep(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}
int guess_the_number(int number){
    int halfresult = number+25;
    int result = 100-halfresult;
    return result;
}
int main(){

    cout << "     Number Guessing Program" << endl;
    cout << "Ready to start?" << endl;
    string rep;
    cout << "You> ";
    cin >> rep;
    transform(rep.begin(), rep.end(), rep.begin(), ::tolower);
    if (rep=="yes")
    {
        cout << "AI> First Think of a (Natural) Number to 100" << endl;
        sleep(5);
        cout << "AI> Now multiply that number by 2" << endl;
        sleep(5);
        cout << "AI> Now add 50" << endl;
        sleep(5);
        cout << "AI> Now divide the number by 2" << endl;
        sleep(5);
        cout << "AI> Now from 100 subtract the number" << endl;
        sleep(5);
        cout << "AI> Now all you need to tell me is the number you are left" << endl;
        int ad;
        cout << "You> ";
        cin >> ad;
        cout << "AI> The number you was thinking of is " << guess_the_number(ad) << endl;
        sleep(3);
        cout << "AI> Is that the number you was thinking?" << endl;
        string confirmation;
        cout << "You> ";
        cin >> confirmation;
        transform(confirmation.begin(), confirmation.end(), confirmation.begin(), ::tolower);
        if (confirmation=="yes")
        {
            cout << "AI> Thank you! for using program made by Ravi Sharma" << endl;
            sleep(5);
            exit(0);
        }
        else if (confirmation=="no")
        {
            cout << "AI> There must be a mistake in your calculations" << endl;
            cout << "AI> Try again" << endl;
            sleep(3);
        }
    }
    else if (rep=="no")
    {
        cout << "AI> Type Exit to exit" << endl;
        string ex;
        cout << "You> ";
        cin >> ex;
        transform(ex.begin(), ex.end(),ex.begin(), ::tolower);
        if (ex=="exit")
        {
            exit(0);
        }
        
    }
    else
    {
        cout << "AI> yes or no?" << endl;
    }
    
    
    return 0;
}
