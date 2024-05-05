import java.util.ArrayList;

public class Studente {
    private String nome;
    private int matricola;
    private ArrayList<Esame> esamiSostenuti;
    private ArrayList<Esame> pianoStudio;
    public Studente(String nome, int matricola) {
        this.nome = nome;
        this.matricola = matricola;
        this.esamiSostenuti = new ArrayList<Esame>();
        this.pianoStudio = new ArrayList<Esame>();
    }
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public int getMatricola() {
        return matricola;
    }
    public void setMatricola(int matricola) {
        this.matricola = matricola;
    }
    public ArrayList<Esame> getEsamiSostenuti() {
        return esamiSostenuti;
    }
    public void setEsamiSostenuti(ArrayList<Esame> esamiSostenuti) {
        this.esamiSostenuti = esamiSostenuti;
    }
    public ArrayList<Esame> getPianoStudio() {
        return pianoStudio;
    }
    public void setPianoStudio(ArrayList<Esame> pianoStudio) {
        this.pianoStudio = pianoStudio;
    }
    @Override
    public String toString() {
        return "Studente [nome=" + nome + ", matricola=" + matricola + ", esamiSostenuti=" + esamiSostenuti
                + ", pianoStudio=" + pianoStudio + "]";
    }

    public void aggiungiEsame(String nomeEsame, int numCrediti){
        Esame esame = new Esame(nomeEsame, numCrediti, 0);
        pianoStudio.add(esame);
    }

    public int cercaIndiceEsamePiano(String nomeEsame){
        int n = pianoStudio.size();
        for(int i = 0; i < n; i++){
            if(pianoStudio.get(i).getNome() == nomeEsame){
                return i;
            }
        }
        return -1;
    }

    public int cercaIndiceEsameSostenuto(String nomeEsame){
        int n = esamiSostenuti.size();
        for(int i = 0; i < n; i++){
            if(esamiSostenuti.get(i).getNome() == nomeEsame){
                return i;
            }
        }
        return -1;
    }

    public void cancella(String nomeEsame){
        for(Esame es : pianoStudio){
            if(es.getNome() == nomeEsame){
                pianoStudio.remove(es);
            }
        }
        return;
    }

    public void promosso(String nomeEsame, int voto){
        if(voto < 18){
            return;
        int i = 0;
        int n = pianoStudio.size();
        while(i < n){
            if(pianoStudio.get(i).getNome() == nomeEsame){
                int crediti = pianoStudio.get(i).getCrediti();
                Esame esame = new Esame(nomeEsame, crediti, voto)
                esamiSostenuti.add(esame);
                cancella(nomeEsame);
                break;
                }
            i++;
            }
        return;
        }
    }

    public double mediaVoti(){
        int somma = 0;
        for(Esame es: esamiSostenuti){
            somma += es.getVoto();
        }
        return somma / esamiSostenuti.size();
    }

    public int numCrediti(){
        int somma = 0;
        for(Esame es : esamiSostenuti){
            somma += es.getCrediti();
        }
        return somma;
    }
    
}
