#include <iostream>
using namespace std;
struct link{//node
    int data;
    bool possible_covid;
    int x;
    int y;
    int time;
    link*next;
};
class chain{
private:
    link *head,*tail,*x,*y,*time;
public:
    chain(){
        head=NULL;
        tail=NULL;
    }
    void add_lick(int n,int n_x,int n_y){
        link *tmp = new link;
        tmp->data=n;
        tmp->next;
        tmp->x=n_x;
        tmp->y=n_y;
        tmp->time=n*30;
        if (head==NULL){
            head=tmp;
            tail=tmp;
        }
        else {
            tail->next=tmp;
            tail=tail->next;
        }
    }
    link *gethd(){
        return head;
    }
    void after (link *a , int i){
        link*p = new link;

    }
    void delete_lk(link *prevlk){
        //will delete the next link of the link given
        //prevlk= previus link
        link *temp;
        temp = prevlk->next;
        prevlk->next=temp->next;
        delete temp;
    }
    void display() {//will be moded to show the users final
                    // data chill just working with it
        link *tmp;
        tmp=head;
        while (tmp!=NULL){
            cout<<tmp->data << endl ;
            cout<<tmp->x<<endl;
            cout<<tmp->y<<endl;
            cout<<tmp->time<<endl;
            tmp = tmp->next;//do not remove tha kaneis atemoni loop
                            //dont ask me how i know it
        }
    }

};

int main() {
    int days;
    int i;
    //the seconds every tick counts for 30 seconds do the loop has to be repeated only 2880 times instead of 86400
    //the time will be multiplied by 30 within the chain
    int sec;
    chain a;
    a.add_lick(6,13,13)
    cout<<"give number of days you whant to rum simulation for : ";
    cin>>days;
    for (i=1;i<=days;i++){
        for (sec=1;sec<=2880;sec++){
            //where the inner workings will go
        }
    }

    return 0;
}
