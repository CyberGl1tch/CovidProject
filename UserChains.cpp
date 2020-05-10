//
// Created by Kostas on 5/2/2020.
//

#include "UserChains.h"
#include <iostream>
using namespace std;

UserChains::UserChains(){
    head=NULL;
    tail=NULL;
}
void UserChains::add_lick(int n,int n_x,int n_y,bool isInfected){
    link *tmp = new link;
    tmp->isInfected=isInfected;
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
/*link *gethd(){
    return head;
}*/

link *get_link(int n,int n_x,int n_y,bool isInfected){
    link *new_lk= (link*)malloc(sizeof(link));//allocata the space
    new_lk->isInfected=isInfected;
    new_lk->data=n;
    new_lk->x=n_x;
    new_lk->y=n_y;
    new_lk->time=n * 30;
    return new_lk;

}
void UserChains::summarize(int R) {
    bool y;
    bool x;
    int z = 1;
    int c = 1;//counter
    link *comparer = gethd();
    int least_space_x = comparer->x - R;
    int max_space_x = comparer->x + R;

    int least_space_y = comparer->y - R;
    int max_space_y = comparer->y + R;
    while (comparer->next != NULL) {
        link *temp = comparer->next;

        //checks if the cords are within R

        if (temp->x >= least_space_x && temp->x <= max_space_x) { x = true; }
        else { x = false; }
        if (temp->y >= least_space_y && temp->y <= max_space_y) { y = true; }
        else { y = false; }
        z++;
        if (x == true && y == true) {
            c++;
            //the deletion part

        }
        else {
            least_space_x = comparer->x - R;
            max_space_x = comparer->x + R;

            least_space_y = comparer->y - R;
            max_space_y = comparer->y + R;
            if(c>2){
                cout<<c<<endl;
                link* idk=gethd();
                if (z>1) {
                    z--;
                    for (int i = 1; i < z; i++) {
                        idk = idk->next;
                    }
                }
                c--;
                for (int j=1;j<c;j++) {
                    link *tempikd;
                    tempikd = idk->next;
                    idk->next = tempikd->next;//deletes what we want
                    delete tempikd;
                }


            }
            c=0;
        }
        comparer = comparer->next;
    }
}
void UserChains::repair() {
    int c = 0;
    link *this_link = gethd();
    link *next_link = this_link->next;
    while (next_link->next != NULL) {
        c++;//pun intended
        int this_n = this_link->data;
        int next_n = next_link->data-1;
        if (this_n != next_n) {
            //creates a node
            int n_n = this_link->data + 1;//the data
            int n_xc = (this_link->x + next_link->x) / 2;
            int n_y = (this_link->y + next_link->y) / 2;
            bool n_isInfected = this_link->isInfected; //this next same thing
            link *mid_node = get_link(n_n, n_xc, n_y, n_isInfected);
            link *new_link = gethd();
            n_n--;
            if (n_n > 1) {
                for (int i = 1; i < n_n; i++) {
                    new_link = new_link->next;//reaches the previus link to that that we want to edit
                }

            }
            mid_node->next = new_link->next;
            new_link->next = mid_node;
        }
        this_link = this_link->next;
        next_link = next_link->next;
    }
}
void UserChains::after (link *a , int i){
    link*p = new link;

}
void UserChains::delete_lk(link *prevlk){
    //will delete the next link of the link given
    //prevlk= previus link
    link *temp;
    temp = prevlk->next;
    prevlk->next=temp->next;
    delete temp;
}
void UserChains::display() {//will be moded to show the users final
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