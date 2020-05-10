
#ifndef UNTITLED_USERCHAINS_H
#define UNTITLED_USERCHAINS_H


struct link{//node
    int data;
    bool isInfected;
    int x;
    int y;
    int time;
    link*next;
};

class UserChains {
private:
    link *head,*tail,*x,*y,*time,*isInfected;
public:
    UserChains();
    void add_lick(int n,int n_x,int n_y,bool isInfected);
    link *gethd(){
        return head;
    }
    void summarize(int);
    void repair();
    void after (link *a , int i);
    void delete_lk(link *prevlk);
    void display();
};


#endif //UNTITLED_USERCHAINS_H
