import java.time.LocalDate;
import java.time.Month;
import java.util.ArrayList;
import java.util.HashMap;
import models.Sportivo;
import models.TipoSportivo;
import services.GestioneSportivi;

public class Main {

    public static void main(String[] args) {
        // Imposta minReti a 10
        GestioneSportivi gs = new GestioneSportivi(10);
        
        // Aggiungi sportivi
        Sportivo Adriano = new Sportivo("Adriano", "Porzia", LocalDate.of(2024, 6, 9), 3, TipoSportivo.GIOCATORE);
        Adriano.addReti(Month.MAY, 20);
        Adriano.addReti(Month.JUNE, 11);
        Adriano.addReti(Month.NOVEMBER, 6);
        Adriano.addReti(Month.NOVEMBER, 5);

        Sportivo Ionut = new Sportivo("Ionut", "Zbirciog", LocalDate.of(2024, 6, 9), 4, TipoSportivo.GIOCATORE);
        Ionut.addReti(Month.AUGUST, 11);

        gs.addSportivo(Adriano);
        gs.addSportivo(Ionut);


        //Sportivo Jack
        Sportivo Jack = new Sportivo("Jack", "Pace", LocalDate.of(2024, 6, 9), 4, TipoSportivo.GIOCATORE);
        Jack.addReti(Month.AUGUST, 11);

        gs.addSportivo(Jack);

        // Aggiungi Luca e inserisci le reti
        gs.addSportivo("Luca", "Marfella", LocalDate.now(), 5, TipoSportivo.GIOCATORE);
        Sportivo Luca = gs.getSportivo("Luca", "Marfella");
        Luca.addReti(Month.JULY, 12);  // Aggiungi reti per Luca

        // Ottieni e stampa i premiati
        HashMap<Integer, ArrayList<Sportivo>> premiati = gs.getPremiati();
        ArrayList<Sportivo> doppioni = gs.getDoppioni();


        //STAMPE DOPPIONI

        if (premiati.isEmpty()) {
            System.out.println("Nessun sportivo ha raggiunto il numero minimo di reti.");
        } else {
            System.out.println("Lista dei doppioni:\n");
            int counter = 1;
            for (Sportivo d : doppioni) {
                System.out.println("Doppione #" + counter + ":");
                System.out.println("Nome: " + d.getNome());
                System.out.println("Cognome: " + d.getCognome());
                System.out.println("Data di Assunzione: " + d.getDataAssunzione());
                System.out.println("Tipo Sportivo: " + d.getTipoSportivo());
                System.out.println("-----------------------------------");
                counter++;
            }
        }
        
        //STAMPE PREMIATI

        if (premiati.isEmpty()) {
            System.out.println("Nessun sportivo ha raggiunto il numero minimo di reti.");
        } else {
            System.out.println("Lista premiati:");
            for (int mesi : premiati.keySet()) {
                System.out.println("\nSportivi che hanno segnato almeno " + gs.getMinReti() + " reti in " + mesi + " mesi:");
                for (Sportivo sportivo : premiati.get(mesi)) {
                    System.out.println("- " + sportivo.getNome() + " " + sportivo.getCognome() 
                                       + " (Livello stipendiale: " + sportivo.getLivelloStipendiale() 
                                       + ", Data assunzione: " + sportivo.getDataAssunzione() + ")");
                }
            }
        }
    }
}
