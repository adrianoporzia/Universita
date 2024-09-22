package models;

import java.util.ArrayList;

public class Classe {
    private String sezione;
    private int annoDiCorso;  // 1 - 5
    private int annoStudentiRegolarmente;
    private String nomeClasse;
    private ArrayList<Studente> studentiClasse;

    public Classe(String sezione, int annoDiCorso, int annoStudentiRegolarmente) {
        this.sezione = sezione;
        this.annoDiCorso = annoDiCorso;
        this.annoStudentiRegolarmente = annoStudentiRegolarmente;
        this.nomeClasse = annoDiCorso + sezione;
        this.studentiClasse = new ArrayList<>();
    }

    public String getSezione() {
        return sezione;
    }

    public void setSezione(String sezione) {
        this.sezione = sezione;
    }

    public int getAnnoDiCorso() {
        return annoDiCorso;
    }

    public void setAnnoDiCorso(int annoDiCorso) {
        if(annoDiCorso < 1 || annoDiCorso > 5){
            throw new IllegalArgumentException("Anno deve essere compreso tra 1 e 5!");
        }
        this.annoDiCorso = annoDiCorso;
    }

    public int getAnnoStudentiRegolarmente() {
        return annoStudentiRegolarmente;
    }

    public void setAnnoStudentiRegolarmente(int annoStudentiRegolarmente) {
        this.annoStudentiRegolarmente = annoStudentiRegolarmente;
    }

    public String getNomeClasse() {
        return nomeClasse;
    }
 
    public ArrayList<Studente> getStudentiClasse() {
        return studentiClasse;
    }

    public int getNumeroStudentiClasse(){
        if(studentiClasse.size() == 0){
            return 0;
        }
        return studentiClasse.size();
    }
    public void addStudenteClasse(Studente studente){
        if(studente == null){
            throw new IllegalArgumentException("Studente non valido!");
        }
        studentiClasse.add(studente);
    }

    @Override
    public String toString() {
        return "Classe [Studenti=" + studentiClasse + "]";
    }
    
        
}
