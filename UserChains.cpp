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