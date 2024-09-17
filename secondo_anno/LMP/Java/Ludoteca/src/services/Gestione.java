package services;

import java.sql.Time;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.NoSuchElementException;

import models.Prodotto;
import models.Prestito;

public class Gestione {
    private HashMap<Prodotto, Integer> prodottiDisponibili;
    private ArrayList<Prestito> prestitiTotali;

    public Gestione() {
        this.prodottiDisponibili = new HashMap<>();
        this.prestitiTotali = new ArrayList<>();

    }

    public void addProdotto(Prodotto prodotto){
        if(prodotto == null){
            throw new IllegalArgumentException("Prodotto null");
        }
        if(prodottiDisponibili.containsKey(prodotto)){
            int disponibilitaVecchia = prodottiDisponibili.get(prodotto);
            prodottiDisponibili.put(prodotto, disponibilitaVecchia + 1);
        }
        else{
            prodottiDisponibili.put(prodotto, 1);
        }
    }
    
    public int checkDisponibilita(Prodotto prodotto){
        if(!prodottiDisponibili.containsKey(prodotto)){
            throw new NoSuchElementException("Non ci sono copie");
        }
        return prodottiDisponibili.get(prodotto);
    }

    public void inizioPrestito(Prodotto prodottoPrestato, Time oraInizioPrestito, String nomePersona, Time oraFinePrestito){
        Prestito newPrestito = new Prestito(prodottoPrestato, oraInizioPrestito, nomePersona, oraFinePrestito);
        if(checkDisponibilita(newPrestito.getProdottoPrestato()) > 0){
            int d = prodottiDisponibili.get(newPrestito.getProdottoPrestato());
            prodottiDisponibili.put(newPrestito.getProdottoPrestato(), d - 1);
        }
    }

    public LocalTime stimaAttesa(){
        
    }

}

