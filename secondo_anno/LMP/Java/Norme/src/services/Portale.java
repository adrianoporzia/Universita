package services;

import java.util.ArrayList;
import java.util.HashMap;

import models.Legge;
import models.TipoLegge;

public class Portale {
    private HashMap<String, Legge> leggi;

    public Portale() {
        this.leggi = new HashMap<>();
    }


    public void addLeggi(Legge legge){
        if(legge == null){
            throw new IllegalArgumentException("La legge è vuota");
        }
        String identificatore = legge.getIdentita();
        leggi.put(identificatore, legge);
    }


    public void searchLegge(TipoLegge tipo, int anno){
        ArrayList<Legge> wanted = new ArrayList<>();
        for(Legge l : leggi.values()){
            if(l.getTipoLegge() == tipo && l.getDataLegge().getYear() == anno){
                wanted.add(l);
            }
        }
        for(Legge l : wanted){
            System.out.println(l);
        }
    }


    public void ventiArticoli(){
        ArrayList<Legge> wanted = new ArrayList<>();
        for(Legge l : leggi.values()){
            if(l.getArticoliLegge().size() >= 20){
                wanted.add(l);
            }
        }
        System.out.println(wanted);
    }

    
}



    



