package models;

import java.time.LocalDate;

public class Studente {
    private LocalDate dataDiNascita;
    private String luogoDiNascita;
    private String nome;
    private String cognome;
    private int annoDiIscrizioneScuola;
    
    public Studente(LocalDate dataDiNascita, String luogoDiNascita, String nome, String cognome,
            int annoDiIscrizioneScuola) {
        this.dataDiNascita = dataDiNascita;
        this.luogoDiNascita = luogoDiNascita;
        this.nome = nome;
        this.cognome = cognome;
        this.annoDiIscrizioneScuola = annoDiIscrizioneScuola;
    }

    public LocalDate getDataDiNascita() {
        return dataDiNascita;
    }

    public void setDataDiNascita(LocalDate dataDiNascita) {
        this.dataDiNascita = dataDiNascita;
    }

    public String getLuogoDiNascita() {
        return luogoDiNascita;
    }

    public void setLuogoDiNascita(String luogoDiNascita) {
        this.luogoDiNascita = luogoDiNascita;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public int getAnnoDiIscrizioneScuola() {
        return annoDiIscrizioneScuola;
    }

    public void setAnnoDiIscrizioneScuola(int annoDiIscrizioneScuola) {
        this.annoDiIscrizioneScuola = annoDiIscrizioneScuola;
    }

    @Override
    public String toString() {
        return "Studente [nome=" + nome
                + ", cognome=" + cognome + "]";
    }

    
    
}
