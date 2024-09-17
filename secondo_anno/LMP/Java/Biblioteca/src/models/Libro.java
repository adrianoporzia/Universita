package models;

import java.time.LocalDate;

public class Libro extends Supporto{
    private int numeroPagine;

    public Libro(String titolo, String entePubblicante, LocalDate dataDiPubblicazione, int numeroPagine) {
        super(titolo, entePubblicante, dataDiPubblicazione);
        this.numeroPagine = numeroPagine;
    }

    public int getNumeroPagine() {
        return numeroPagine;
    }

    public void setNumeroPagine(int numeroPagine) {
        this.numeroPagine = numeroPagine;
    }

    
    
}
