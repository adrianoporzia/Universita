import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner scanner = new Scanner(System.in);
        System.out.println("La lunghezza dell'array è: ");
        int lenArray = scanner.nextInt();

        MaxMinArray array = new MaxMinArray(lenArray);
        for(int i = 0; i < lenArray; i++){
            System.out.println("Inserisci il numero in posizione" + i);
            int numero = scanner.nextInt();
            array.addNumero(i, numero);
        }

        System.out.println("Il minimo nell'array è: ");
        System.out.println(array.getMin());

        System.out.println("Il massimo nell'array è: ");
        System.out.println(array.getMax());

        

    }
}
