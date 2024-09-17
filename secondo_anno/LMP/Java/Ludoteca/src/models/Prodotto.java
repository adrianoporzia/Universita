package models;

import java.time.LocalDate;

public class Prodotto {
    private String titolo;
    private String autore;
    private String casaEditrice;
    private LocalDate dataDiPubblicazione;

    
    public Prodotto(String titolo, String autore, String casaEditrice, LocalDate dataDiPubblicazione) {
        this.titolo = titolo;
        this.autore = autore;
        this.casaEditrice = casaEditrice;
        this.dataDiPubblicazione = dataDiPubblicazione;
    }


    public String getTitolo() {
        return titolo;
    }


    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }


    public String getAutore() {
        return autore;
    }


    public void setAutore(String autore) {
        this.autore = autore;
    }


    public String getCasaEditrice() {
        return casaEditrice;
    }


    public void setCasaEditrice(String casaEditrice) {
        this.casaEditrice = casaEditrice;
    }


    public LocalDate getDataDiPubblicazione() {
        return dataDiPubblicazione;
    }


    public void setDataDiPubblicazione(LocalDate dataDiPubblicazione) {
        this.dataDiPubblicazione = dataDiPubblicazione;
    }


   
    
    
}
