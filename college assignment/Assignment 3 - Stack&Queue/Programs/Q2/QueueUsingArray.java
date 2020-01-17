import java.util.Scanner;

class Queue{
    private int front;
    private int rear;
    private int capacity;
    private int queue[];
    
    Queue(int capacity){
        front = rear = 0;
        this.capacity = capacity;
        queue = new int[capacity];
    }
    
    public void enqueue(int data){
        if(rear == capacity){
            System.out.println("Heap overflow\n");
            return;
        }
        queue[rear] = data;
        rear++;
    }      
    
    public boolean isEmpty(){
        if(rear == front)
            return true;
        return false;
    }
    
    public void dequeue(){
        if(isEmpty()){    
            System.out.println("Queue underflow\n");
            return;
        }
        
        else{
            for(int i = 0; i< rear- 1; i++)
                queue[i] =queue[i+1];
            
            if(rear < capacity)
                queue[rear] = 0;
            
            rear--;
        }
    }
    
    public void display(){
        if(isEmpty()){
            System.out.println("Queue is Empty\n");
            return;
        }
        System.out.print("\n");
        for(int i = front  ; i< rear ; i++  ){
            System.out.print(queue[i] +" " );
        }
    }
    
    public int queueFront(){
        if(isEmpty()){
            System.out.println("Queue is Empty\n");
            System.exit(1);
        }
        return queue[front];
    }
    
}

public class QueueUsingArray{
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Welcome to Queue Program Using Array");
        
        System.out.println("\nEnter size of queue");
        int numberOfElements = keyboard.nextInt();
        Queue queue = new Queue(numberOfElements);
   
        System.out.println("\nEnter elements of queue");
        for(int i = 0; i<numberOfElements; i++){
            int element = keyboard.nextInt();
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
