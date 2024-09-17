package models;

import java.time.LocalDate;
import java.util.ArrayList;

public class Legge {
    private TipoLegge tipoLegge;
    private LocalDate dataLegge;
    private String identita;
    private ArrayList<Articolo> articoliLegge;
    private ArrayList<Object> allegatiLegge;
    private String conclusioniLegge;
    
    public Legge(TipoLegge tipoLegge, LocalDate dataLegge, String conclusioniLegge) {
        this.tipoLegge = tipoLegge;
        this.dataLegge = dataLegge;
        this.identita = dataLegge.toString() + tipoLegge.toString();
        this.articoliLegge = new ArrayList<>();
        this.allegatiLegge = new ArrayList<>();
        this.conclusioniLegge = conclusioniLegge;
    }

    public TipoLegge getTipoLegge() {
        return tipoLegge;
    }

    public void setTipoLegge(TipoLegge tipoLegge) {
        this.tipoLegge = tipoLegge;
    }

    public LocalDate getDataLegge() {
        return dataLegge;
    }

    public void setDataLegge(LocalDate dataLegge) {
        this.dataLegge = dataLegge;
    }

    public String getIdentita() {
        return identita;
    }

    public ArrayList<Articolo> getArticoliLegge() {
        return articoliLegge;
    }

    public void addArticoliLegge(Articolo articolo) {
        if(articolo == null){
            throw new IllegalArgumentException("L'articolo non va bene.");
        }
        articoliLegge.add(articolo);
    }

    public ArrayList<Object> getAllegatiLegge() {
        return allegatiLegge;
    }

    public void setAllegatiLegge(Object allegato) {
        if(allegato == null){
            throw new IllegalArgumentException("L'allegato è vuoto.");
        }
        allegatiLegge.add(allegato);
    }

    public String getConclusioniLegge() {
        return conclusioniLegge;
    }

    public void setConclusioniLegge(String conclusioniLegge) {
        this.conclusioniLegge = conclusioniLegge;
    }

    @Override
    public String toString() {
        return "Legge [tipoLegge=" + tipoLegge + ", dataLegge=" + dataLegge + "]";
    }
    
}
