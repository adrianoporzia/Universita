package services;
import java.util.HashMap;
import java.util.NoSuchElementException;

import models.Classe;
import models.Studente;

public class GestionePreside {
    private HashMap<String, Classe> classiScuola;

    public GestionePreside() {
        this.classiScuola = new HashMap<>();
    }

    public void addClasse(Classe classe){
        String nomeClasse = classe.getNomeClasse();
        classiScuola.put(nomeClasse, classe);
    }

                    
    public int getNumeriStudenti(Classe classe){
        if(!classiScuola.containsKey(classe.getNomeClasse())){
            throw new NoSuchElementException("Classe non esiste!");
        }
        return classiScuola.get(classe.getNomeClasse()).getStudentiClasse().size();
    }
                    
    public HashMap<Integer, Studente> getBocciatoPerClasse(Classe classe) {
        if (classiScuola.get(classe.getNomeClasse()).getNumeroStudentiClasse() == 0) {
            throw new NoSuchElementException("Non ci sono studenti");
        }
    
        int annoAtteso = classe.getAnnoStudentiRegolarmente();
        HashMap<Integer, Studente> mapBocciati = new HashMap<>();
    
        for (Studente s : classiScuola.get(classe.getNomeClasse()).getStudentiClasse()) {
            int annoIscrizioneStudente = s.getDataDiNascita().getYear();
            
            if (annoIscrizioneStudente < annoAtteso) {
                int anniBocciato = annoAtteso - annoIscrizioneStudente;
                mapBocciati.put(anniBocciato, s);
            }
        }
        System.out.println(mapBocciati);
        return mapBocciati;
    }
    
                    

    @Override
    public String toString() {
        return "GestionePreside [classiScuola=" + classiScuola + "]";
    }  
}
