//  main.cpp
//  Linked_list
//  Created by Dixit sharma on 7/8/17.
//  Copyright © 2017 Dixit sharma. All rights reserved.
//
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
    private :
    node *head, *tail;
    
    public :
    
    list ()                                                      // Constructer to Init
    {
        head = NULL;
        tail = NULL;
    }
    
    void create_node(int num)                                   // Create new or add to prev_created
    {
        node *temp = new node;
        temp->data = num;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    
    void add_front()                                            // Insert in front
    {
        int num;
        cout<<endl<<"Please enter the number to insert in front : ";
        cin>>num;
        node *temp = new node;
        temp->data = num;
        temp->next = head;
        head = temp;
        
    }
    
    void add_rear()                                         // Insert in Rear
    {
        int num;
        cout<<endl<<"Please enter the number to insert in rear : ";
        cin>>num;
        node *temp = new node;
        temp->data = num;
        tail->next = temp;
        tail = temp;
        temp->next = NULL;
        
    }
    
    void add_pos()                                          // Insert in Particular position
    {
        int num, pos;
        cout<<endl<<"Please enter the number to insert in : ";
        cin>>num;
        cout<<"Particular Position : ";
        cin>>pos;
        node *curr = new node;
        node *temp = new node;
        node *prev = new node;
        curr = head;
        for(int i = 1; i<pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        temp->data = num;
        prev->next = temp;
        temp->next = curr;
        
    }
    
    void reverse_list()                                 // Reverse the list
    {
        cout<<endl<<"Reverse the list"<<endl;
        node *temp = new node;
        node *curr = new node;
        node *prev = new node;
        curr = head;
        prev = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }
    
    void delete_front()                                 // delete from front
    {
        cout<<endl<<"Delete from front"<<endl;
        node *temp = new node;
        head = head->next;
        temp = head;
        delete temp;
    }
    
    void delete_rear()                                      // Delete from rear
    {
        cout<<endl<<"Delete from rear"<<endl;
        node *prev = new node;
        node *curr = new node;
        curr = head;
        while(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        tail->next = prev;
        delete curr;
        prev->next = NULL;
        }
    
    void delete_pos()                                       // Delete from particular position
    {
        node *prev = new node;
        node *curr = new node;
        
        int pos;
        cout<<endl<<"Enter the position to delete : ";
        cin>>pos;
        curr = head;
        
        for(int i=1; i<pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
    }

  void display()                                            // Display Function
    {
        node *temp = new node;
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    list obj;
    
    obj.create_node(10);
    obj.create_node(20);
    cout<<"List : ";
    obj.display();
    obj.add_front();
    obj.display();
    obj.add_rear();
    obj.display();
    obj.add_pos();
    obj.display();
    obj.reverse_list();
    obj.display();
    obj.delete_front();
    obj.display();
    obj.delete_rear();
    obj.display();
    obj.delete_pos();
    obj.display();
    
    cout<<endl;
    return 0;
}

/*----------------------------Output-----------------------------
 List : 10	20
 Please enter the number to insert in front : 5
 5	10	20
 Please enter the number to insert in rear : 25
 5	10	20	25
 Please enter the number to insert in : 11
 Particular Position : 3
 5	10	11	20	25
 Reverse the list
 25	20	11	10	5
 Delete from front
 20	11	10	5
 Delete from rear
 20	11	10
 Enter the position to delete : 2
 20	10
 Program ended with exit code: 0
 -----------------------------------------------------------------*/













