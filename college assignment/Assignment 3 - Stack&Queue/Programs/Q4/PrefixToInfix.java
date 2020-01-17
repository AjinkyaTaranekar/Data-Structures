import java.util.Scanner;

class Stack{
    private class Node{
        String data;
        Node next;
    }
    
    Node top;
    private int size=0;
    
    
    public void push(String data){
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
    
    public String peek(){
        if(isEmpty()){
            System.out.println("Stack underflow\n");
            System.exit(0);
        }
        return top.data;
    }
    
    public String top(){
        String topValue = peek();
        pop();
        return topValue;
    }
    
    public int size(){
        return size;
    }
    
    public void display(){
        Node temp = top;
        while(temp != null){
            System.out.print(temp.data + " " );
            temp=temp.next;    
        }
    }
}

public class PrefixToInfix{
    public static boolean isOperator(char operator){
        switch(operator){
            case '+' : return true;
            case '-' : return true;
            case '*' : return true;
            case '/' : return true;
        }
        return false;
    }
    public static String prefixToInfix(String sentence) { 
        Stack stack = new Stack();
    
        String temp = "";    
        for(int i = sentence.length()-1; i >=0;  i--){
            if(!isOperator(sentence.charAt(i)))
                    stack.push(sentence.charAt(i)+"");
            else
                stack.push("(" + stack.top() + sentence.charAt(i) + stack.top() + ")");
             
        }
        temp = stack.top();
        return temp;
    } 
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Enter a prefix expression");
        String sentence = keyboard.nextLine();

        System.out.println("\nInfix expression:");
        System.out.println(prefixToInfix(sentence));
        
        keyboard.close();
    }
}
