import java.util.Scanner;

class Stack{
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
    
    public int size(){
        return size;
    }
    
    public void display(){
        Node temp = top;
        System.out.println("-----");
        while(temp != null){
            System.out.println("| "+ temp.data +" |" );
            temp=temp.next;    
        }
        System.out.println("-----");
    }
}

public class StackUsingLinkedList{
    public static void main(String[] args){
       
        Scanner keyboard = new Scanner(System.in);
        Stack stack = new Stack();
        System.out.println("Welcome to Stack Program Us7ing Array");
        
        System.out.println("\nEnter elements of stack");
        System.out.println("Break using -1");
        while(true){
            int element = keyboard.nextInt();
            if(element==-1)
                break;
            stack.push(element);
        }

        System.out.println("\nCurrent stack");
        stack.display();
        
        System.out.println("Top value using Top() = "+ stack.top());

        System.out.println("Top value using peek() = " + stack.peek());
        
        System.out.println("\nCurrent stack");
        stack.display();

        keyboard.close();
    }
}
