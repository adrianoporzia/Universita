package services;

import java.time.LocalDate;
import java.time.Month;
import java.time.Year;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.NoSuchElementException;

import models.Dipendente;
import models.Dipendente.Dipartimento;
import models.Mansione;

public class GestioneAzienda {
    private HashMap<Integer, ArrayList<Dipendente>> chainOfCommand;
    private ArrayList<Dipendente> dipendentiAzienda;

    public GestioneAzienda() {
        this.chainOfCommand = new HashMap<>();
        this.dipendentiAzienda = new ArrayList<>();

    }


    public void nuovoDipendente(Dipendente dip){
        int lvl = dip.getLivello();
        dipendentiAzienda.add(dip);
        if (chainOfCommand.get(lvl).size() == 0){
            ArrayList<Dipendente> newDip = new ArrayList<>();
            newDip.add(dip);
            chainOfCommand.put(lvl, newDip);
        }
        else{
            chainOfCommand.get(lvl).add(dip);
        }
    }

    public void nuovoDipendenteInCatena(String nome, String cognome, LocalDate dataDiNascita, LocalDate dataDiAssunzione,
            Dipartimento dipartimentoDipendente, Mansione mansioneDipendente, int livello){
        Dipendente dip = new Dipendente(nome, cognome, dataDiNascita, dataDiAssunzione, dipartimentoDipendente, mansioneDipendente, livello);
        dipendentiAzienda.add(dip);
        int lvl = dip.getLivello();
        if (chainOfCommand.get(lvl).size() == 0){
            ArrayList<Dipendente> newDip = new ArrayList<>();
            newDip.add(dip);
            chainOfCommand.put(lvl, newDip);
        }
        else{
            chainOfCommand.get(lvl).add(dip);
        }
    }

    public ArrayList<Dipendente> getCapoDiretto(Dipendente dip) {
        int lvl = dip.getLivello();
        // Cerca i capi a un livello superiore
        for (int livelloSuperiore = lvl + 1; livelloSuperiore <= 8; livelloSuperiore++) {
            if (chainOfCommand.containsKey(livelloSuperiore)) {
                ArrayList<Dipendente> capi = chainOfCommand.get(livelloSuperiore);
                if (!capi.isEmpty()) {
                    return capi; 
                }
            }
        }
        // Se non trovi nessun capo, restituisci una lista vuota
        throw new NoSuchElementException("Non ce capo diretto!");
    }


    public ArrayList<Dipendente> getSostituto(Dipendente dip){
        int lvl = dip.getLivello();
        Mansione mansioneDaSostituire = dip.getMansioneDipendente();
        if(chainOfCommand.get(lvl).size() <= 1){        //L'unico dipendente con quel livello
            throw new NoSuchElementException("Dipendente Insostituibile!");
        }
        ArrayList<Dipendente> sostituti = new ArrayList<>();
        for(Dipendente d : chainOfCommand.get(lvl)){
            if(d.getMansioneDipendente() == mansioneDaSostituire){
                sostituti.add(d);
            }
        }
        if(sostituti.size() == 0){
            throw new NoSuchElementException("Non ci sono sostituti con stessa mansione e livello");
        } 
        else{
            return sostituti;
        }
    }


    public void cercaDipendente(Month mese, int anno, Dipartimento dipartimento){
        ArrayList<Dipendente> dipendentiCercati = new ArrayList<>();
        for(Dipendente d : dipendentiAzienda){
            if(d.getDipartimentoDipendente() == dipartimento && d.getDataDiNascita().getYear() == anno && d.getDataDiNascita().getMonth() == mese){
                dipendentiCercati.add(d);
               }
        }
        if(dipendentiCercati.size() == 0){
            throw new NoSuchElementException("Non ci sono dipendenti che rispettano i parametri!");
        }
        System.out.println(dipendentiCercati);
    }  

    



    
    
}
