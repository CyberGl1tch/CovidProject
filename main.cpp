#include <iostream>
#include <random>
#include <ctime>
#include "UserChains.h"

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
       // cout<<"new objectives"<<endl;
       // cout<<objective_x<<"      "<<objective_y<<endl;
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
        //cout << startpoint_x << "  " << startpoint_y << endl;
    }

    //just a testing function nothing more
    //shows the original values
    void print(){
        cout<<startpoint_x<<"    "<<startpoint_y<<endl;
        cout<<objective_x<<"    "<<objective_y<<endl;
    }
};

void walkUsersss();

void walkUsers(random_waypoint_system& a,random_waypoint_system& b,random_waypoint_system& c,random_waypoint_system& d,random_waypoint_system& e,random_waypoint_system& f){
    a.walk();
      if(a.get_startpoint_y()==a.get_objective_y()&&a.get_startpoint_x()==a.get_objective_x()){
            a.new_objectives();
    }
    b.walk();
    if(b.get_startpoint_y()==b.get_objective_y()&&b.get_startpoint_x()==b.get_objective_x()){
        b.new_objectives();
    }
    c.walk();
    if(c.get_startpoint_y()==c.get_objective_y()&&c.get_startpoint_x()==c.get_objective_x()){
        c.new_objectives();
    }
    d.walk();
    if(d.get_startpoint_y()==d.get_objective_y()&&d.get_startpoint_x()==d.get_objective_x()){
        d.new_objectives();
    }
    e.walk();
    if(e.get_startpoint_y()==e.get_objective_y()&&e.get_startpoint_x()==e.get_objective_x()){
        e.new_objectives();
    }
    f.walk();
    if(f.get_startpoint_y()==f.get_objective_y()&&f.get_startpoint_x()==f.get_objective_x()){
        f.new_objectives();
    }

}

bool PossibleCovid(UserChains& nonCovid,int day,UserChains& Covid){
    int radius = 3;
    int minTimeStay = 30; // in minutes
    int maxTimeStay = 1;// in minutes
    bool inDistance = false;
    bool inTime = false;
    link *nonCovidLink = nonCovid.gethd();
    link *covidLink = Covid.gethd();
    //Run loop for every CovidPatient Coordinates(places)
    while (covidLink->next != NULL) {

        //Check for day if day is the day in function input then :
        if(covidLink->data == 2880*day){
            //Geting the first place of the nonCovidPatient
            //tha trexoume mia for gia na doume an vrethike o user kapou mesa sths wres pou orizei o xristis t2 simfona me thn ekfonish an vrethei koda mesa
            //se aftes tis wres tote tha treksoume mia allh for gia na doume an emeine ekei toulaxistwn t1 lepta an isxyoun kai ta 2 tote einai o tipas possible
            // skeftomaste oti einai 30Defterolepton oi loops
            //to max time afou einai se minutes gia na doume posous komvous prepei na treksei einai maxtime*60/30
            for (int i = 0; i < maxTimeStay*60/30; i++) {
                if(!inDistance) {
                    inDistance = true;
                    link *tmp = nonCovidLink->next;
                    if(tmp == NULL){
                        break;
                    }
                    double distance = sqrt(pow(tmp->x - covidLink->x, 2) + pow(tmp->y - covidLink->y, 2));
                    // an i apostash einai mikroteri isi tou 2 dld einai koda
                    if (distance <= radius) {
                        //Edw tha treksw for gia to an paraminei sto simio gia minTimeStay dld to t1 sthbn egasia
                        for(int j = 0; j < minTimeStay*60/30; j++){
                            inTime = true;
                            link *tmp2 = tmp->next; //xrisimopoio to tmp giati einai apo tin thesei pou vrethike koda
                            double distance2 = sqrt(pow(tmp2->x - covidLink->x, 2) + pow(tmp2->y - covidLink->y, 2));
                            if(distance2>radius){
                                inTime = false;
                                inDistance = false;
                                break;
                            }

                        }
                    }
                }else{
                    break;
                }
            }
            if(inDistance && inTime){
                return true;
            }
            //link *nonCovidLink = nonCovid.gethd();

        }

        covidLink = covidLink->next; // proxorame ena to Covid
    }
    return false;
}


int main() {
    srand(time(0));//very important
    random_waypoint_system nonCovid1;
    random_waypoint_system nonCovid2;
    random_waypoint_system nonCovid3;
    random_waypoint_system nonCovid4;
    random_waypoint_system Covid1;
    random_waypoint_system Covid2;
    UserChains nonCovid1Chain;
    UserChains nonCovid2Chain;
    UserChains nonCovid3Chain;
    UserChains nonCovid4Chain;
    UserChains Covid1Chain;
    UserChains Covid2Chain;

    int day = 1;

    int radius = 3;
    int minTimeStay = 3; // in seconds
    int maxTimeStay = 10;// in seconds

    //walks until everything is where it should be
    for (int i;i<100;i++){
        walkUsers(nonCovid1,nonCovid2,nonCovid3,nonCovid4,Covid1,Covid2);
        nonCovid1Chain.add_lick(i,nonCovid1.get_startpoint_x(),nonCovid1.get_startpoint_y(),false);
        nonCovid2Chain.add_lick(i,nonCovid2.get_startpoint_x(),nonCovid2.get_startpoint_y(),false);
        nonCovid3Chain.add_lick(i,nonCovid3.get_startpoint_x(),nonCovid3.get_startpoint_y(),false);
        nonCovid4Chain.add_lick(i,nonCovid4.get_startpoint_x(),nonCovid4.get_startpoint_y(),false);
        Covid1Chain.add_lick(i,Covid1.get_startpoint_x(),Covid1.get_startpoint_y(),true);
        Covid2Chain.add_lick(i,Covid2.get_startpoint_x(),Covid2.get_startpoint_y(),true);
    };
   bool t = PossibleCovid(nonCovid1Chain,1,Covid1Chain);
    if(t){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

   return 0;
}

