#include <iostream>
#include <random>
#include <ctime>
using namespace std;
class random_waypoint_system{
private:
    int x;int y;int startpoint_x;int startpoint_y ; int objective_x ; int objective_y;
public:
    //initial constructor
    random_waypoint_system(){
        //random number for everything
        startpoint_x =rand()%100;
        startpoint_y = rand()%100;
        objective_x = rand()%100;
        objective_y = rand()%100;
    }
    //adds a new objective if you wish
    void new_objectives(){
        objective_x=rand()%100;
        objective_y=rand()%100;
        cout<<"new objectives"<<endl;
        cout<<objective_x<<"      "<<objective_y<<endl;
    }

    //getters
    int get_startpoint_x(){
        return startpoint_x;
    }
    int get_startpoint_y(){
        return startpoint_y;
    }
    int get_objective_x(){
        return objective_x;
    }

    int get_objective_y(){
        return objective_y;
    }
    //to perpatima oso dougrou paei
    void walk() {
        int distance_y = startpoint_y - objective_y;
        distance_y = abs(distance_y);
        int distance_x = startpoint_x - objective_x;
        distance_x = abs(distance_x);
        if (startpoint_x < objective_x) {
            startpoint_x = startpoint_x + (rand() % 3) + 2;
        } else if (startpoint_x > objective_x) {
            startpoint_x = abs(startpoint_x - ((rand() % 3) + 2));
        } else if (distance_x < 5) {//an einai kato apo 5 apostas tote dn kathom na to kano random and shit o bazw amesos
            if (startpoint_x < objective_x) {
                startpoint_x = startpoint_x + distance_x;
            } else if (startpoint_x > objective_x) {
                startpoint_x = abs(startpoint_x - distance_x);
            }

        }
        if (startpoint_y < objective_y) {
            startpoint_y = startpoint_y + ((rand() % 3) + 2);

        } else if (startpoint_y > objective_y) {
            startpoint_y = abs(startpoint_y - ((rand() % 3) + 2));
        } else if (distance_y < 5) {//same me to apo pano
            if (startpoint_y < objective_y) {
                startpoint_y = startpoint_y + distance_y;
            } else if (startpoint_y > objective_y) {
                startpoint_y = abs(startpoint_y - objective_y);

            }
        }
        cout << startpoint_x << "  " << startpoint_y << endl;
    }

    //just a testing function nothing more
    //shows the original values
    void print(){
        cout<<startpoint_x<<"    "<<startpoint_y<<endl;
        cout<<objective_x<<"    "<<objective_y<<endl;
    }
};
int main() {
    srand(time(0));//very important
    random_waypoint_system a;
    //print before walking
    a.print();
    //walks until everything is where it should be
    for (int i;i<100;i++){
        a.walk();
        if(a.get_startpoint_y()==a.get_objective_y()&&a.get_startpoint_x()==a.get_objective_x()){
            a.new_objectives();
        }
    }
    //in this print the 2 numbers should be the same
    a.print();
    return 0;
}