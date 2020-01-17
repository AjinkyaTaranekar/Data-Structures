import java.util.*; 

class Queue{
    class StackUsingLinkedList{
        private class Node{
        int data;
        Node next;
        }
        
        Node top;
        private int size=0;
        
        
        public void push(int data){
            Node temp = new Node();
            if(temp == null){
                System.out.println("Heap overflow\n");
                return;
            }
            temp.data = data;
            temp.next = top;
            top = temp;
            size++;
        }
        
        public boolean isEmpty(){
            if(top == null)
                return true;
            return false;
        }
        
        public void pop(){
            if(!isEmpty()){
                top = top.next;
                size--;
            }
            else{    
                System.out.println("Stack underflow\n");
                return;
            }
        }
        
        public int peek(){
            if(isEmpty()){
                System.out.println("Stack underflow\n");
                System.exit(0);
            }
            return top.data;
        }
        
        public int top(){
            if(isEmpty()){
                System.out.println("Stack underflow\n");
                System.exit(0);
            }
            int topValue = top.data;
            pop();
            return topValue;
        }
        
        public int stackSize(){
            return size;
        }
        
        public void display(){
            Node temp = top;
            
            System.out.print(" \n");
            while(temp != null){
                System.out.print( temp.data +" " );
                temp=temp.next;    
            }
        }
    }
        
    StackUsingLinkedList s1 = new StackUsingLinkedList(); 
    StackUsingLinkedList s2 = new StackUsingLinkedList(); 

    void enqueue(int x){ 
		while (!s1.isEmpty()){ 
			s2.push(s1.top()); 
		} 

		s1.push(x); 

		while (!s2.isEmpty()){ 
			s1.push(s2.top());
		} 
	} 

	int dequeue(){ 
		if (s1.isEmpty()){ 
			System.out.println("Queue is Empty"); 
			System.exit(0); 
		} 

		int x = s1.peek(); 
		s1.pop(); 
		return x; 
	} 
	
	void display(){
	    s1.display();
	}
}

public class QueueUsing2Stack{
    public static void main(String[] args){ 
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Welcome to Queue Program Using Array");
        
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
            
        System.out.println("\nDequeue 2 elements from queue");
        queue.dequeue();
        queue.dequeue();

        System.out.println("\nCurrent queue");
        queue.display();

        keyboard.close();
    } 
}

