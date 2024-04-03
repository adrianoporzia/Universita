public class Casa {
    int  red;
    int green;
    int blue;

    Casa(int red, int green, int blue){
        this.red = red;
        this.green = green;
        this.blue = blue;
    }

    @Override
    public String toString() {
        return "Casa{" +
                "red=" + red +
                ", green=" + green +
                ", blue=" + blue +
                '}';
    }


}
