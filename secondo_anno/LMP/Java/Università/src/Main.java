import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Archivio torVergata = new Archivio();
        int i = 0;

    public void createStudenti(){
        Scanner scanner = new Scanner(System.in);
        int i = 0;
        while(i < 2){
            System.out.println("Nome studente: ");
            String nome = readInput(scanner);
            
            Studente st = new Studente(nome, );

        }
    }


    public String readInput(Scanner scanner){
        String output = "";
        try{
            output = scanner.nextLine();
        }catch(Exception e){
            System.out.println("Errore in input");
        }return output;
    }




}
