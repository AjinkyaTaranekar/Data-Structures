import java.util.Scanner;
class Queue { 
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
} 

class MoveAroundCity{ 
		static Queue x = new Queue(); 
		static Queue y = new Queue();
		
	static void move(char city[][], boolean visited[][]){
	    int n=4;
		for (int i=0 ; i<n; i++){
            for (int j=0 ; j<n; j++){
                if(city[i][j]=='t'){
                    break;
                }
                else if(i!=n-1 && city[i][j]!='x' && visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                else if(j!=n-1 && city[i][j]!='x' && visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                else if(i!=0 && city[i][j]!='x' && visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
                else if(j!=0 && city[i][j]!='x' && visited[i][j]==false){
                    x.enqueue(i);
                    y.enqueue(j);
                    visited[i][j]=true;
                }
			}
		}
		x.dequeue();
		y.dequeue();
	}
	public static void main(String[] args){
		Scanner keyboard = new Scanner(System.in);
		int size = 4;
        char[][] city = new char[size][size];
        boolean[][]  visited = new boolean[size][size];
    
        for (int i=0 ; i<size; i++){
            for (int j=0 ; j<size; j++){
				city[i][j]=keyboard.next().charAt(0);	
                visited[i][j]=false;
            }
        }
        
		move(city,visited); 
		x.display();
		y.display();
		
		keyboard.close();  
	} 
} 