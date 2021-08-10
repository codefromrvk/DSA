#include <iostream>

using namespace std;


struct Node
{
    int data;
    Node * next;

};

Node *create(int n);
Node *insert_beg(Node * head,int n);
Node *insert_end(Node * head,int n);

Node *delete_beg(Node * head);
void delete_end(Node * head);

void display(Node *);

Node *create(int n)
{
    Node * nptr= new Node;

    nptr->data=n;
    nptr->next=NULL;
    return nptr;

}
Node *insert_beg(Node * head,int n)
{
    Node * np =create( n);
    if(head==NULL)
    {
        head=np;
        return np;
    }
    np-> next=head;
    head=np;
    return head;
}


Node *insert_end(Node * head,int n)
{
    Node * np =create( n);
    if(head==NULL)
    {
        head=np;

        return np;
    }

    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=np;
    return np;
}
Node * delete_beg(Node * head)
{
    if(head==NULL)
    {
        cout<<"No elements to delete";
        return 0;

    }
    Node * temp;

    temp=head->next;
    free(head);
    return temp;


}
void delete_end(Node * head)
{
    if(head==NULL)
    {
        cout<<"No elements to delete";

    }

    Node *temp=head;
    while(head->next!=NULL)
    {
        temp=head;
        head=head->next;
        if(head->next==NULL)
        {
            free(head);
            temp->next=NULL;

        }
    }



}

int main()
{
    Node * head= NULL;
    Node * head1= NULL;


    head=insert_beg(head,30);
    head=insert_beg(head,40);
    head1=insert_beg(head,60);

    head=insert_end(head1,20);

    cout<<"Before deletion in the begining ";
    display(head1);
    cout<<"\n";
    head1=delete_beg(head1);

    cout<<"After deletion in the begining ";
    display(head1);
    cout<<"\n";



    cout<<"Before deletion in the Ending";
    display(head1);
    cout<<"\n";
   delete_end(head1);

    cout<<"After deletion in the Ending";
    display(head1);
    cout<<"\n";




    return 0;
}
void display(Node * head)
{

    if(!head)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    Node *temp=head;
    while(temp!=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;


    }
}
