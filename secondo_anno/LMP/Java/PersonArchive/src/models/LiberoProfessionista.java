package models;

import java.time.LocalDate;

public class LiberoProfessionista extends Person{
    private String professione;
    private int numPartivaIva;
    
    public LiberoProfessionista(String nome, String cognome, LocalDate dataDiNascita, String codiceFiscale,
            String professione, int numPartivaIva) {
        super(nome, cognome, dataDiNascita, codiceFiscale);
        this.professione = professione;
        this.numPartivaIva = numPartivaIva;
    }

    public String getProfessione() {
        return professione;
    }

    public void setProfessione(String professione) {
        this.professione = professione;
    }

    public int getNumPartivaIva() {
        return numPartivaIva;
    }

    public void setNumPartivaIva(int numPartivaIva) {
        if(numPartivaIva < 0){
            throw new IllegalArgumentException("Numero partita Iva non compatibile!");
        }
        this.numPartivaIva = numPartivaIva;
    }

    @Override
    public String toString() {
        return super.toString() + "LiberoProfessionista [professione=" + professione + ", numPartivaIva=" + numPartivaIva + "]";
    }

    
    
}
