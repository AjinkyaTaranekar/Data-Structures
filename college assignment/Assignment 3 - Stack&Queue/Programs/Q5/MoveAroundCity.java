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
	static void move(char city[][], boolean visited[][]){
	    QueueUsingLinkedList x = new QueueUsingLinkedList(); 
		QueueUsingLinkedList y = new QueueUsingLinkedList();
		
		for (int i=0 ; i<10; i++){
            for (int j=0 ; j<10; j++){
                if(city[i][j]=='t'){
                    break;
                }
                else if(i!=n-1 and city[i][j]!='t' and visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                else if(j!=n-1 and city[i][j]!='t' and visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                else if(i!=0 and city[i][j]!='t' and visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                else if(j!=0 and city[i][j]!='t' and visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                x.dequeue();
                y.dequeue();
            }
        }
	}
	public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        char[][] city = new char[10][10];
        boolean[][]  visited = new boolean[10][10];
    
        for (int i=0 ; i<10; i++){
            for (int j=0 ; j<10; j++){
                city[i][j]=keyboard.nextChar();
                visited[i][j]=false;
            }
        }
        
        move(city,visited);   
	} 
} 