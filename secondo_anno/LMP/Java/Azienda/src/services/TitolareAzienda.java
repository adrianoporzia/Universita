package services;

import java.time.Month;
import java.util.ArrayList;

import models.Dipartimento;
import models.Dipendente;
import models.Mansione;

public class TitolareAzienda {
    private ArrayList<Dipendente> listaDipendenti;

    public TitolareAzienda() {
        this.listaDipendenti = new ArrayList<>();
    }

    public ArrayList<Dipendente> getListaDipendenti() {
        return listaDipendenti;
    }
    

    public void addDipendente(Dipendente dip){
        if(dip == null){
            throw new IllegalArgumentException("Dipendente non valido!");
        }
        listaDipendenti.add(dip);
    }

    public void getChainOfCommand(Dipendente dip){
        if(dip.getCapoDiretto() == null){
            throw new IllegalArgumentException("Il dipendente " + dip.getMatricola() + " è il capo della catena!");
        }
        ArrayList<Dipendente> chainOfCommand = new ArrayList<>();
        chainOfCommand.add(dip);
        while(dip.getCapoDiretto() != null){
            chainOfCommand.add(dip.getCapoDiretto());
            dip = dip.getCapoDiretto();
        } 
        System.out.println(chainOfCommand);
        return;
    }

    public Dipendente getSostituto(Dipendente dip){
        ArrayList<Dipendente> listaStessoCapo = new ArrayList<>();
        Dipendente capo = dip.getCapoDiretto();
        Mansione mansioneCercata = dip.getMansione();
        for(Dipendente d : listaDipendenti){
            if(d.getCapoDiretto() == capo){
                listaStessoCapo.add(d);
            }
        }
        if(listaStessoCapo.size() > 0){
            for(Dipendente d : listaStessoCapo){
                if(d.getMansione() == mansioneCercata){
                    System.out.println(d);
                    return d;
                }
            }
        }
        System.out.println("Il dipendente " + dip.getMatricola() + " non ha sostituti!");
        return null;
    }

    public void getDoppioni(Month mese, int anno, Dipartimento dipartimento){
        ArrayList<Dipendente> listaDoppioni = new ArrayList<>();
        for(Dipendente d : listaDipendenti){
            if(d.getDataDiNascita().getMonth() == mese && d.getDataDiNascita().getYear() == anno && d.getDipartimento() == dipartimento){
                listaDoppioni.add(d);
               }
        }
        if(listaDoppioni.size() == 0){
            System.out.println("Non ci sono doppioni con parametri in input");
            return;
        }
        System.out.println(listaDoppioni);
        return;
    }
    
}
