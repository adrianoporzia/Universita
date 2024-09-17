package models;

import java.time.LocalDate;

public class Libro extends Prodotto{
    private int numeroPagine;

    public Libro(String titolo, String autore, String casaEditrice, LocalDate dataDiPubblicazione, int numeroPagine) {
        super(titolo, autore, casaEditrice, dataDiPubblicazione);
        this.numeroPagine = numeroPagine;
    }

    public int getNumeroPagine() {
        return numeroPagine;
    }

    public void setNumeroPagine(int numeroPagine) {
        this.numeroPagine = numeroPagine;
    }

    
    
}
