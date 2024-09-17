package services;

import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.NoSuchElementException;

import models.Prestito;
import models.Supporto;

public class GestioneBiblioteca {
    private ArrayList<Prestito> prestitiAttivi;

    public GestioneBiblioteca() {
        this.prestitiAttivi = new ArrayList<>();

    }


    public void addPrestito(Prestito prestito, Supporto supporto){
        prestitiAttivi.add(prestito);
        supporto.getPrestitiSupporto().add(prestito);

    }

    public void modificaDataConsegna(Prestito prestito, Supporto supporto, LocalDate data){
        if(!supporto.getPrestitiSupporto().contains(prestito)){
            throw new NoSuchElementException("Il prestito non esiste!");
        }
        for(Prestito p : supporto.getPrestitiSupporto()){
            if(p == prestito){
                p.setDataPrevistaConsegna(data);
            }
        }
    }
    
    public long maxDurataPrestito() {
        long maxDurata = 0; // Inizializziamo con 0 giorni
        for (Prestito p : prestitiAttivi) {
            long durata = ChronoUnit.DAYS.between(p.getDataInizioPrestito(), p.getDataEffettivaConsegna());
            if (durata > maxDurata) {
                maxDurata = durata;
            }
        }
        return maxDurata; // Restituiamo la durata massima in giorni
    }


    public void verificaInconsistenze(Supporto supporto){
        ArrayList<Prestito> inconsistenzePrestiti = new ArrayList<>();
        if(supporto.getPrestitiSupporto().size() <= 1){
            throw new IllegalArgumentException("Non ci sono inconsistenze");
        }
        LocalDate dataDaVerificare = supporto.getPrestitiSupporto().get(0).getDataEffettivaConsegna();
        for(int i = 1; i <= supporto.getPrestitiSupporto().size(); i++){
            if(!dataDaVerificare.isAfter(supporto.getPrestitiSupporto().get(i).getDataInizioPrestito())){
                inconsistenzePrestiti.add(supporto.getPrestitiSupporto().get(i));
            }

        }


    }

}
