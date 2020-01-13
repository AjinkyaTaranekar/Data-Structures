class StackUsingArray{
    private int data;
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
        System.out.println("_____");
        for(int i = top  ; i>= 0 ; i--  ){
            System.out.println("| "+ a[i] +" |" );
        }
        System.out.println("_____");
    }
}

public class Main{
    public static void main(String[] args){
        StackUsingArray stack = new StackUsingArray();
        stack.getSize(5);
        stack.push(5);
        stack.push(6);
        stack.push(7);
        stack.push(8);
        System.out.println(stack.size());
        stack.display();
        
        System.out.println(stack.topVal());
        System.out.println(stack.peek());
        stack.display();
    }
}
