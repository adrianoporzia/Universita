package models;

import java.time.LocalDate;

public class Dipendente {
    private String nome;
    private String cognome;
    private LocalDate dataDiNascita;
    private LocalDate dataDiAssunzione;
    private String matricola;
    private int count = 0;
    private Dipartimento dipartimento;
    private Mansione mansione;
    private int livello;
    private Dipendente capoDiretto;

    public Dipendente(String nome, String cognome, LocalDate dataDiNascita, LocalDate dataDiAssunzione,
            Dipartimento dipartimento, Mansione mansione, int livello, Dipendente capoDiretto) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataDiNascita = dataDiNascita;
        this.dataDiAssunzione = dataDiAssunzione;
        this.matricola = "CLT_" + ++count;
        this.dipartimento = dipartimento;
        this.mansione = mansione;
        this.livello = livello;
        this.capoDiretto = capoDiretto;
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

    public Dipartimento getDipartimento() {
        return dipartimento;
    }

    public void setDipartimento(Dipartimento dipartimento) {
        this.dipartimento = dipartimento;
    }

    public Mansione getMansione() {
        return mansione;
    }

    public void setMansione(Mansione mansione) {
        this.mansione = mansione;
    }

    public int getLivello() {
        return livello;
    }

    public void setLivello(int livello) {
        if(livello < 1 || livello > 8){
            throw new IllegalArgumentException("Livello non compreso tra 1 e 8");
        }
        this.livello = livello;
    }

    public Dipendente getCapoDiretto() {
        return capoDiretto;
    }

    public void setCapoDiretto(Dipendente capoDiretto) {
        this.capoDiretto = capoDiretto;
    }

    @Override
    public String toString() {
        return "Dipendente [nome=" + nome + ", cognome=" + cognome + ", matricola=" + matricola + "]";
    }

    
}
