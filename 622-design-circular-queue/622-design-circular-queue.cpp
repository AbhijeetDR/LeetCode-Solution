class Node{
    friend class MyCircularQueue;
    Node* next;
    int val;
    public:
    
    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class MyCircularQueue {
    Node* head;
    Node* tail;
    int cap;
    // int con;
    
public:
    MyCircularQueue(int k) {
       head = NULL;
        tail = NULL;
        cap = k;
        // con = k;
    }
    
    bool enQueue(int value) {
        if(cap == 0) return 0;
        cap--;
        Node* newNode = new Node(value);
        if(head == NULL){   
            head = newNode;
            tail = head;
            // tail->next = head;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            // newNode->next = head;
        }
        
        return 1;
        
    }
    
    bool deQueue() {
        
        if(head == NULL) return 0;
        cap++;
        if(head == tail){
            head = tail = NULL;
            // head->next = NULL;
            return 1;
        }
        
        head = head->next;
        // tail->next = head;
        return 1;
    }
    
    int Front() {
    	if(head == NULL) return -1;
        return head->val;
    }
    
    int Rear() {
    	if(tail == NULL) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(head == NULL) return 1;
        return 0;
    }
    
    bool isFull() {
        return cap == 0;
        
    }
    void dip(){
    	
    	cout << "st: ";
    	Node* tmp = head;
    	while(tmp != NULL){
    		cout << tmp->val << " ";
    		tmp = tmp->next;
    	}
    	cout << endl;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */