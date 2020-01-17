import java.util.Scanner;
class Stack{
    private int top=-1;
    private int size=0;
    
    void getSize(int size){
        this.size = size;
    }
    
    private int[] a = new int[5];
    
    public void push(int data){
        if(top >= size){
            System.out.println("Heap overflow\n");
            return;
        }
        a[++top] = data;
    }      
    
    public boolean isEmpty(){
        if(top == -1)
            return true;
        return false;
    }
    
    public void pop(){
        if(!isEmpty()){
            top--;
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
        return a[top];
    }
    
    public int topVal(){
        int topValue = peek();
        pop();
        return topValue;
    }
    
    public int size(){
        return top;
    }
    
    public void display(){
        System.out.println("-----");
        for(int i = top  ; i>= 0 ; i--  ){
            System.out.println("| "+ a[i] +" |" );
        }
        System.out.println("-----");
    }
}

public class StackUsingArray{
     public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        Stack stack = new Stack();
        System.out.println("Welcome to Stack Program Using Array");
        
        System.out.println("\nEnter size of stack");
        int numberOfElements = keyboard.nextInt();
        stack.getSize(numberOfElements);

        System.out.println("\nEnter elements of stack");
        for(int i = 0; i<numberOfElements; i++){
            int element = keyboard.nextInt();
            stack.push(element);
        }

        System.out.println("\nCurrent stack");
        stack.display();
        
        System.out.println("Top value using Top() = "+ stack.topVal());

        System.out.println("Top value using peek() = " + stack.peek());
        
        System.out.println("\nCurrent stack");
        stack.display();

        keyboard.close();
    }
}
