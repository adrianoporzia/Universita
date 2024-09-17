package models;

public class Articolo {
    private static int count = 0;
    private int numArticolo;
    private String introduzione;
    private String commi;


    public Articolo(int numArticolo, String introduzione, String commi) {
        this.numArticolo = ++count;
        this.introduzione = introduzione;
        this.commi = commi;
    }


    public int getNumArticolo() {
        return numArticolo;
    }


    public String getIntroduzione() {
        return introduzione;
    }


    public void setIntroduzione(String introduzione) {
        this.introduzione = introduzione;
    }


    public String getCommi() {
        return commi;
    }


    public void setCommi(String commi) {
        this.commi = commi;
    }


    
    
}
