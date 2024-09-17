package models;

import java.util.ArrayList;

public class Prodotto {
    private String identificativo;
    private String etichettaDiRiferimento;
    private double costoDiProduzione;
    private double prezzoPerAcquirenti;
    private ArrayList<Componente> componentiAutomobile;
    private ArrayList<Componente> componentiAutomobilePubblici;
    private ArrayList<Componente> componentiAutomobilePrivati;
    private int numeroComponentiNecessari;      //size array
    private int tempoStimatoOrdineComponenti;   //max tra tutti
    private int tempoProduzioneProdotto;
    private int tempoAssemblaggioProdotto; 
    private int costoProduzioneProdotto; //c * giorni produzione
    private int costoGiornalieroProduzione;

    public Prodotto(String identificativo, String etichettaDiRiferimento, double costoDiProduzione,
            double prezzoPerAcquirenti, int tempoProduzioneProdotto, int tempoAssemblaggioProdotto,
            int costoGiornalieroProduzione) {
        this.identificativo = identificativo;
        this.etichettaDiRiferimento = etichettaDiRiferimento;
        this.costoDiProduzione = costoDiProduzione;
        this.prezzoPerAcquirenti = prezzoPerAcquirenti;
        this.componentiAutomobile = new ArrayList<>();
        this.componentiAutomobilePubblici = new ArrayList<>();
        this.componentiAutomobilePrivati = new ArrayList<>();
        this.numeroComponentiNecessari = componentiAutomobile.size();
        this.setTempoStimatoOrdineComponenti();
        this.tempoProduzioneProdotto = tempoProduzioneProdotto;
        this.tempoAssemblaggioProdotto = tempoAssemblaggioProdotto;
        this.costoProduzioneProdotto = getCostoGiornalieroProduzione() * tempoAssemblaggioProdotto;
        this.costoGiornalieroProduzione = costoGiornalieroProduzione;
    }

    public String getIdentificativo() {
        return identificativo;
    }

    public void setIdentificativo(String identificativo) {
        this.identificativo = identificativo;
    }

    public String getEtichettaDiRiferimento() {
        return etichettaDiRiferimento;
    }

    public void setEtichettaDiRiferimento(String etichettaDiRiferimento) {
        this.etichettaDiRiferimento = etichettaDiRiferimento;
    }

    public double getCostoDiProduzione() {
        return costoDiProduzione;
    }

    public void setCostoDiProduzione(double costoDiProduzione) {
        this.costoDiProduzione = costoDiProduzione;
    }

    public double getPrezzoPerAcquirenti() {
        return prezzoPerAcquirenti;
    }

    public void setPrezzoPerAcquirenti(double prezzoPerAcquirenti) {
        this.prezzoPerAcquirenti = prezzoPerAcquirenti;
    }

    public ArrayList<Componente> getComponentiAutomobile() {
        return componentiAutomobile;
    }

    public void setComponentiAutomobile(ArrayList<Componente> componentiAutomobile) {
        this.componentiAutomobile = componentiAutomobile;
    }

    public int getNumeroComponentiNecessari() {
        return numeroComponentiNecessari;
    }

    public void setNumeroComponentiNecessari(int numeroComponentiNecessari) {
        this.numeroComponentiNecessari = numeroComponentiNecessari;
    }

    public int getTempoStimatoOrdineComponenti() {
        return tempoStimatoOrdineComponenti;
    }

    public void setTempoStimatoOrdineComponenti() {
        int max = 0;
        for(Componente c : componentiAutomobile){
            if(c.getGiorniOrdinazioneComponenti() > max){
                max = c.getGiorniOrdinazioneComponenti();
            }
        }
        this.tempoStimatoOrdineComponenti = max;
    }

    public int getTempoProduzioneProdotto() {
        return tempoProduzioneProdotto;
    }

    public void setTempoProduzioneProdotto(int tempoProduzioneProdotto) {
        this.tempoProduzioneProdotto = tempoProduzioneProdotto;
    }

    public int getTempoAssemblaggioProdotto() {
        return tempoAssemblaggioProdotto;
    }

    public void setTempoAssemblaggioProdotto(int tempoAssemblaggioProdotto) {
        this.tempoAssemblaggioProdotto = tempoAssemblaggioProdotto;
    }

    public int getCostoGiornalieroProduzione() {
        return costoGiornalieroProduzione;
    }


    public double costoComplessivoComponenti(){
        double somma = 0;
        for(Componente c : componentiAutomobile){
            somma = somma + c.getCostoComponente();
        }
        return somma;
    }

    public double costoComplessivoProduzione(){
        double somma = 0;
        somma = getCostoDiProduzione() + costoComplessivoComponenti();
        return somma;
    }

    public double getFattoreGuadagno(){
        double guadagno = 0;
        guadagno = getPrezzoPerAcquirenti() - costoComplessivoProduzione();
        return guadagno; 
    }



    public void addComponente(Componente componente){
        if(componente == null){
            throw new IllegalArgumentException("Componente non valido");
        }
        componentiAutomobile.add(componente);
        if(componente.isPrivato()){
            componentiAutomobilePrivati.add(componente);
        }
        else{
            componentiAutomobilePubblici.add(componente);
        }
    }

    @Override
    public String toString() {
        return "Prodotto [identificativo=" + identificativo + ", etichettaDiRiferimento=" + etichettaDiRiferimento
                + ", prezzoPerAcquirenti=" + prezzoPerAcquirenti + ", componentiAutomobilePubblici="
                + componentiAutomobilePubblici + "]";
    }

    
}
