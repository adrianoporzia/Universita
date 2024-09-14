package services;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.NoSuchElementException;

import models.Sportivo;
import models.TipoSportivo;

public class GestioneSportivi {
    private int minReti;
    private ArrayList<Sportivo> archivioSportivi;
    private HashMap<Integer, ArrayList<Sportivo>> premiati;

    // Inizializzazione del costruttore
    public GestioneSportivi(int minReti) {
        this.minReti = minReti;
        this.archivioSportivi = new ArrayList<>();
        this.premiati = new HashMap<>();
    }

    public void addSportivo(Sportivo sportivo){
        archivioSportivi.add(sportivo);
    }
    
    public void addSportivo(String nome, String cognome, LocalDate dataAssunzione, int livelloStipendiale, TipoSportivo tipoSportivo){
        Sportivo s = new Sportivo(nome, cognome, dataAssunzione, livelloStipendiale, tipoSportivo);
        archivioSportivi.add(s);
    }
    
    public int getMinReti() {
        return minReti;
    }

    public void setMinReti(int minReti) {
        this.minReti = minReti;
    }

    public Sportivo getSportivo(String nome, String cognome){
        for (int i = 0; i < archivioSportivi.size(); i++) {
            Sportivo s = archivioSportivi.get(i);
            if(s.getNome().equals(nome) && s.getCognome().equals(cognome)){
                return s;    
            }
        }
        // Lo sportivo non esiste
        throw new NoSuchElementException("Lo sportivo non esiste!");
    }


        public ArrayList<Sportivo> getDoppioni(){
            ArrayList<Sportivo> doppioni = new ArrayList<>();
            for(Sportivo s1 : archivioSportivi){
                LocalDate data1 = s1.getDataAssunzione();
                TipoSportivo tipo1 = s1.getTipoSportivo();
                for(Sportivo s2 : archivioSportivi){
                    LocalDate data2 = s2.getDataAssunzione();
                    TipoSportivo tipo2 = s2.getTipoSportivo();
                    if(s1 != s2){                               // verifica che non sto controllando lo stesso elemento
                        if(data1.equals(data2) && tipo1.equals(tipo2)){   // verifica se sono uguali i parametri
                            if(!doppioni.contains(s1)){
                                doppioni.add(s1);
                            }
                            if(!doppioni.contains(s2)){
                                doppioni.add(s2);
                            }
                        }
                    }
                }

            }
            return doppioni;
        }


    public HashMap<Integer, ArrayList<Sportivo>> getPremiati(){
        int count;
        for(Sportivo sp : archivioSportivi){
            count = 0;
            if(sp.getLivelloStipendiale() >= 3 && sp.getTipoSportivo() == TipoSportivo.GIOCATORE){
                for(int reti : sp.getRetiSegnate().values()){
                    if(reti >= minReti){
                        count++;
                    }
                }
            }
            if(count > 0){
                ArrayList<Sportivo> p = premiati.getOrDefault(count, new ArrayList<>());
                p.add(sp);
                premiati.put(count, p);
            }
        }
        return premiati;
    }

    @Override
    public String toString() {
        return "GestioneSportivi [minReti=" + minReti + ", archivioSportivi=" + archivioSportivi + ", premiati="
                + premiati + "]";
    }
    
    
}
