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
link *gethd(){
    return head;
}
void UserChains::after (link *a , int i){
    link*p = new link;

}
void UserChains::delete_lk(int j){
   //prevlk= previus link
        link *prevlk;
        prevlk=gethd();
        int i;
        if (j>1) {
            j--;
            for (i = 1; i < j; i++) {
            prevlk=prevlk->next;//reaches the previus link to that that we want to delete
            }
        link *temp;
        temp = prevlk->next;
        prevlk->next=temp->next;//deletes what we want
        delete temp;
        }
        else{
            cout<<"wrong number"<<endl;//if num smaller than 1
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
