import java.util.HashMap;
import java.util.Scanner;

public class Archivio {
    private HashMap<Cliente, Automobile> archivio;

    public Archivio() {
        this.archivio = new HashMap<>();   
    }

    public void addMacchine(Automobile auto){
        if(auto == null && auto.getProprietario() == null){
            System.out.println("Errore input");
        }else{
            archivio.put(auto.getProprietario(), auto);
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

    public int readInputInt(Scanner scanner){
        int output = -1;
        try{
            output = scanner.nextInt();
        }catch(Exception e){
            System.out.println("Errore in input");
        }return output;
    }


    public void createArchive(int numeroAuto){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Benvenuto, aggiungi all'archivo: ");
        for(int j = 0; j < numeroAuto; j++){
            System.out.println("Stiamo aggiungendo: ");
            System.out.println("Nome cliente: ");
            String nome = readInput(scanner);

            System.out.println("Cognome cliente: ");
            String cognome = readInput(scanner);

            Cliente cliente = new Cliente(nome, cognome);

            System.out.println("Targa del veicolo del cliente " + cliente.getName() + " " + cliente.getCognome());
            int targa = readInputInt(scanner);

            Automobile auto = new Automobile(targa, cliente);

            archivio.put(cliente, auto);

        }
        System.out.println(archivio);
        scanner.close();
    }

    @Override
    public String toString() {
        return "Archivio [archivio=" + archivio + "]";
    }

    

    
    
    
}
