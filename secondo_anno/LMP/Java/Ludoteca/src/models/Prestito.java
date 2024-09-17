package models;

import java.sql.Time;

public class Prestito {
    private Prodotto prodottoPrestato;
    private Time oraInizioPrestito;
    private String nomePersona;
    private Time oraFinePrestito;
    
    public Prestito(Prodotto prodottoPrestato, Time oraInizioPrestito, String nomePersona, Time oraFinePrestito) {
        this.prodottoPrestato = prodottoPrestato;
        this.oraInizioPrestito = oraInizioPrestito;
        this.nomePersona = nomePersona;
        this.oraFinePrestito = oraFinePrestito;
    }

    public Prodotto getProdottoPrestato() {
        return prodottoPrestato;
    }

    public void setProdottoPrestato(Prodotto prodottoPrestato) {
        this.prodottoPrestato = prodottoPrestato;
    }

    public Time getOraInizioPrestito() {
        return oraInizioPrestito;
    }

    public void setOraInizioPrestito(Time oraInizioPrestito) {
        this.oraInizioPrestito = oraInizioPrestito;
    }

    public String getNomePersona() {
        return nomePersona;
    }

    public void setNomePersona(String nomePersona) {
        this.nomePersona = nomePersona;
    }

    public Time getOraFinePrestito() {
        return oraFinePrestito;
    }

    public void setOraFinePrestito(Time oraFinePrestito) {
        this.oraFinePrestito = oraFinePrestito;
    }


    public Prestito finePrestito(Prestito prestito, Time fineUtilizzo){
        prestito.setOraFinePrestito(fineUtilizzo);
        return prestito;

    }
    
    
}
