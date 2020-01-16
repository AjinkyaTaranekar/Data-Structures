
class QueueUsingLinkedList { 
    private class Node { 
    	int key; 
    	Node next; 
    
    	Node(int key){ 
    		this.key = key; 
    		this.next = null; 
    	} 
    } 

	Node front, rear; 

	public QueueUsingLinkedList(){ 
		this.front = this.rear = null; 
	} 
	
    void enqueue(int key){ 

		Node temp = new Node(key); 

		if (this.rear == null) { 
			this.front = this.rear = temp; 
			return; 
		} 

		this.rear.next = temp; 
		this.rear = temp; 
	} 
    
    boolean isEmpty(){
        if (this.front == null) 
			return true;
		return false;
    }
	Node dequeue(){ 
		if (isEmpty()) 
			return null; 

		Node temp = this.front; 
		this.front = this.front.next; 

		if (this.front == null) 
			this.rear = null; 
		return temp; 
	} 
	
	void display(){
	    if (isEmpty()){
	        System.out.println("Queue is Empty\n");
	        System.exit(0);
	    }
	    Node temp = front;
	    while(temp!=null){
	        System.out.print(temp.key+" ");
	        temp = temp.next;
	    }
	    System.out.print("\n");
	    
	}
} 

public class Main { 
	public static void main(String[] args){
	    
		QueueUsingLinkedList queue = new QueueUsingLinkedList(); 
		queue.enqueue(0); 
		queue.enqueue(10);
		queue.enqueue(20); 
		queue.display();
		
		queue.dequeue(); 
		queue.dequeue(); 
		queue.display();
		
		queue.enqueue(30); 
		queue.enqueue(40); 
		queue.enqueue(50); 
		queue.display();
	    
	} 
} 
