#include <iostream>
#include "UserChains.h"

using namespace std;

int main() {
    int days;
    int i;
    //the seconds every tick counts for 30 seconds do the loop has to be repeated only 2880 times instead of 86400
    //the time will be multiplied by 30 within the chain
    int sec;
    UserChains a;
    a.add_lick(6,13,13,true);
    a.display();
    cout<<"give number of days you whant to rum simulation for : ";
    cin>>days;
    for (i=1;i<=days;i++){
        for (sec=1;sec<=2880;sec++){
            //where the inner workings will go
        }
    }

    return 0;
}
