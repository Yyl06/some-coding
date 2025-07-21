public abstract class Objects{
    protected String color;
    protected boolean filled;
    protected java.util.Date dateCreated;

    public Objects(){
        color = "green";
        filled = false;
        dateCreated = new java.util.Date();
    }

    public Objects(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
        dateCreated = new java.util.Date();
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public abstract double findArea();

    public abstract double findPerimeter();

    @Override
    public String toString(){
        return "Created on: " + dateCreated + "\n Color: " + color + "\n Filled: " + filled;
    }
}
