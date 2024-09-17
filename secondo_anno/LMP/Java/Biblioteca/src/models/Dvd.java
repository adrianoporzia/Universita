package models;

import java.time.LocalDate;

public class Dvd extends Supporto{
    private double durata;

    public Dvd(String titolo, String entePubblicante, LocalDate dataDiPubblicazione, double durata) {
        super(titolo, entePubblicante, dataDiPubblicazione);
        this.durata = durata;
    }

    public double getDurata() {
        return durata;
    }

    public void setDurata(double durata) {
        this.durata = durata;
    }
    
    
    
}
