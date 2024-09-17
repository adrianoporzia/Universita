package services;

import java.util.ArrayList;

import models.Prodotto;

public class Fabrica {
    private ArrayList<Prodotto> catenaProduzione;

    public Fabrica() {
        this.catenaProduzione = new ArrayList<>();
    }

    public void addProdotti(Prodotto prodotto){
        if(prodotto == null){
            throw new IllegalArgumentException("Prodotto non valido");
        }
        catenaProduzione.add(prodotto);
    }

    public void getRankingGuadagno(){
        ArrayList<Double> ranking = new ArrayList<>();
        for(int i = 0; i < catenaProduzione.size(); i++){
            double guadagnoTempo = (catenaProduzione.get(i).getPrezzoPerAcquirenti()) / 
                                   (catenaProduzione.get(i).getTempoProduzioneProdotto() + 
                                    catenaProduzione.get(i).getTempoStimatoOrdineComponenti());
            ranking.add(guadagnoTempo);
        }
        ranking.sort(null);
    }


    public void presentazionePerDipendenti(){
        for(Prodotto p : catenaProduzione){
            System.out.println(p);
        }
    }
    
}
