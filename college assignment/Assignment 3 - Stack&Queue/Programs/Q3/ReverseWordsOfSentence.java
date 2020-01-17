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

public class ReverseWordsOfSentence{
    public static String reverseWordsOfSentence(String sentence) { 
        Stack stack = new Stack();
    
        String temp = "";    
        for(int i = 0 ; i< sentence.length(); i++){
            if(sentence.charAt(i) == ' '){
                stack.push(temp);
                temp = "";
            }
            else
                temp+=sentence.charAt(i);
        }
        stack.push(temp);
        temp = "";
        while(!stack.isEmpty()){
            temp+=stack.top() + " "; 
        }
        
        return temp;
    } 
    public static void main(String[] args){
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Enter a string to be reversed");
        String sentence = keyboard.nextLine();
        
        System.out.println("Reversed string :");
        System.out.println(reverseWordsOfSentence(sentence));
        keyboard.close();
    }
}
