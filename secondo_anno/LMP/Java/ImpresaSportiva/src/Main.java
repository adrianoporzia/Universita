import java.time.LocalDate;
import java.time.Month;

import models.Sportivo;
import models.TipoSportivo;
import services.GestioneSportivo;

public class Main {
    public static void main(String[] args) {
        GestioneSportivo gs = new GestioneSportivo(1);

        Sportivo adriano = new Sportivo("Adriano", "Porzia", LocalDate.of(2024, 11, 11), TipoSportivo.GIOCATORE, 4);
        Sportivo ionut = new Sportivo("Ionut", "Zbirciog", LocalDate.of(2024, 11, 11), TipoSportivo.GIOCATORE, 3);
        Sportivo domenico = new Sportivo("Domenico", "Sabatini", LocalDate.of(2022, 11, 7), TipoSportivo.ALLENATORE, 5);

        gs.addSportivo(adriano);
        gs.addSportivo(ionut);
        gs.addSportivo(domenico);

        adriano.setGolPerMese(0, 5);  
        adriano.setGolPerMese(1, 2);  
        adriano.setGolPerMese(2, 8);  

        ionut.setGolPerMese(0, 7);    
        ionut.setGolPerMese(2, 11);    
        ionut.setGolPerMese(11, 33);   

        
        domenico.setGolPerMese(5, 6);  

        gs.doppioniData(Month.NOVEMBER , 2024);
        gs.getPremiatiPerBonus(5);
    }
}
