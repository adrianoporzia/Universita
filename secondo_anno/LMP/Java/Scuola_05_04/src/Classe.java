import java.util.ArrayList;

public class Classe {
    private int annoStudenti;
    private int annoInCorso;
    private String sezione;

    ArrayList<Studente> bocciati;
    ArrayList<Studente> classe;

    public Classe(int annoStudenti, int annoInCorso, String sezione) {
        this.annoStudenti = annoStudenti;
        this.annoInCorso = annoInCorso;
        this.sezione = sezione;
        this.bocciati = new ArrayList<>();
        this.classe = new ArrayList<>();
    }

    public String getNome() {
        return Integer.toString(this.annoInCorso) + this.sezione;
    }

    public int getAnnoStudenti() {
        return annoStudenti;
    }

    public void setAnnoStudenti(int annoStudenti) {
        this.annoStudenti = annoStudenti;
    }

    public int getAnnoInCorso() {
        return annoInCorso;
    }

    public void setAnnoInCorso(int annoInCorso) {
        this.annoInCorso = annoInCorso;
    }

    public String getSezione() {
        return sezione;
    }

    public void setSezione(String sezione) {
        this.sezione = sezione;
    }
    public int getStudents(){
        return this.classe.size();
    }
}
