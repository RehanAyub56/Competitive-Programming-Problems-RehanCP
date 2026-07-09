class MyLinkedList {
    MyLinkedList*head;
    int val;
    MyLinkedList*next;
    MyLinkedList*prev;
    MyLinkedList*tail;
public:
    MyLinkedList() {
        head=nullptr;
        next=nullptr;
        prev=nullptr;
        tail=nullptr;
    }
    
    int get(int index) {
        MyLinkedList*temp=head;
        if(head!=NULL){
        while(index && temp!=NULL){
            temp=temp->next;
            index--;
        }
        if(temp!=NULL){
            return temp->val;
        }
        else{
            return -1;
        }


        }

        return -1;

    }
    
void addAtHead(int val) {
    MyLinkedList* newNode = new MyLinkedList();
    newNode->val = val;
    newNode->prev = nullptr;
    newNode->next = head;

    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        head->prev = newNode;
        head = newNode;
    }
}
    void addAtTail(int val) {
        MyLinkedList*newNode=new MyLinkedList();
        newNode->val=val;
        newNode->next=nullptr;
        newNode->prev=nullptr;
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;

        }

    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
        }
        else{
        MyLinkedList*temp=head;   
        MyLinkedList*newNode=new MyLinkedList();
        newNode->val=val;
        if(head!=NULL){

        while(index && temp!=NULL){
            index--;
            temp=temp->next;
        }

        if(index>0){
            return ;
        }
        if(temp==NULL){
            addAtTail(val);
            return;
        }
        if(temp!=NULL){
        newNode->next=temp;
        newNode->prev=temp->prev;
        newNode->prev->next=newNode;
        newNode->next->prev=newNode;
        }

        }

        
}

    }
    
void deleteAtIndex(int index) {

    MyLinkedList* temp = head;

    if(head == NULL)
        return;

    while(index && temp != NULL){
        index--;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    // Only one node
    if(head == tail){
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    // Delete head
    if(temp == head){
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    // Delete tail
    if(temp == tail){
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
        return;
    }

    // Delete middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}
};