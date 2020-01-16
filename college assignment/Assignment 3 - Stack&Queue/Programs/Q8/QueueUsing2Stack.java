import java.util.*; 

class QueueUsing2Stack{
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
            System.out.println("_____");
            while(temp != null){
                System.out.println("| "+ temp.data +" |" );
                temp=temp.next;    
            }
            System.out.println("_____");
        }
    }
        
    StackUsingLinkedList s1 = new StackUsingLinkedList(); 
    StackUsingLinkedList s2 = new StackUsingLinkedList(); 

    void enQueue(int x){ 
		while (!s1.isEmpty()){ 
			s2.push(s1.top()); 
		} 

		s1.push(x); 

		while (!s2.isEmpty()){ 
			s1.push(s2.top());
		} 
	} 

	int deQueue(){ 
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

public class Main{
    public static void main(String[] args){ 
    	QueueUsing2Stack queue = new QueueUsing2Stack(); 
    	queue.enQueue(1); 
    	queue.enQueue(2); 
    	queue.enQueue(3); 
        queue.display();
        
        queue.deQueue(); 
    	queue.deQueue(); 
    	queue.display();
    } 
}

