package models;

import java.time.LocalDate;

public class Person {
    
    private String nome;
    private String cognome;
    private LocalDate dataDiNascita;
    private String codiceFiscale;

    public Person(String nome, String cognome, LocalDate dataDiNascita, String codiceFiscale) {
        this.nome = nome;
        this.cognome = cognome;
        this.setDataDiNascita(dataDiNascita);
        this.codiceFiscale = codiceFiscale;
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

    public LocalDate getDataDiNascita() {
        return dataDiNascita;
    }

    public void setDataDiNascita(LocalDate dataDiNascita) {
        int year = dataDiNascita.getYear();
        if(year < 1900){
            throw new IllegalArgumentException("Anno minore 1900!");
        }
        this.dataDiNascita = dataDiNascita;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public void setCodiceFiscale(String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
    }

    @Override
    public String toString() {
        return "Person [nome=" + nome + ", cognome=" + cognome + ", dataDiNascita=" + dataDiNascita + ", codiceFiscale="
                + codiceFiscale + "]";
    }

}
