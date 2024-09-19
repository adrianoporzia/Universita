package services;

import java.time.Month;
import java.util.ArrayList;
import java.util.HashMap;

import models.Sportivo;

public class GestioneSportivo {
    private ArrayList<Sportivo> listaSportivi;
    private HashMap<Integer, ArrayList<Sportivo>> listaPremiati;
    private int bonus;

    public GestioneSportivo(int bonus) {
        this.listaSportivi = new ArrayList<>();
        this.listaPremiati = new HashMap<>();
        this.bonus = bonus;
    }

    public ArrayList<Sportivo> getListaSportivi() {
        return listaSportivi;
    }

    
    public int getBonus() {
        return bonus;
    }

    public void setBonus(int bonus) {
        this.bonus = bonus;
    }

    public void addSportivo(Sportivo sportivo){
        if(sportivo == null){
            throw new IllegalArgumentException("Sportivo è null");
        }
        listaSportivi.add(sportivo);
    }

    public void getPremiatiPerBonus(int n){
        int mesiConNGoal;
        for(Sportivo sp : listaSportivi){
            mesiConNGoal = 0;
            if(sp.getLivelloStipendiale() >= 3){
                for(int i = 0; i < 12; i++){
                    if(sp.getGolPerMese(i) >= n){
                        mesiConNGoal++;
                    }
                }
                if(mesiConNGoal > 0){
                    ArrayList<Sportivo> appoggio = listaPremiati.getOrDefault(mesiConNGoal, new ArrayList<>());
                    appoggio.add(sp);
                    listaPremiati.put(mesiConNGoal, appoggio);
                }
            }
        }
        System.out.println(listaPremiati);
    }
    

    public void doppioniData(Month mese, int anno){
        ArrayList<Sportivo> doppioni = new ArrayList<>();
        for(Sportivo sp : listaSportivi){
            Month meseSp = sp.getDataDiAssunzione().getMonth();
            int annoSp = sp.getDataDiAssunzione().getYear();
            if(meseSp == mese && annoSp == anno){
                doppioni.add(sp);
            }
        }
        if(listaSportivi.size() < 2){
            System.out.println("Non ci sono sportivi nati nello stesso mese e anno!");
        }
        System.out.println("Almeno due sportivi sono doppioni!");
        System.out.println(doppioni);
    }

    public HashMap<Integer, ArrayList<Sportivo>> getListaPremiati() {
        return listaPremiati;
    }
}
