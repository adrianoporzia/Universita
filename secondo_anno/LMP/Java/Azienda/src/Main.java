import java.time.LocalDate;

import models.Dipartimento;
import models.Dipendente;
import models.Mansione;
import services.TitolareAzienda;

public class Main {
   public static void main(String[] args) {

        TitolareAzienda azienda = new TitolareAzienda();

        Dipendente adriano = new Dipendente("Adriano", "Porzia", LocalDate.of(2003, 11, 23), LocalDate.of(2023, 9, 27), Dipartimento.MARKETING, Mansione.TECNICO, 8, null);
        Dipendente ionut = new Dipendente("Ionut", "Zbirciog", LocalDate.of(2002, 7, 7), LocalDate.of(2023, 7, 7), Dipartimento.RISORSE_UMANE, Mansione.FABBRO, 7, adriano);
        Dipendente francesco = new Dipendente("Francesco", "Cosciotti", LocalDate.of(2001, 7, 7), LocalDate.of(2024, 7, 7), Dipartimento.RISORSE_UMANE, Mansione.SEGRETARIO, 3, ionut);
        Dipendente domenico = new Dipendente("Domenico", "Sabatini", LocalDate.of(2003, 10, 6), LocalDate.of(2023, 1, 5), Dipartimento.SVILUPPO, Mansione.SEGRETARIO, 3, ionut);


        azienda.addDipendente(adriano);
        azienda.addDipendente(ionut);
        azienda.addDipendente(francesco);

        System.out.println("La chain of command da francesco è : ");
        azienda.getChainOfCommand(francesco);
        
        System.out.println("----------------------------");

        System.out.println("Il sostituto di francesco è : ");
        azienda.getSostituto(francesco);

        System.out.println("----------------------------");

   } 
}
