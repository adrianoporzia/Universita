package services;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import models.ProvaStudente;

public class Esame {
    private ArrayList<ProvaStudente> proveTotaliEsame;
    private LocalDate dataEsame;
    private int modalitaEsame;

    public Esame(LocalDate dataEsame, int modalitaEsame) {
        this.proveTotaliEsame = new ArrayList<>();
        this.dataEsame = dataEsame;
        this.modalitaEsame = modalitaEsame;
    }


    public LocalDate getDataEsame() {
        return dataEsame;
    }

    public void setDataEsame(LocalDate dataEsame) {
        this.dataEsame = dataEsame;
    }

    public int getNumeroPartecipanti(){
        return proveTotaliEsame.size();
    }

    public int getmodalitaEsame(){
        return modalitaEsame;
    }

    public void setModalitaEsame(int modalitaEsame) {
        this.modalitaEsame = modalitaEsame;

    }

    public void addProve(ProvaStudente prova){
        proveTotaliEsame.add(prova);
    }
    
    public int getNumeroPromossi(){
        if (proveTotaliEsame.size() == 0) {
            throw new NoSuchElementException("Non ci sono partecipanti");  
        }
        int numPromossi = 0;
        for(ProvaStudente p : proveTotaliEsame){
            if(p.isPromosso()){
                numPromossi++;
            }
        }
        return numPromossi;
    }
    
    public int getPercentualePromossi(){

        int numPromossi = getNumeroPromossi();  
        int numeroPartecipanti = getNumeroPartecipanti();
    
        if (numeroPartecipanti == 0) {
            throw new NoSuchElementException("Non ci sono partecipanti");  
        }
    
        return (numPromossi * 100) / numeroPartecipanti;
    }

    public ProvaStudente getProvaStudente(int matricola){
        if (proveTotaliEsame.size() == 0) {
            throw new NoSuchElementException("Non ci sono partecipanti");  
        }
        for(ProvaStudente p : proveTotaliEsame){
            if(p.getMatricola() == matricola){
                return p;
            }
        }
        return null;
    }
    


}
