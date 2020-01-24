import java.util.Queue;
import java.util.Scanner;
import java.util.Random;
import java.util.LinkedList;

class Restaurant{
    class CustomerInfo{
        int custID;
        int arrivalTime;
        int tokenID;
        CustomerInfo(int custID, int arrivalTime){
            this.custID = custID;
            this.arrivalTime = arrivalTime;
        }
        int getCustID(){
            return custID;
        }
    }
    class FoodInfo{
        int foodID;
        String foodName;
        double rate;

        void setFoodID(int foodID){
            this.foodID = foodID;
        }
        void setFoodName(String foodName){
            this.foodName = foodName;
        }
        void setRate(double rate) {
            this.rate = rate;
        }
    }

    class Orders{ 
        int tokenID;
        double cost;
        FoodInfo foodIDs[];
        Orders(int tokenID, FoodInfo foodIDs[], double cost){
            this.tokenID = tokenID;
            this.cost = cost;
            this.foodIDs=foodIDs;
        }
    }
    class Kitchen{
        Orders order;
        int preparationTime;
    }

    static int custID = 0 , ordersInKitchen = 0 , tokenID = 0 , foodIndex = 0;
    
    FoodInfo[] food = new FoodInfo[100];
    Orders order;
    Kitchen[] k = new Kitchen[100];
    
    Queue<CustomerInfo> customerQueue = new LinkedList<CustomerInfo>();
    Queue<Integer> orderDispatch = new LinkedList<Integer>();
        
    void setFoodItems(int id, String name, double rate) {
        food[foodIndex] = new FoodInfo();
        food[foodIndex].setFoodID(id);
        food[foodIndex].setFoodName(name);
        food[foodIndex].setRate(rate);
        foodIndex++;
    }
    
    void loadMenu(){
        setFoodItems(1,"Vada Pav",10.0);
        setFoodItems(2,"Uttappa",18.0);
        setFoodItems(3,"Samosa",15.0);
        setFoodItems(4,"Mendu Vada",10.0);
        setFoodItems(5,"Missal Pav",20.0);
        setFoodItems(6,"Masala Dosa",25.0);
        setFoodItems(7,"Bhel Puri",30.0);
        setFoodItems(8,"Sev Puri",30.0);
        setFoodItems(9,"Pakoda",22.0);
        setFoodItems(10,"Bhajia",16.0);
        setFoodItems(11,"Sukhi Baji",19.0);
        setFoodItems(12,"Shira",26.0);
    }
    
    void displayMenu(){
        String leftAlignFormat = "| %-4d | %-25s | %.2f |%n";
		System.out.format("+-----------------------------------------+%n");
		System.out.format("+--------------------MENU-----------------+%n");
		System.out.format("+------+---------------------------+------+%n");
		System.out.format("|S.No. | Food Item                 |Price |%n");
		System.out.format("+------+---------------------------+------+%n");
		for (int j = 0; j < foodIndex; j++ ) {
			System.out.format(leftAlignFormat, food[j].foodID, food[j].foodName, food[j].rate);
		}
		System.out.format("+------+---------------------------+------+%n");
    }
    void bill(int custID){
        String leftAlignFormat = "| %-4d | %-25s | %.2f |%n";
		int i = custID - 1001;
		System.out.format("+-----------------------------------------+%n");
		System.out.format("+--------------------BILL-----------------+%n");
		System.out.format("CustID:" + custID + "%n");
		System.out.format("+------+---------------------------+------+%n");
		System.out.format("|S.No. | Food Item                 |Price |%n");
		System.out.format("+------+---------------------------+------+%n");
		for (int j = 0; j < k[i].order.foodIDs.length; j++ ) 
			System.out.format(leftAlignFormat, k[i].order.foodIDs[j].foodID, k[i].order.foodIDs[j].foodName, k[j].order.foodIDs[j].rate);
        
        System.out.format("Cost:" + k[i].order.cost + "%n");
		System.out.format("+------+---------------------------+------+%n");
    }
}

class CustomerOrder{
    public static void main(String[] args) {
        Restaurant restaurant = new Restaurant();
        Random random = new Random();
        restaurant.loadMenu();
        System.out.println("Welcome to GS Restaurant");
        int custID = 0;
        restaurant.displayMenu();
            
        // let 5 customers arrived
        for (int i =0; i<5; i++){
            custID = 1000 + i + 1;
            int arrivalTime =  i ; 
            restaurant.customerQueue.add(new Restaurant().new CustomerInfo(custID, arrivalTime)); 

            double cost = 0;
            int tokenID = 2000 + i +1;
            int preparationTime = 0; 
            int numberOfFood = random.nextInt(5);
            FoodInfo foodIDs[] = new FoodInfo[numberOfFood];
            for (int j =0; j<numberOfFood; j++){
                foodIDs[j] = new Restaurant().new FoodInfo();
                foodIDs[j]=random.nextInt(restaurant.foodIndex);
                cost+=restaurant.food[foodIDs[j].foodID].rate;
                preparationTime+=random.nextInt(50);    
            }
            Restaurant.Orders order = new Restaurant().new Orders(tokenID, foodIDs, cost);
            restaurant.orderDispatch.add(tokenID);
            restaurant.k[i] = new Restaurant().new Kitchen();
            restaurant.k[i].order = order;
            restaurant.k[i].preparationTime = preparationTime;
        }

        for (int i = 0; i<5; i++){
            restaurant.bill(1000 + i + 1);
            restaurant.orderDispatch.remove();
        }
    }
}