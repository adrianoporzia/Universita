import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;
import java.util.logging.SimpleFormatter;

public class Person_Archive{
    private HashMap<String, Person> persone;

    public Person_Archive() {
        this.persone = new HashMap<>();
    }

    public void add_person(Person persona){
        String codiceFiscale = persona.getCodiceFiscale();
        if(persona != null && codiceFiscale != null){
            persone.put(persona.getCodiceFiscale(), persona);
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

    public Date formatData(String dataRaw){
        Date formattedData = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        try {
            formattedData = sdf.parse(dataRaw);
            System.out.println("Data inserita correttamente: " + formattedData);
        } catch (ParseException e) {
            System.out.println("Formato data non valido. Assicurati di inserire la data nel formato corretto.");
        }return formattedData;
    }

    public void createPerson(int numPersone){
        int i = 1;
        Scanner scanner = new Scanner(System.in);
        for(int j = 0; j < numPersone; j++){
            System.out.println("Benvenuto, stai creando la persona " + i);
            i++;
            System.out.println("Nome:");
            String nome = readInput(scanner);

            System.out.println("Cognome: ");
            String cognome = readInput(scanner);

            System.out.println("Data di nascita -> (dd/MMMM/yyyy)");
            String dataRaw = readInput(scanner);
            Date dataDiNascita = formatData(dataRaw);

            System.out.println("Codice Fiscale: ");
            String codiceFiscale = readInput(scanner);

            System.out.println("Inserisci: 1 -> impiegato | 2 -> libero professionista | 3 -> disoccupato ");
            int categoria = Integer.parseInt(readInput(scanner));

            switch (categoria){
                case 1:
                    System.out.println("Matricola: ");
                    String matricola = readInput(scanner);

                    System.out.println("Livello: ");
                    int livello = Integer.parseInt(readInput(scanner));

                    System.out.println("Mansione: ");
                    String mansione = readInput(scanner);

                    Impiegato p = new Impiegato(nome, cognome, dataDiNascita, codiceFiscale, matricola, livello, mansione);
                    persone.put(codiceFiscale, p);
                    break;
                case 2:
                    System.out.println("Professione: ");
                    String professione = readInput(scanner);

                    System.out.println("Partita iva: ");
                    String partitaIva = readInput(scanner);

                    Libero_Professionista p1 = new Libero_Professionista(nome, cognome, dataDiNascita, codiceFiscale,professione, partitaIva);
                    add_person(p1);
                    break;
                case 3:
                    System.out.println("Registro disoccupati: ");
                    String registro = readInput(scanner);

                    Disoccupato p2 = new Disoccupato(nome, cognome, dataDiNascita, codiceFiscale, registro);
                    add_person(p2);
                    break;
                default:
                    System.out.println("Input errato");
            }
        }
        scanner.close();
    }

    @Override
    public String toString() {
        return "Person_Archive{" +
                "persone=" + persone +
                '}';
    }
}
