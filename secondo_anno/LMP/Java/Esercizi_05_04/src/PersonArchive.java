import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Scanner;

public class PersonArchive {

    private HashMap<String, Person> personArchive;

    public PersonArchive() {
        this.personArchive = new HashMap<>();
    }

    public boolean add_person(Person person) {
        String codice = person.getCodiceFiscale();
        if (person != null && codice != null) {
            personArchive.put(person.getCodiceFiscale(), person);
            return true;
        }
        return false;
    }

    public String readInput(Scanner scanner) {
        String output = "";
        try {
            output = scanner.nextLine();
        } catch (Exception e) {
            System.out.println("Errore input");
        }
        return output;

    }

    public void createPerson(int numPers) {
        System.out.println("Generazione persone in corso:");
        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < numPers; i++) {
            System.out.println("Inserire:");
            System.out.println("Nome:");
            String nome = this.readInput(scanner);

            System.out.println("Cognome:");
            String cognome = this.readInput(scanner);

            System.out.println("Data: dd/mm/yyyy");
            String dataRaw = this.readInput(scanner);
            Date fortattedData = new Date();
            SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

            System.out.println("Codice Fiscale:");
            String codiceFiscale = this.readInput(scanner);

            try {
                fortattedData = sdf.parse(dataRaw); // Proviamo a fare il parsing della data
                System.out.println("Data inserita correttamente: " + fortattedData);
            } catch (ParseException e) {
                System.out.println("Formato data non valido. Assicurati di inserire la data nel formato corretto.");
            }

            System.out.println("""
                    Inserire: \s
                    [Impiegato]: 1\s
                    [Libero Professionista]: 2\s
                    [Disoccupato]: 3\s """);
            int tipo = Integer.parseInt(this.readInput(scanner));
            switch (tipo) {
                case 1:
                    System.out.println("Inserire");
                    System.out.println("Matricola: ");
                    String matricola = this.readInput(scanner);

                    System.out.println("Livello: ");
                    String livello = this.readInput(scanner);

                    System.out.println("Mansione: ");
                    String mansione = this.readInput(scanner);
                    Impiegato p = new Impiegato(nome, cognome, fortattedData, codiceFiscale, matricola, livello, mansione);
                    break;
                case 2:
                    System.out.println("Inserire");
                    System.out.println("Professione: ");
                    String professione = this.readInput(scanner);

                    System.out.println("PartitaIva");
                    String partitaIva = this.readInput(scanner);

                    Libero_Professionista p1 = new Libero_Professionista(nome, cognome, fortattedData , codiceFiscale, professione, partitaIva);
                    break;
                case 3:
                    System.out.println("Inserire");
                    System.out.println("Registro disoccupati:");
                    String registro = readInput(scanner);

                    Disoccupato p2 = new Disoccupato(nome, cognome, fortattedData , codiceFiscale, registro);
                    break;
                default:
                    System.out.println("Input errato");
                    break;
            }
        }
        scanner.close();
    }
}

