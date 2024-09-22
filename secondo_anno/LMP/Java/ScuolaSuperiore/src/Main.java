import java.time.LocalDate;

import models.Classe;
import models.Studente;
import services.GestionePreside;

public class Main{
    public static void main(String[] args){

        GestionePreside gp = new GestionePreside();
        Studente adriano = new Studente(LocalDate.of(2003, 11, 23), "Roma", "Adriano", "Porzia", 5);
        Studente ionut = new Studente(LocalDate.of(2003, 10, 7), "Bucarest", "Ionut", "Zbirciog", 5);
        Studente francesco = new Studente(LocalDate.of(2001, 1, 10), "Roma", "Francesco", "Cosciotti", 5);
        Studente domenico = new Studente(LocalDate.of(2003, 7, 6), "Frascati", "Domenico", "Sabatini", 4);

        Classe classe1 = new Classe("A", 5, 2003);
        Classe classe2 = new Classe("B", 4, 2004);

        classe1.addStudenteClasse(adriano);
        classe1.addStudenteClasse(ionut);
        classe1.addStudenteClasse(francesco);

        classe2.addStudenteClasse(domenico);

        gp.addClasse(classe1);
        gp.addClasse(classe2);

        System.out.println("Bocciati della classe " + classe1.getNomeClasse() + ":");
        gp.getBocciatoPerClasse(classe1);
        System.out.println("Bocciati della classe " + classe2.getNomeClasse() + ":");
        gp.getBocciatoPerClasse(classe2);
        
        System.out.println("-------------------------------------------");
        System.out.println("Le classi sono:");
        System.out.println(gp);


    }
    
}
