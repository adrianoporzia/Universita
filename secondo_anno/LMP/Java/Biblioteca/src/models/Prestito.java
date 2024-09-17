package models;

import java.time.LocalDate;

public class Prestito {
    private LocalDate dataInizioPrestito;
    private LocalDate dataPrevistaConsegna;
    private LocalDate dataEffettivaConsegna;
    private String nomeCognomeUtente;
    private double costoAffitto;
    
    public Prestito(LocalDate dataInizioPrestito, LocalDate dataPrevistaConsegna, LocalDate dataEffettivaConsegna,
            String nomeCognomeUtente, double costoAffitto, Supporto supportoPrestato) {
        this.dataInizioPrestito = dataInizioPrestito;
        this.dataPrevistaConsegna = dataPrevistaConsegna;
        this.dataEffettivaConsegna = dataEffettivaConsegna;
        this.nomeCognomeUtente = nomeCognomeUtente;
        this.costoAffitto = costoAffitto;
    }

    public LocalDate getDataInizioPrestito() {
        return dataInizioPrestito;
    }

    public void setDataInizioPrestito(LocalDate dataInizioPrestito) {
        this.dataInizioPrestito = dataInizioPrestito;
    }

    public LocalDate getDataPrevistaConsegna() {
        return dataPrevistaConsegna;
    }

    public void setDataPrevistaConsegna(LocalDate dataPrevistaConsegna) {
        this.dataPrevistaConsegna = dataPrevistaConsegna;
    }

    public LocalDate getDataEffettivaConsegna() {
        return dataEffettivaConsegna;
    }

    public void setDataEffettivaConsegna(LocalDate dataEffettivaConsegna) {
        this.dataEffettivaConsegna = dataEffettivaConsegna;
    }

    public String getNomeCognomeUtente() {
        return nomeCognomeUtente;
    }

    public void setNomeCognomeUtente(String nomeCognomeUtente) {
        this.nomeCognomeUtente = nomeCognomeUtente;
    }

    public double getCostoAffitto() {
        return costoAffitto;
    }

    public void setCostoAffitto(double costoAffitto) {
        this.costoAffitto = costoAffitto;
    }

    

}
