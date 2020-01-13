class QueueUsingArray{
    private int front;
    private int rear;
    private int capacity;
    private int queue[];
    
    QueueUsingArray(int capacity){
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
        for(int i = front  ; i< rear ; i++  ){
            System.out.println(queue[i] +" " );
        }
    }
    
    public int queueFront(){
        if(isEmpty()){
            System.out.println("Queue is Empty\n");
            return;
        }
        return queue[front];
    }
    
}

public class Main{
    public static void main(String[] args){
        QueueUsingArray queue = new QueueUsingArray(5);
        queue.getSize(5);
        queue.enqueue(5);
        queue.enqueue(6);
        queue.enqueue(7);
        queue.enqueue(8);
        
        queue.display();
        
        queue.dequeue();
        queue.display();
    }
}
