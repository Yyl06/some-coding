public class WhichEdible {
    public static void main(String[] args) {
        Object[] objects = {new Tiger(), new Chicken(), new Apple()};
        //Why for when u can use foreach
        for (Object o : objects) {
            showObject(o);
        }
    }
    public static void showObject(Object obj){
        if(obj instanceof Edible edible){
            System.out.println(edible.howToEat());
        }
    }
}