class restaurant{
    class customerInfo{
        int custID;
        int arrivalTime;
    }
    class foodInfo{
        int foodID;
        String foodName;
        float rate;
    }
    class orders{ 
        int tokenID;
        float cost;
    }
    class kitchen{
        orders order;
        int preparationTime;
    }
    static int custID = 0 , ordersInKitchen = 0 , tokenID = 0 , foodIndex = 0;
    foodInfo food[100];
    orders order;
    kitchen k[100];
    queue<customerInfo> customerQueue;
    queue<int> orderDispatch;
    
    
    void setFoodItems(int id, string name, float rate) {
        food[foodIndex].foodID = id;
        food[foodIndex].foodName = name;
        food[foodIndex].rate = rate;
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
}
