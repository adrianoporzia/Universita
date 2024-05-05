import java.util.ArrayList;
import java.util.Random;

public class Archivio {

    
    private ArrayList<Studente> immatricolati;
    public static int prossimaMatricola;
    public static final int MIN_CREDITI=30;

    public Archivio() {
        this.immatricolati = new ArrayList<>();
        prossimaMatricola = 0;
    }

    public ArrayList<Studente> getImmatricolati() {
        return immatricolati;
    }

    public void setImmatricolati(ArrayList<Studente> immatricolati) {
        this.immatricolati = immatricolati;
    }

    public static int getProssimaMatricola() {
        return prossimaMatricola;
    }

    public static void setProssimaMatricola(int prossimaMatricola) {
        Archivio.prossimaMatricola = prossimaMatricola;
    }

    public static int getMinCrediti() {
        return MIN_CREDITI;
    }

    public void nuovaIscrizione(String nomeStudente){
        if(nomeStudente != null){
            prossimaMatricola ++;
            immatricolati.add(new Studente(nomeStudente, prossimaMatricola));
        }
    }

    public int cercaIndiceStudente(String nomeStudente){
    int i=0;
    while (i<immatricolati.size()){
        Studente studente1= immatricolati.get(i);
        String nStudente= studente1.getNome();
        if (nStudente.equalsIgnoreCase(nomeStudente))
            return i;
            i++;
        }
    return -1;
    }

    public void ritirato(String nomeStudente){
        String nomeStudenteFinale = nomeStudente;
        int indiceStudente= cercaIndiceStudente(nomeStudenteFinale);
        if (indiceStudente==-1)
            return;
        else
            immatricolati.remove(indiceStudente);
    }

    public void appello(String nomeEsame, ArrayList<Studente> iscritti){
        Random generator = new Random ();
        int i = 0;
        while (i<iscritti.size()){
            int rVoto = 1 + generator.nextInt(30);
            if (rVoto>=18)
                iscritti.get(i).promosso(nomeEsame,rVoto);
            i++;
        }           
    }

    public void laurea(){
        int i = 0;
        while (i<immatricolati.size()){
            if (immatricolati.get(i).numCrediti() >= MIN_CREDITI)
                immatricolati.remove(i);
            i++;
            }
        }



    
}
