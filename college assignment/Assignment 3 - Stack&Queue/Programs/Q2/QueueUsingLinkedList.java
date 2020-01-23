import java.util.Scanner;

class Queue{ 
    private class Node { 
    	int key; 
    	Node next; 
    
    	Node(int key){ 
    		this.key = key; 
    		this.next = null; 
    	} 
    } 

	Node front, rear; 

	public Queue(){ 
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

	int queueFront(){
		if (isEmpty()){
	        System.out.println("Queue is Empty\n");
	        System.exit(0);
	    }
	    return front.key;
	}
} 

public class QueueUsingLinkedList{ 
	public static void main(String[] args){
	    Scanner keyboard = new Scanner(System.in);
        System.out.println("Welcome to Queue Program Using Linked List");
        
        Queue queue = new Queue();
   
        System.out.println("\nEnter elements of queue");
        System.out.println("\nTo Break enter -1");
        while(true){
			int element = keyboard.nextInt();
			if(element==-1)
				break;
            queue.enqueue(element);
        }

        System.out.println("\nCurrent queue");
        queue.display();
        
        
        System.out.println("\nQueue Front = " +queue.queueFront());
        
        System.out.println("\nDequeue 2 elements from queue");
        queue.dequeue();
        queue.dequeue();

        System.out.println("\nCurrent queue");
        queue.display();

        keyboard.close();

	} 
} 
