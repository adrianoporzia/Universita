package models;

import java.time.Duration;
import java.time.LocalDate;

public class Gioco extends Prodotto {
    private Duration durataMediaUtilizzo;

    

    public Gioco(String titolo, String autore, String casaEditrice, LocalDate dataDiPubblicazione,
            Duration durataMediaUtilizzo) {
        super(titolo, autore, casaEditrice, dataDiPubblicazione);
        this.durataMediaUtilizzo = durataMediaUtilizzo;
    }

    public Duration getDurataMediaUtilizzo() {
        return durataMediaUtilizzo;
    }

    public String durataMediaFormattata() {
        long ore = durataMediaUtilizzo.toHours();
        long minuti = durataMediaUtilizzo.toMinutesPart();
        long secondi = durataMediaUtilizzo.toSecondsPart();

        return String.format("%d ore, %d minuti, %d secondi", ore, minuti, secondi);
    }

    public void setDurataMediaUtilizzo(Duration durataMediaUtilizzo) {
        this.durataMediaUtilizzo = durataMediaUtilizzo;
    }

    @Override
    public String toString() {
        return super.toString() + ", Durata media di utilizzo: " + durataMediaFormattata();
    }
}
