#include <iostream>
using namespace std;
struct link{//node
    int data;
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
    int i;
    int num_link;
    std::cout << "Hello, World!" << std::endl;
    chain a;
    a.add_lick(1,10,25);
    a.add_lick(2,13,30);
    a.add_lick(3,25,45);
    a.add_lick(4,3,5);
    a.display();
    a.delete_lk(a.gethd());
    a.display();
    return 0;
}
