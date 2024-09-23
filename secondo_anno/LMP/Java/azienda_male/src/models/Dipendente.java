package models;

import java.time.LocalDate;

public class Dipendente {

    public enum Dipartimento{
        MARKETING, RISORSE_UMANE, SVILUPPO
    }

    private String  nome;
    private String cognome;
    private LocalDate dataDiNascita;
    private LocalDate dataDiAssunzione;

    private static int count = 1;
    private String matricola;
    private Dipartimento dipartimentoDipendente;
    private Mansione mansioneDipendente;
    private int livello;
    private Dipendente capoDiretto;

    public Dipendente(String nome, String cognome, LocalDate dataDiNascita, LocalDate dataDiAssunzione,
            Dipartimento dipartimentoDipendente, Mansione mansioneDipendente, int livello) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = dataDiNascita;
        this.dataDiAssunzione = dataDiAssunzione;
        this.matricola = "CLT_" + count++;
        this.dipartimentoDipendente = dipartimentoDipendente;
        this.mansioneDipendente = mansioneDipendente;
        this.livello = livello;
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
        this.dataDiNascita = dataDiNascita;
    }

    public LocalDate getDataDiAssunzione() {
        return dataDiAssunzione;
    }

    public void setDataDiAssunzione(LocalDate dataDiAssunzione) {
        this.dataDiAssunzione = dataDiAssunzione;
    }

    public String getMatricola() {
        return matricola;
    }

    public void setMatricola(String matricola) {
        this.matricola = matricola;
    }

    public Dipartimento getDipartimentoDipendente() {
        return dipartimentoDipendente;
    }

    public void setDipartimentoDipendente(Dipartimento dipartimentoDipendente) {
        this.dipartimentoDipendente = dipartimentoDipendente;
    }

    public Mansione getMansioneDipendente() {
        return mansioneDipendente;
    }

    public void setMansioneDipendente(Mansione mansioneDipendente) {
        this.mansioneDipendente = mansioneDipendente;
    }

    public int getLivello() {
        return livello;
    }

    public void setLivello(int livello) {
        this.livello = livello;
    }

    public Dipendente getCapoDiretto() {
        return capoDiretto;
    }

    
}
