package models;

import java.time.LocalDate;
import java.util.ArrayList;

public class Supporto {
    private String titolo;
    private String entePubblicante;
    private LocalDate dataDiPubblicazione;
    private ArrayList<Prestito> prestitiSupporto; 


    public Supporto(String titolo, String entePubblicante, LocalDate dataDiPubblicazione) {
        this.titolo = titolo;
        this.entePubblicante = entePubblicante;
        this.dataDiPubblicazione = dataDiPubblicazione;
        this.prestitiSupporto = new ArrayList<>();
    }


    public String getTitolo() {
        return titolo;
    }


    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }


    public String getEntePubblicante() {
        return entePubblicante;
    }


    public void setEntePubblicante(String entePubblicante) {
        this.entePubblicante = entePubblicante;
    }


    public LocalDate getDataDiPubblicazione() {
        return dataDiPubblicazione;
    }


    public void setDataDiPubblicazione(LocalDate dataDiPubblicazione) {
        this.dataDiPubblicazione = dataDiPubblicazione;
    }


    public ArrayList<Prestito> getPrestitiSupporto() {
        return prestitiSupporto;
    }


    public void setPrestitiSupporto(ArrayList<Prestito> prestitiSupporto) {
        this.prestitiSupporto = prestitiSupporto;
    }

    
    
    
    
}
