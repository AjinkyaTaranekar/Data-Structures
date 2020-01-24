import java.util.Scanner;

public class Petrol{ 

	private static class PetrolPump{ 
		int rear, front; 
		int size; 
		int[][] petrolPump; 
			
		PetrolPump(int numberOfPetrolPump){ 
			front = rear = -1; 
			size = numberOfPetrolPump; 
			petrolPump = new int[numberOfPetrolPump][2]; 
		} 

		void enQueue(int petrol, int distance){ 
			if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){ 
				System.out.println("\nQueue is Full"); 
				return; 
			} 
		
			else if (front == -1){ 
				front = rear = 0; 
				petrolPump[rear][0] = petrol;
				petrolPump[rear][1] = distance; 
			} 
		
			else if (rear == size-1 && front != 0){ 
				rear = 0; 
				petrolPump[rear][0] = petrol;
				petrolPump[rear][1] = distance;
			} 
		
			else{ 
				rear++; 
				petrolPump[rear][0] = petrol;
				petrolPump[rear][1] = distance;
			} 
		} 
		
		void deQueue(){ 
			if (front == -1){ 
				System.out.println("\nQueue is Empty"); 
				return; 
			} 
		 
			if (front == rear){ 
				front = -1; 
				rear = -1; 
			} 
			else if (front == size-1) 
				front = 0; 
			else
				front++; 
		} 
		int getPetrol(int pos){
			return petrolPump[pos][0];
		}
		
		int getDistance(int pos){
			return petrolPump[pos][1];
		}
	}	
	
	static int startingPoint(PetrolPump petrolPump, int numberOfPetrolPump){
		int start = 0; 
		int end = 1; 
		int remaining = petrolPump.getPetrol(start) - petrolPump.getDistance(start); 
		
		while(end != start || remaining < 0) 
		{ 
			while(remaining < 0 && start != end) 
			{ 
				remaining -= petrolPump.getPetrol(start) - petrolPump.getDistance(start); 
				start = (start + 1) % numberOfPetrolPump; 
				
				if(start == 0) 
					return -1; 
			} 
			remaining += petrolPump.getPetrol(end) - petrolPump.getDistance(end); 	
			end = (end + 1)%numberOfPetrolPump; 
		} 
		
		return start; 
	} 
	
    public static void main(String[] args) { 
    
        Scanner keyboard = new Scanner(System.in);
        int numberOfPetrolPump = keyboard.nextInt();
        
        PetrolPump petrolPumps = new PetrolPump(numberOfPetrolPump);
        
        for (int i = 0 ; i < numberOfPetrolPump; i++){
            int petrol = keyboard.nextInt();
            int distance = keyboard.nextInt();
            petrolPumps.enQueue(petrol, distance);
        } 
        	
        int start = startingPoint(petrolPumps, numberOfPetrolPump); 
        if(start == -1)
            System.out.println("No Solution");
        else
            System.out.println("Start = " + start); 
		keyboard.close();
	} 
}
