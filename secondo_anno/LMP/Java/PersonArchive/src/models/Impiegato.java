package models;

import java.time.LocalDate;

public class Impiegato extends Person{
    private static int counter = 0;
    private String matricola;
    private int livello;
    private String mansione;
    
    
    public Impiegato(String nome, String cognome, LocalDate dataDiNascita, String codiceFiscale,
            int livello, String mansione) {
        super(nome, cognome, dataDiNascita, codiceFiscale);
        this.matricola = "Matricola_" + (++counter);
        this.livello = livello;
        this.mansione = mansione;
    }


    public String getMatricola() {
        return matricola;
    }


    public int getLivello() {
        return livello;
    }


    public void setLivello(int livello) {
        this.livello = livello;
    }


    public String getMansione() {
        return mansione;
    }


    public void setMansione(String mansione) {
        this.mansione = mansione;
    }


    @Override
    public String toString() {
        return super.toString() + "Impiegato [matricola=" + matricola + ", livello=" + livello + ", mansione=" + mansione + "]";
    }

    

    
    
}
