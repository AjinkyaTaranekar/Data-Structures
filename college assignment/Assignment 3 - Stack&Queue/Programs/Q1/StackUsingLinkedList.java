class StackUsingLinkedList
{
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
        System.out.println("_____");
        while(temp != null){
            System.out.println("| "+ temp.data +" |" );
            temp=temp.next;    
        }
        System.out.println("_____");
    }
}

public class Main{
    public static void main(String[] args){
        StackUsingLinkedList stack = new StackUsingLinkedList();
        
        stack.push(5);
        stack.push(6);
        stack.push(7);
        stack.push(8);
        stack.push(9);
        System.out.println(stack.size());
        stack.display();
        
        System.out.println(stack.top());
        System.out.println(stack.peek());
        stack.display();
    }
}
