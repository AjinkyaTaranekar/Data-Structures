import java.util.Scanner;

public class Petrol{ 

	private static class PetrolPump{ 
		int petrol; 
		int distance; 
        
		PetrolPump(int petrol, int distance){ 
			this.petrol = petrol; 
			this.distance = distance; 
		} 
	
	}	
	
	static int startingPoint(PetrolPump[] petrolPumps, int numberOfPetrolPump){
		int start = 0; 
		int end = 1; 
		int curr_petrol = petrolPump[start].petrol - petrolPump[start].distance; 
		
		while(end != start || curr_petrol < 0) 
		{ 
			
			while(curr_petrol < 0 && start != end) 
			{ 
				curr_petrol -= petrolPump[start].petrol - petrolPump[start].distance; 
				start = (start + 1) % numberOfPetrolPump; 
				
				if(start == 0) 
					return -1; 
			} 
			curr_petrol += petrolPump[end].petrol - petrolPump[end].distance; 
			
			end = (end + 1)%numberOfPetrolPump; 
		} 
		
		return start; 
	} 
	
    public static void main(String[] args) { 
    
        Scanner keyboard = new Scanner(System.in);
        int numberOfPetrolPump = keyboard.nextInt();
        
        PetrolPump[] petrolPumps;
        
        for (int i = 0 ; i < numberOfPetrolPump; i++){
            int petrol = keyboard.nextInt();
            int distance = keyboard.nextInt();
            petrolPumps[i] = new PetrolPump(petrol, distance);
        } 
        	
        int start = startingPoint(petrolPumps, numberOfPetrolPump); 
        if(start == -1)
            System.out.println("No Solution");
        else
            System.out.println("Start = " + start); 
    } 
}
