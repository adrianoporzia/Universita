import java.util.Arrays;

public class MaxMinArray {
    private int[] buffer;

    public MaxMinArray(int len) {
        buffer = new int[len];
    }

    public int getMax(){
        int massimo = buffer[0];
        if(buffer.length < 0 ){
            System.out.println("Errore in input");
            return -1;
        }
        for(int i = 0; i < buffer.length; i++){
            if(massimo < buffer[i]){
                massimo = buffer[i];
            }
        }
        return massimo;
    }

    public int getMin(){
        int minimo = buffer[0];
        if(buffer.length < 0 ){
            System.out.println("Errore in input");
            return -1;
        }
        for(int i = 0; i < buffer.length; i++){
            if(minimo > buffer[i]){
                minimo = buffer[i];
            }
        }
        return minimo;
    }

    public void addNumero(int i, int numero){
        buffer[i] = numero;
    }


    @Override
    public String toString() {
        return "MaxMinArray [buffer=" + Arrays.toString(buffer) + "]";
    }

    
    
    
}
