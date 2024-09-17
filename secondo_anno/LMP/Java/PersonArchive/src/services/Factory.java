package services;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.NoSuchElementException;

import models.Disoccupato;
import models.Impiegato;
import models.LiberoProfessionista;
import models.Person;

public class Factory {

    private HashMap<String, Person> archivioPerson;

    public Factory() {
        this.archivioPerson = new HashMap<>();
    }


    public void createPerson(Person person){
        String codiceFiscale = person.getCodiceFiscale();
        archivioPerson.put(codiceFiscale, person);

    }
    
    public void createPerson(String nome, String cognome, LocalDate dataDiNascita, String codiceFiscale, int livello, String Mansione){
        Impiegato impiegato = new Impiegato(nome, cognome, dataDiNascita, codiceFiscale, livello, Mansione);
        archivioPerson.put(codiceFiscale, impiegato);
    }


    public void createPerson(String nome, String cognome, LocalDate dataDiNascita, String codiceFiscale, String professione, int numPartitaIva){
        LiberoProfessionista libProfessionista= new LiberoProfessionista(nome, cognome, dataDiNascita, codiceFiscale, professione, numPartitaIva);
        archivioPerson.put(codiceFiscale, libProfessionista);
    }

    public void createPerson(String nome, String cognome, LocalDate dataDiNascita, String codiceFiscale, String iscrizioneRegistroDisoccupazione){
        Disoccupato disoccupato = new Disoccupato(nome, cognome, dataDiNascita, codiceFiscale, iscrizioneRegistroDisoccupazione);
        archivioPerson.put(codiceFiscale, disoccupato       );

    }

    public Person getPerson(String codiceFiscale){
        Person p = archivioPerson.get(codiceFiscale);
        if(codiceFiscale == null){
            throw new NoSuchElementException("Non esiste persona!");
        }
        return p;


    }


    @Override
    public String toString() {
        return "Factory [archivioPerson=" + archivioPerson + "]";
    }

    
    
}
